/**
 *            ### EMBEDDED SYSTEMS ####
 *
 *  activity 03: Implementation of a blockchain prototype
 *
 * @author: Geymerson Ramos
 * @email: geymerson@ic.ufal.br
 * last modified: March 3, 2018
**/

#include <stdio.h>
#include "ICBlockchain.h"

int main() {
    ICBlockchainCreateBlockchain();
    ICBlockchainMineNewBlock(0x44, 0x74, 17);
    ICBlockchainMineNewBlock(0x42, 0x60, 4);
    ICBlockchainMineNewBlock(0x50, 0x33, 7);
    ICBlockchainGenerateBlockchainLog();
    if(ICBlockchainVerifyBlockchain()) {
        printf("This is a valid blockchain\n");
    } else {
        printf("Invalid blockchain\n");
    }

    ICBlock* block = ICBlockchainGetLastBlock();
    block->data.amout = 5;

    ICBlockchain blockchain = ICBlockchainGetBlockchain();
    printf("blockchain size: %d\n", blockchain.size);
    for(int i = 0; i < blockchain.size; i++) {
        printf("blockchain data: %d\n", blockchain.blockchain[i].data.amout);
    }
    if(ICBlockchainVerifyBlockchain()) {
        printf("This is a valid blockchain\n");
    } else {
        printf("Invalid blockchain\n");
    }
	return 0;
}
