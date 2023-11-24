// Copyright (c) 2017 The AustraliaCash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AUSTRALIACASH_RPC_MINING_H
#define AUSTRALIACASH_RPC_MINING_H

#include <script/script.h>

#include <univalue.h>

#include <memory>

class AuxpowMiner;

/** Generate blocks (mine) */
UniValue generateBlocks(std::shared_ptr<CReserveScript> coinbaseScript, int nGenerate, uint64_t nMaxTries, bool keepScript);

/** Check bounds on a command line confirm target */
unsigned int ParseConfirmTarget(const UniValue& value);

/** Singleton instance of the AuxpowMiner, created during startup.  */
extern std::unique_ptr<AuxpowMiner> g_auxpow_miner;

#endif
