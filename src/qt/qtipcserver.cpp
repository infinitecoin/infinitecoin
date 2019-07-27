// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#include "qtipcserver.h"
#include "guiconstants.h"
#include "ui_interface.h"
#include "util.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/version.hpp>

#if defined(WIN32) && (!defined(BOOST_INTERPROCESS_HAS_WINDOWS_KERNEL_BOOTTIME) || !defined(BOOST_INTERPROCESS_HAS_KERNEL_BOOTTIME) || BOOST_VERSION < 104900)
#warning Compiling without BOOST_INTERPROCESS_HAS_WINDOWS_KERNEL_BOOTTIME and BOOST_INTERPROCESS_HAS_KERNEL_BOOTTIME uncommented in boost/interprocess/detail/tmp_dir_helpers.hpp or using a boost version before 1.49 may have unintended results see svn.boost.org/trac/boost/ticket/5392
#endif

using namespace boost;
using namespace boost::interprocess;
using namespace boost::posix_time;

static void ipcThread2(void* pArg);

#ifdef MAC_OSX
// URI handling not implemented on OSX yet

void ipcInit() { }

#else

static void ipcThread(void* pArg)
{
    IMPLEMENT_RANDOMIZE_STACK(ipcThread(pArg));
	
    // Make this thread recognisable as the GUI-IPC thread
    RenameThread("bitcoin-gui-ipc");
	
    try
    {
        ipcThread2(pArg);
    }
    catch (std::exception& e) {
        PrintExceptionContinue(&e, "ipcThread()");
    } catch (...) {
        PrintExceptionContinue(NULL, "ipcThread()");
    }
    printf("ipcThread exited\n");
}

static void ipcThread2(void* pArg)
{
    printf("ipcThread started\n");

    message_queue* mq = (message_queue*)pArg;
    char buffer[MAX_URI_LENGTH + 1] = "";
    size_t nSize = 0;
    unsigned int nPriority = 0;

    while(1)
    {
        ptime d = boost::posix_time::microsec_clock::universal_time() + millisec(100);
        if (mq->timed_receive(&buffer, sizeof(buffer), nSize, nPriority, d))
        {
            uiInterface.ThreadSafeHandleURI(std::string(buffer, nSize));
            Sleep(1000);
        }

        if (fShutdown)
            break;
    }

    // Remove message queue
    message_queue::remove(BITCOINURI_QUEUE_NAME);
    // Cleanup allocated memory
    delete mq;
}

void ipcInit()
{
    message_queue* mq = NULL;
    char buffer[MAX_URI_LENGTH + 1] = "";
    size_t nSize = 0;
    unsigned int nPriority = 0;

    try {
        mq = new message_queue(open_or_create, BITCOINURI_QUEUE_NAME, 2, MAX_URI_LENGTH);

        // Make sure we don't lose any infinitecoin: URIs
        for (int i = 0; i < 2; i++)
        {
            ptime d = boost::posix_time::microsec_clock::universal_time() + millisec(1);
            if (mq->timed_receive(&buffer, sizeof(buffer), nSize, nPriority, d))
            {
                uiInterface.ThreadSafeHandleURI(std::string(buffer, nSize));
            }
            else
                break;
        }

        // Make sure only one infinitecoin instance is listening
        message_queue::remove(BITCOINURI_QUEUE_NAME);
        delete mq;

        mq = new message_queue(open_or_create, BITCOINURI_QUEUE_NAME, 2, MAX_URI_LENGTH);
    }
    catch (interprocess_exception &ex) {
        printf("ipcInit() - boost interprocess exception #%d: %s\n", ex.get_error_code(), ex.what());
        return;
    }

    if (!CreateThread(ipcThread, mq))
    {
        delete mq;
        return;
    }
}

#endif
