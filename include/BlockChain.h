#pragma once

#include <vector>
#include <iostream>
#include <string>
#include "Block.h"
//#include "NodeServer.h"

class BlockChain
{
private:
	std::vector<Block> chain;
	//NodeServer nodeServer;

public:
	BlockChain();
	void mineBlock(const std::vector<Transaction> &transactionVector);
	Block getGenesisBlock();
	int proofOfWork(Block &block, uint8_t difficulty);
	bool validateBlockChain();
	void printBlockChain();
	//void registerNode(const char *ip, int port);
};