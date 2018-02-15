// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// Thanks and Credits for Technologies found in BeepMagnet: Bitcoin, Novacoin, Blackcoin, Bitmessage, Shadowcoin, Cryptonote
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

//#include "chainparamsseeds.h"

unsigned int pnSeed[] =
{
    0xaa9e97c0,
    0x58a5c445,
};


int64_t CChainParams::GetProofOfWorkReward(int nHeight, int64_t nFees) const
{
    // miner's coin base reward
    int64_t nSubsidy = 0;
    
    if (nHeight <= 0)
        nSubsidy = 0;
    else
    if (nHeight <= nDistributionFund)
        nSubsidy = 10000000 * COIN;
	else
    if (nHeight <= nLastFairLaunchBlock)
        nSubsidy = 5 * COIN;
    else
    if (nHeight <= nLastPOWBlock)
        nSubsidy = 7.22 * COIN;
    
    if (fDebug && GetBoolArg("-printcreation"))
        LogPrintf("GetProofOfWorkReward() : create=%s nSubsidy=%d\n", FormatMoney(nSubsidy).c_str(), nSubsidy);
    
    return nSubsidy + nFees;
};


int64_t CChainParams::GetProofOfStakeReward(int64_t nCoinAge, int64_t nFees) const
{
    // miner's coin stake reward based on coin age spent (coin-days)
    int64_t nSubsidy = nCoinAge * 7.77 * 33 / (365 * 33 + 8);

    if (fDebug && GetBoolArg("-printcreation"))
        LogPrintf("GetProofOfStakeReward(): create=%s nCoinAge=%d\n nFees=%d\n", FormatMoney(nSubsidy).c_str(), nCoinAge, nFees);

    if (pindexBest->nHeight <= (105120 * 1))
        nSubsidy = nCoinAge * 7.13 * 33 / (365 * 33 + 8);
    else
    if (pindexBest->nHeight <= (105120 * 2))
        nSubsidy = nCoinAge * 7.16 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 3))
        nSubsidy = nCoinAge * 7.11 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 4))
        nSubsidy = nCoinAge * 6.99 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 5))
        nSubsidy = nCoinAge * 6.79 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 6))
        nSubsidy = nCoinAge * 6.52 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 7))
        nSubsidy = nCoinAge * 6.16 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 8))
        nSubsidy = nCoinAge * 5.72 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 9))
        nSubsidy = nCoinAge * 5.21 * 33 / (365 * 33 + 8);
    else	
    if (pindexBest->nHeight <= (105120 * 10))
        nSubsidy = nCoinAge * 4.62 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 11))
        nSubsidy = nCoinAge * 3.96 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 12))
        nSubsidy = nCoinAge * 3.25 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 13))
        nSubsidy = nCoinAge * 2.90 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 14))
        nSubsidy = nCoinAge * 2.53 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 15))
        nSubsidy = nCoinAge * 2.14 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 16))
        nSubsidy = nCoinAge * 1.73 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 17))
        nSubsidy = nCoinAge * 1.58 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 18))
        nSubsidy = nCoinAge * 1.41 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 19))
        nSubsidy = nCoinAge * 1.25 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 20))
        nSubsidy = nCoinAge * 1.08 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 21))
        nSubsidy = nCoinAge * 0.90 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 22))
        nSubsidy = nCoinAge * 0.73 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 23))
        nSubsidy = nCoinAge * 0.55 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 24))
        nSubsidy = nCoinAge * 0.37 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight <= (105120 * 25))
        nSubsidy = nCoinAge * 0.18 * 33 / (365 * 33 + 8);
    else    
    if (pindexBest->nHeight >= (105120 * 25))
        nSubsidy = 1;

    if (fDebug && GetBoolArg("-printcreation"))
        LogPrintf("GetProofOfStakeReward(): create=%s nCoinAge=%d\n", FormatMoney(nSubsidy).c_str(), nCoinAge);

    // Up until block 50k limited POS rewards while calculations are verified.  Limited rewards are equal to 1 sat per 0.01 coin.
    if (pindexBest->nHeight >= 60000)
        nSubsidy = nSubsidy * COIN;

    return nSubsidy + nFees;
}

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

// Convert the pnSeeds6 array into usable address objects.
static void convertSeeds(std::vector<CAddress> &vSeedsOut, unsigned int *data, unsigned int count, int port)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in_addr ip;
        memcpy(&ip, &pnSeed[i], sizeof(ip));
        CAddress addr(CService(ip, Params().GetDefaultPort()));
        addr.nTime = GetTime()-GetRand(nOneWeek)-nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x69;
        pchMessageStart[1] = 0xf0;
        pchMessageStart[2] = 0x0f;
        pchMessageStart[3] = 0x69;
        
        vAlertPubKey = ParseHex("0482299e1ba91b8d726160247ff58cf8aa8030054e778c496a1271d190414d1e5babeb9fbb2ec594cbde7d299cb2d529f9dcee06d180315eec72c532b40dff1e5f");
        
        nDefaultPort = 10340;
        nRPCPort = 10430;
        
        nFirstPosv2Block = 50000;
        
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20); // "standard" scrypt target limit for proof of work, results with 0,000244140625 proof-of-work difficulty
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);
        bnProofOfStakeLimitV2 = CBigNum(~uint256(0) >> 48);
        
        const char* pszTimestamp = "The Mercury, May 04 2017: Ready for the fourth industrial revolution?";
        CTransaction txNew;
        txNew.nTime = GENESIS_BLOCK_TIME;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CBigNum(42) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = GENESIS_BLOCK_TIME;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 1431440;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x00000bc30830c3ab3ea4f5b24bdd7612ac7f6bde627418ccb382e44e5578bee8"));
        assert(genesis.hashMerkleRoot == uint256("0x97d9f1778a9e22581e60a04456ab9473ca520ccbe9bc03f62ea1b5fadd152932"));
        
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("beepmagnetcoin.com", "dnsseed.beepmagnetcoin.com"));
        
        base58Prefixes[PUBKEY_ADDRESS] = list_of(25)                    .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[SCRIPT_ADDRESS] = list_of(52)                    .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[SECRET_KEY]     = list_of(199)                   .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x03)(0xCC)(0x23)(0xD7).convert_to_container<std::vector<unsigned char> >();  // need to change, to  okub
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x03)(0xCC)(0x1C)(0x73).convert_to_container<std::vector<unsigned char> >();  // need to change to okpv
        
        // TODO: There has yet to become a valid list of peers, come back to this once established.
        // convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        // convertSeeds(vFixedSeeds, pnSeed, ARRAYLEN(pnSeed), nDefaultPort);
        
        // 1 Year aprox = 105120 blocks 
        
        nLastPOWBlock = 33186;
        nLastFairLaunchBlock = 30;
        nDistributionFund = 1;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const std::vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    std::vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;

//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x00;
        pchMessageStart[1] = 0x09;
        pchMessageStart[2] = 0x7a;
        pchMessageStart[3] = 0x0f;
        
        nFirstPosv2Block = 50000;
        
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);
        bnProofOfStakeLimitV2 = CBigNum(~uint256(0) >> 16);
        
        vAlertPubKey = ParseHex("04c20398b68bda9178e6b2ff4cddc8188608b9274921539e65af6e3b3199fbd8d3d9069d2c154aa3dbd54f89cd0bd8c04f0ba39bb100bc8ae25af2cf7fae21fd6c");
        nDefaultPort = 7980;
        nRPCPort = 7979;
        strDataDir = "testnet";

        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 96147;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000fdae910d0f4a9b7c0ee0f564254c6d998ad4e028a2c5d128d33a1a333531"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(34)                    .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[SCRIPT_ADDRESS] = list_of(39)                    .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[SECRET_KEY]     = list_of(161)                   .convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x34)(0x18)(0xBB).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x34)(0x11)(0x56).convert_to_container<std::vector<unsigned char> >();
        
        //convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        // convertSeeds(vFixedSeeds, pnSeed, ARRAYLEN(pnSeed), nDefaultPort);

        //nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xaf;
        pchMessageStart[1] = 0x6b;
        pchMessageStart[2] = 0xb3;
        pchMessageStart[3] = 0xaa;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1442228811;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 3;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 8989;
        strDataDir = "regtest";



        assert(hashGenesisBlock == uint256("0x62dcb4feb636c48e60748c496f250070699280cb77477cf4977bdabc6358931c"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

const CChainParams &TestNetParams() {
    return testNetParams;
}

const CChainParams &MainNetParams() {
    return mainParams;
}

void SelectParams(CChainParams::Network network)
{
    switch (network)
    {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    };
};

bool SelectParamsFromCommandLine()
{
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest)
    {
        return false;
    };

    if (fRegTest)
    {
        SelectParams(CChainParams::REGTEST);
    } else
    if (fTestNet)
    {
        SelectParams(CChainParams::TESTNET);
    } else
    {
        SelectParams(CChainParams::MAIN);
    };
    
    return true;
}
