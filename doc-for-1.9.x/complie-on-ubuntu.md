支持 ubuntu 1404 32&64
---
```
sudo apt-get update
sudo apt-get upgrade

//libminiupnpc-dev ifc编译可以不安装
sudo apt-get install libminiupnpc-dev

//增加软件源安装db4.8
apt-get install -y python-software-properties software-properties-common 
add-apt-repository ppa:bitcoin/bitcoin
apt-get update && apt-get install -y libdb4.8-dev libdb4.8++-dev


//安装基本环境
apt-get install -y make gcc g++ git libssl-dev build-essential libtool autotools-dev autoconf pkg-config libevent-dev libboost-all-dev libqt4-dev qt4-qmake libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libqrencode-dev libpng-dev

apt-get install -y libfontconfig1-dev libfreetype6-dev libx11-dev libxcursor-dev libxext-dev libxfixes-dev libxft-dev libxi-dev libxrandr-dev libxrender-dev

//不需要，编译安装 db4.8 如果以上代码正确，则不需要执行编译安装
apt-get install unzip && wget http://download.oracle.com/berkeley-db/db-4.8.30.zip && unzip db-4.8.30.zip && cd db-4.8.30 && cd build_unix/ && ../dist/configure --prefix=/usr/local --enable-cxx && make && make install

//不需要，安装openssl 1.0.1g
wget https://www.openssl.org/source/openssl-1.0.1t.tar.gz && tar zvxf openssl-1.0.1t.tar.gz && cd openssl-1.0.1t &&  ./config shared zlib && make && make install

//安装qrcode
wget 'http://fukuchi.org/works/qrencode/qrencode-3.2.0.tar.bz2' --no-check-certificate && tar xjf qrencode-3.2.0.tar.bz2 && cd qrencode-3.2.0 && ./configure --enable-static --disable-shared && make install

//静态编译qt
wget http://download.qt.io/archive/qt/4.8/4.8.6/qt-everywhere-opensource-src-4.8.6.tar.gz && gunzip qt-everywhere-opensource-src-4.8.6.tar.gz && tar xvf qt-everywhere-opensource-src-4.8.6.tar && cd qt-everywhere-opensource-src-4.8.6 && ./configure -static -nomake demos -nomake examples -nomake tools -no-exceptions && make && make install

//设置环境变量
PATH=/usr/local/Trolltech/Qt-4.8.6/bin:$PATH
export PATH

//32位
mkdir /usr/lib/i386-linux-gnu/qt4/bin
rm /usr/lib/i386-linux-gnu/qt4/bin/qmake
ln -s /usr/local/Trolltech/Qt-4.8.6/bin/qmake /usr/lib/i386-linux-gnu/qt4/bin/qmake

//64位
mkdir /usr/lib/x86_64-linux-gnu/qt4/bin
rm  /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
ln -s /usr/local/Trolltech/Qt-4.8.6/bin/qmake /usr/lib/x86_64-linux-gnu/qt4/bin/qmake

//下载源码
cd /home && mkdir ifc && cd ifc && git clone https://github.com/withu2018/infinitecoin.git

//执行静态编译 infinitecoin-qt
cd infinitecoin && qmake bitcoin-qt-linux.pro RELEASE=1 USE_UPNP=0 USE_QRCODE=1 USE_IPV6=0 && make -f Makefile && strip infinitecoin-qt

//静态编译 infinitecoind
cd src/ && make -f makefile.unix STATIC=1 USE_UPNP=- USE_IPV6=0 && strip infinitecoind

```
