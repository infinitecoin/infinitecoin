// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Infinitecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     1, uint256("0x5034bab74771e5910f3f366c614c457e166b0f6cfcbc5ea8022da08f8cad734c"))
            (    99, uint256("0x5d39f8648c612d6e01b953fcfc6e7c31a58f086ae4715ae3e5e828cd148052a9"))
            (   999, uint256("0x18045133dedbed71aa49aaf1696b65818ca21b20263cd53cc9bd935c1c8be6ee"))
            (  9999, uint256("0xd2f1a2f1b8862af96c5a750f3d99680ee96e7a4aac4e27f0587b1dbaa9b9207f"))
            ( 49999, uint256("0xef2a0653071708d6a41dff2bb671bb459879f2c361a06024fca17a2566b41225"))
            ( 99979, uint256("0xf376177d849c75c6344fc93c9429f59df7d5b25b067447e694e087bb765128e0"))
            (139999, uint256("0xff9d5edf1661d8cd6fc53ffb9f583b16981874522044a760d8c8c004c312a41e"))
            (199999, uint256("0xec62c7700fd83c56f2013b1b97a7dbcc2aad1f065176ea18d9c47701ced164d5"))
            (228800, uint256("0x6a2a329c5d21d6433cf9bda5ba43d66a732898bcd0c81150f1584d095edd5cd5"))
            (242388, uint256("0x4c2dfd22435525519e89041420f6692e709da34f48243cebe1be14d43adb1c5c"))
            (265420, uint256("0x9ef4ce8e7dab5c2f2b9142ceb285419ef0ea62021e5f613d4a81a3fc9d53453e"))
			(265497, uint256("0x206aed8fb5b1ed94cf696bc5b964445380dd4c30c186e45ba5ed545866a242c7")) // keep
            (268559, uint256("0xfd0ff0e0020f0ade68122c0fd82f648c7e6913e32cd6a3d8abc81694055daecc")) // keep
			(268560, uint256("0x08c5337322ea40d3602b98ab9d9b1d43abd87dda19a4f8e282414a838ae3dbb8"))
            (282045, uint256("0x271abe1c26daf5a684034529befb217e16f87e1af779c0e63bdd971def3d8ba5"))
			(380962, uint256("0xa032a87b430091fbb4faa20f16c8247f93cfcc1854bd49a19c3c9fc3a0c43634"))
			(453211, uint256("0xea08eace1b78c5513d74750c7cfc01d0c1f3789fc650ccce197b85497405ce56"))
            (647000, uint256("0x667fc19d6066d472176136f2a34dac9b2662e9d7212df3679e56042d8b198906"))
            (4333333, uint256("0x8e4fcf3e003293882dec8943e42ed29e066cfc3782ff4d011c58c8b8ed9bb9a4"))
            (4368037, uint256("0xb60d656dcc3fdd60b279a7de7ad8c21950c4cbae58698219785249e0174d4bcd"))
            (4468037, uint256("0xf041001d5548e3cc91ff16a409dc47eebf5d684afa12572e5259e0d457593fb6"))
            (5000000, uint256("0x71b50efbeeed2172d6076b3798b2fe6b9e28346600bac2c37dad34b704992d78"))
            (5299999, uint256("0x2b16f5c210d5374aeb74c95479a6a32b706fc80979285bd5a69b5eae24403d64"))
            (5399999, uint256("0xcf22db1f6264fcb49c6c126ae1a07174084e780af39dae938dffece03fd409f7"))
            (5499999, uint256("0x57cfae1035a7bd1828921663fc4ea71b9251aa9fcc5048b252075273ac1da612"))
            (5529599, uint256("0x981fceee5af344d4e01664e2bb2fe7aafd5536b233be087824a5ccea8670b726"))//fork
            (5529600, uint256("0x8682584ab5620c01ec8a323ac9bfbb6b1c5a4bf49af006470782b347e761c2ca"))
            (5559999, uint256("0x29f34fc1ccba3023f8cd8ea820bc5b40514a2756b9afbe7505597b8e8fbe42ec"))
            (5566666, uint256("0x1d35801d806f2e26f99506303cd969cfb052f55ad48bbb75a06e7769c9473d93"))
            (5569999, uint256("0x23e346da920a92b74876b7aa50234930966e88ec5b4bed3944d84cff9930f4dd"))
			;
			
		

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    uint256 GetLatestHardenedCheckpoint()
    {
        const MapCheckpoints& checkpoints = mapCheckpoints;
        return (checkpoints.rbegin()->second);
    }
}
