/**
 *            ### EMBEDDED SYSTEMS ####
 *
 *  Activity 03: Implementation of a blockchain prototype
 *
 * @author: Geymerson Ramos
 * @email: geymerson@ic.ufal.br
 * last modified: March 3, 2018
**/

#ifndef ICBLOCKCHAIN_H
#define ICBLOCKCHAIN_H

#include "ICBlock.h"

//Max size = 100 blocks + genesis block
#define BLOCKCHAIN_MAX_SIZE	101

//Our blockchain struct
typedef struct {
    ICBlock blockchain[BLOCKCHAIN_MAX_SIZE];
    uint16_t size;
} ICBlockchain;

/** BLOCKCHAIN FUNCTIONS **/

//Create an empty blockchain
void CreatBlockchain();

//Get the block in the last position
ICBlock* GetLastBlock();

//Get the block at position 'index'
// 1 <= index <= blockchain length
ICBlock* GetBlockAt(uint8_t index);

//Get the whole blockchain
ICBlockchain GetBlockchain();

//Mine a new block and add it to the blockchain
bool MineNewBlock(ICAddress sender, ICAddress receiver, int amount);

//Generate log
void GenerateBlockchainLog();

//Check for inconsistency in the blockchain sequence
bool VerifyBlockchain();


#endif //ICBLOCKCHAIN_H
