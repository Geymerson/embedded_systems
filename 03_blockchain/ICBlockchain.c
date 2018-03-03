/**
 *            ### EMBEDDED SYSTEMS ####
 *
 *  activity 03: Implementation of a blockchain prototype
 *
 * @author: Geymerson Ramos
 * @email: geymerson@ic.ufal.br
 * last modified: March 3, 2018
**/

#include <string.h>
#include "ICBlockchain.h"

static ICBlockchain __blockchain;
static int16_t __index = -1;
static uint16_t __length = 0;

void CreatBlockchain() {
    ICBlock icBlock;

    //The genesis block has a '0' value previous hash
    memset(icBlock.previousHash.hash, '0', sizeof icBlock.previousHash.hash);

    //Just some arbitrary values
    icBlock.data.receiverAddress = 1;
    icBlock.data.senderAddress = 2;
    icBlock.data.amout = 25;

    //Create block hash
    ICHashCreate(&icBlock.hash, &icBlock.data, &icBlock.previousHash);

    //Update blockchain length and position
    __index = 0;
    __length = 1;
    __blockchain.blockchain[0] = icBlock;
}

ICBlock* GetLastBlock() {
    if(__index == -1) {
        printf("No blockchain created\n");
        return NULL;
    }
    return &__blockchain.blockchain[__length - 1];
}

ICBlock* GetBlockAt(int16_t index) {
    if(index < 0 || index >= __length) {
        printf("index out of range\n");
        return NULL;
    }
    return &__blockchain.blockchain[index];
}

ICBlockchain GetBlockchain() {
    __blockchain.size = __length;
    return __blockchain;
}

bool MineNewBlock(ICAddress sender, ICAddress receiver, int amount) {
    if(__length == BLOCKCHAIN_MAX_SIZE) {
        printf("Max length exceeded\n");
        return false;
    }

    ICHash hash;
    ICBlock block;

    //Fill block data
    block.data.senderAddress = sender;
    block.data.receiverAddress = receiver;
    block.data.amout = amount;

    if(__length == 0) { //If genesis block
        memset(hash.hash, '0', sizeof hash.hash);
        ICHashCopy(&block.previousHash, &hash);
    } else {
        hash = GetLastBlock()->hash;
        ICHashCopy(&block.previousHash, &hash);
    }

    ICHashCreate(&block.hash, &block.data, &block.previousHash);

    __index+=1;
    __length+=1;
    __blockchain.blockchain[__index] = block;
    return true;
}

void GenerateBlockchainLog() {
    for(int i = 0; i < __length; i++) {
        printf("block %d: \n", i);
        char hashOutput[250], previousHashOutput[250], blockDataOutput[250];
        ICHash hash, previousHash;
        ICBlockData blockData = GetBlockAt(i)->data;
        hash = GetBlockAt(i)->hash;
        previousHash = GetBlockAt(i)->previousHash;

        //Generate output strings
        ICHashToString(hashOutput, &hash);
        ICHashToString(previousHashOutput, &previousHash);
        ICBlockDataToString(blockDataOutput, &blockData);

        //Print outputs
        printf("Hash: %s\n", hashOutput);
        printf("Previous hash: %s\n", previousHashOutput);
        printf("Data [sender|receiver|amount]: %s\n\n", blockDataOutput);
    }
}

bool VerifyBlockchain() {
    if(__length == 0) {
        printf("No blockchain created\n");
        return false;
    }

    //i = 1 since genesis block requires no verification
    for(int i = 1; i < __length; i++) {
        if(!ICHashEquals(&GetBlockAt(i)->previousHash, &GetBlockAt(i - 1)->hash)) {
            return false;
        }
    }
    return true;
}
