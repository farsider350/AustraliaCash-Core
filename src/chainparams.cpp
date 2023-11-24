// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin developers
// Copyright (c) 2009-2018 The Litecoin developers
// Copyright (c) 2009-2018 The Dogecoin developers
// Copyright (c) 2019 The AustraliaCash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/merkle.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>

#include <assert.h>

#include <chainparamsseeds.h>
#include <auxpowforkparams.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1386325540, nBits=1e0ffff0, nNonce=99943, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "May 13, 2013 11:34pm EDT: U.S. crude futures were up 0.3 percent at $95.41 a barrel";
    const CScript genesisOutputScript = CScript() << ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 840000;
        consensus.BIP16Exception = uint256();
        //consensus.BIP16Height = 0; // int64 nBIP16SwitchTime = 1349049600
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256S("4b22bb52e51d5b2f3f7648f61b81b69b3359d8d630d2253b81a92d7948d8676a");
        consensus.BIP65Height = 1; // OP_CHECKLOCKTIMEVERIFY
        consensus.BIP66Height = 1; // ToDo make sure these work with aux


        consensus.nDiffChangeTarget = 750000; // 750k ToDo - change?
        consensus.patchBlockRewardDuration = 20160;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); 
        consensus.nPowTargetTimespan = 0.5 *24 * 60 * 60;
        consensus.nPowTargetSpacing = 2.5 * 60;
        
        consensus.nTargetTimespanRe = 60 * 60; // australiacash: 1 hour
        consensus.nTargetSpacingRe = 1 * 30; // australiacash: 30 sec
        
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 6048; // 75% of 8064
        consensus.nMinerConfirmationWindow = 8064; // nPowTargetTimespan / nPowTargetSpacing * 4
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999;


        // Deployment of BIP68, BIP112, and BIP113.
        // XXX: BIP heights and hashes all need to be updated to AustraliaCash values
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1547078400;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1576195200;

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1547078400;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1576195200;



        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000000037ca543d83432af");
		
        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x1b340cd2dd8990b4e8c1c686038cb4d882cd6a71991bb0a0381027af7851e892");

        // AuxPoW parameters
		consensus.nAuxpowChainId = AUXPOW_CHAIN_ID;
        consensus.nAuxpowStartHeight = AUXPOW_START_HEIGHT;
        consensus.fStrictChainId = true;
        consensus.nLegacyBlocksBefore = AUXPOW_START_HEIGHT;    

        // Blocks ? - ? are  AuxPoW without LWMA
        consensus.nDiffChangeTargetLWMA = LWMA_START_HEIGHT;
        consensus.nLWMAPowTargetTimespan = 30;
        consensus.lwmaAveragingWindow = 120;
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xf1;
        pchMessageStart[1] = 0xc6;
        pchMessageStart[2] = 0xf2;
        pchMessageStart[3] = 0xcb;
        nDefaultPort = 1986;
        nPruneAfterHeight = 100000;
        
        genesis = CreateGenesisBlock(1542015250, 2084598007, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x273a20070d7cb57e4c77354d8bd5e01c1cf7d96ad32d91a7b7d183e30da12ef5"));
        assert(genesis.hashMerkleRoot == uint256S("0xaa43989047f144331fc6400859c691b11c0e111ead1977511d340860c1c5ad1f"));

        // Note that of those which support the service bits prefix, most only support a subset of
        // possible options.
        // This is fine at runtime as we'll fall back to using them as a oneshot if they don't support the
        // service bits we want, but we should get them updated to support all service bits wanted by any
        // release ASAP to avoid it where possible.
        vSeeds.emplace_back("australiacash.org");
        vSeeds.emplace_back("161.43.201.255");
        vSeeds.emplace_back("165.232.173.117");
        vSeeds.emplace_back("104.156.233.160");
        vSeeds.emplace_back("104.156.239.75");
        vSeeds.emplace_back("45.32.244.142");
        vSeeds.emplace_back("207.148.85.226");
        vSeeds.emplace_back("104.27.141.137");
        vSeeds.emplace_back("104.20.149.177");
        vSeeds.emplace_back("104.24.6.35");
        vSeeds.emplace_back("67.219.100.165")
        vSeeds.emplace_back("207.148.87.64")

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,63);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,23);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x07, 0x77, 0xC3, 0x1D};
        base58Prefixes[EXT_SECRET_KEY] = {0x05, 0x66, 0xAA, 0xF2};

        bech32_hrp = "aus";

        //TODO: fix this for australiacash -- plddr
        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
        //vFixedSeeds.clear();

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = {
            {
                {  0, uint256S("0x7f90a957c7c307305924641f651423456cab5d456457d82671927361609d9215")},
        {  2100, uint256S("0x0019f21b64cdae0379225a935dfc0f44030f45411eff5a2910b2f391875d872d")},
		{  4957, uint256S("0x7577ff0728fe984476bf2f9fa9261133d78da4f2af6feb036bf7e2a82a2d6055")},
		{  10212, uint256S("0xe004ad1378f39ca06bf0cff572a1c5f7369bb61add1d039f23c082cae9b3c2ea")},
		{  15215, uint256S("0x040dbc53aa7aeedef70600430446c7a636a3bf7a143b2644cf745c3bd9269deb")},
		{  16915, uint256S("0x1bd4305f93404ddcc65da27e2898494df8f8d04d55c8bb2ff8b7f0636d2fcc73")},
		{  18648, uint256S("0x1a193a850f29228ddee8cae435c51cc215e962446b7d0166222e497056cbdd76")},
		{  20135, uint256S("0xff5f29ec67713b790b8e72089c58724a6f7ed7d10bac441e7a03a756cd3c41ae")},
		{  22356, uint256S("0xc1c6d7e497a5a63723045baa144bd8ca167beded471170a5ecc3494d6400107c")},
		{  24872, uint256S("0xd93d562dc901fa171a7bb98120ebc3ac225640bf26143cb2cb851aef43b99341")},
		{  29517, uint256S("0x89158c1bb3dde6e01f30f476922ec8ebae195dbb2063ccef46a33eeec2923b15")},
		{  30210, uint256S("0x34e2d49d3138bb73429efbcd87303fca223b60f1f9b1e19d840579d4944b8e3a")},
		{  31502, uint256S("0xd5bc86ab92257f0e3eb149f69ba180410092c6465639d8fd5ab8525c1a2a0200")},
		{  32985, uint256S("0x58815a2fdec8b91cf0e84197cb0eea88dd705edd962e4784a43d6783fe03963f")},
		{  37846, uint256S("0x1e7d1f67de29e32e06c23426f9346a99876a24d664fcddbdd2705e8054dc5530")},
		{  40000, uint256S("0xf2243cce020a8354758e4f26d4398656e80b2b91add91681d8a729248ff3e473")},
		{  45000, uint256S("0x49f2754bc381ac77c1cc36210e8862935de2ff5346a66b9817906bb9223c0c90")},
		{  50000, uint256S("0xfb09f0e9fc709c22e84b014bfbe11eb1a8ede673ab0873f03bf1bc70662b2a62")},
		{  55000, uint256S("0x370f787f4daf4ac52c9d2560298de8e25efc40930804f55fac91f88cca91fecc")},
		{  60000, uint256S("0x7ce107de1168a9052fb4bee934e3acf8a9694f6e5310b74fe40ffcd4536ddf1f")},
		{  65000, uint256S("0x4e500fd331c28b3dccc714978d437b4cdde7675f69b84423c176f58b177a668b")},
		{  70000, uint256S("0x2a954526a229c4679a950b08754460bd62ea7d88f7634fa020cf49c4bfe21312")},
		{  75000, uint256S("0xddcc79c889ae5a72aab32abe826478b865e0df6cc4e0608bea0c3195237d0745")},
		{  80000, uint256S("0x9b6230d9066906640bcfe26bc92b3eb1f1f52ea59c7aa107844dd7902ce1f70c")},
		{  85000, uint256S("0xd410c1187292bb4e1a17e88a499fbd727cf1742b2eab2eb3257135e4522e6a77")},
		{  90000, uint256S("0x8d4c267b390daa0913397f4357dd6b38f119f1d463bfcdcb1d5c4457eec6c2ec")},
		{  95000, uint256S("0x16ae3b52e588a4750d1670127a66b428b64396709824e6b08d8050369b932c54")},
		{ 130000, uint256S("0x233f0791e8beab0ea34af5aa4db4f9e9e78b4e6f570e7af3a26a94432019d697")},
        { 232059, uint256S("0x1b340cd2dd8990b4e8c1c686038cb4d882cd6a71991bb0a0381027af7851e892")},
            }
        };

        chainTxData = ChainTxData{
            // Data from rpc: getchaintxstats 4096 a601455787cb65ffc325dda4751a99cf01d1567799ec4b04f45bb05f9ef0cbde
            /* nTime    */ 1658034247,
            /* nTxCount */ 8296601,
            /* dTxRate  */ 0.02991589890928619
        };

        /* disable fallback fee on mainnet */
		// ToDo
        m_fallback_fee_enabled = true;
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 500
        consensus.BIP16Exception = uint256();
        //consensus.BIP16Height = 0; // always enforce P2SH BIP16 on testnet
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256S("");
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 60 * 60; // 7 days
        consensus.nPowTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1483228800; // January 1, 2017
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1517356801; // January 31st, 2018

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1483228800; // January 1, 2017
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1517356801; // January 31st, 2018

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x14b1da80b3d734d36a4a2be97ed2c9d49e79c47213d5bcc15b475a1115d28918"); //0

	// AuxPoW parameters
        consensus.nAuxpowChainId = AUXPOW_CHAIN_ID;
	consensus.nAuxpowStartHeight = 5;            // test-net only	
        consensus.fStrictChainId = true;
	consensus.nLegacyBlocksBefore = 5;           // test-net only
        
        pchMessageStart[0] = 0xab;
        pchMessageStart[1] = 0xd2;
        pchMessageStart[2] = 0xc8;
        pchMessageStart[3] = 0xf1;
        nDefaultPort = 2018;
        nPruneAfterHeight = 1000;
        
        genesis = CreateGenesisBlock(1541015250, 319977, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x32fbb5ecde32b9506eec7e75efd9d390f7e9d3dc06aa7a9a430f0a131307be7e"));
        assert(genesis.hashMerkleRoot == uint256S("0x273a20070d7cb57e4c77354d8bd5e01c1cf7d96ad32d91a7b7d183e30da12ef5"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
	    //vSeeds.emplace_back("testnet-seed.eacpay.com");
	    //vSeeds.emplace_back("testnet-seed.australiacash.global");    

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,25);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,65);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,23);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x07, 0x77, 0xC3, 0x1D};
        base58Prefixes[EXT_SECRET_KEY] = {0x05, 0x66, 0xAA, 0xF2};

        bech32_hrp = "taus";

        //TODO: fix this for australiacash -- plddr
        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));
        //vFixedSeeds.clear();

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData) {
            {
                {0, uint256S("0xdf83d8ce31005c88ee7e27aaf802a96dd6042800300c35d3045fe013a105ac39")},
            }
        };

        chainTxData = ChainTxData{
            // Data from rpc: getchaintxstats 4096 438b7e1c86f58b4e62e8cf2d0f9f256e3dddaebc5d1cc568e633a38e0db6c025
            /* nTime    */ 1565582448,
            /* nTxCount */ 2848910,
            /* dTxRate  */ 0.02265200874042768
        };

        /* enable fallback fee on testnet */
        m_fallback_fee_enabled = true;
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Exception = uint256();
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.powLimit = uint256S("0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~uint256(0) >> 1;
        consensus.nPowTargetTimespan = 30 * 60; 
        consensus.nPowTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (60 instead of 240)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 19444;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1396382110, 1529337473, 0x1e0ffff0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        //LogPrint(BCLog::ALL, "CreateGenesisBlock GetHash is 0x%X\n", consensus.hashGenesisBlock);
        // assert(consensus.hashGenesisBlock == uint256S("0x14b1da80b3d734d36a4a2be97ed2c9d49e79c47213d5bcc15b475a1115d28918"));
        // assert(genesis.hashMerkleRoot == uint256S("0x13757c3610411891452ac1f04d7f81946339b0e5b5aba216e6646e81805c4bb1"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;

        checkpointData = {
            {
                {0, uint256S("0x14b1da80b3d734d36a4a2be97ed2c9d49e79c47213d5bcc15b475a1115d28918")},
            }
        };
        
        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        // base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "raus";

        /* enable fallback fee on regtest */
        m_fallback_fee_enabled = true;
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}
