#include "include/BlockChain.h"
#include "include/Transaction.h"

BlockChain::BlockChain(const std::vector<Transaction> &genesisTr)
{
	Block genesisBlock = getGenesisBlock(genesisTr);
	chain.push_back(genesisBlock);
}

Block BlockChain::getGenesisBlock(const std::vector<Transaction> &genesisTr)
{
	Block genesisBlock(0, genesisTr, 0, 0);
	return genesisBlock;
}

void BlockChain::mineBlock(const std::vector<Transaction> &transactionVector)
{
	uint8_t currentIndex = chain.size();
	uint8_t difficulty = currentIndex; // difficulty = currentIndex for simplicity
	std::string previousHash = chain[currentIndex - 1].getHash();
	Block block(currentIndex, transactionVector, 0, previousHash);
	proofOfWork(block, difficulty);
	if (block.validateNonce(difficulty))
		chain.push_back(block);
	else
		std::cout << "Nonce not found";
}

int BlockChain::proofOfWork(Block &block, uint8_t difficulty)
{
	for (uint64_t nonce = 0;; nonce++)
	{
		block.setNonce(nonce);
		std::string hash = block.getHash();
		for (uint8_t i = 0; i < difficulty; i++)
		{
			if (hash[i] != '0')
			{
				break;
			}
			if (i == difficulty - 1)
			{
				return 0;
			}
		}
	}
}

/*void BlockChain::registerNode(const char *ip, int port)
{
	nodeServer.connect(ip, port);
}*/

/*void BlockChain::printBlockChain()
{
	for (uint8_t i = 0; i < chain.size(); i++)
	{
		Block block = chain[i];
		std::cout << "BlockIndex : " << block.getCurrentIndex() << std::endl;
		std::cout << "Amount : " << block.getTransactionObject().getAmount() << std::endl;
		std::cout << "SenderId : " << block.getTransactionObject().getSenderId() << std::endl;
		std::cout << "ReciverId : " << block.getTransactionObject().getRecieverId() << std::endl;
		std::cout << "Proof : " << block.getProof() << std::endl;
		std::cout << "Previous Hash : " << block.getPreviousHash() << std::endl;
		std::cout << "Self Hash : " << block.getSelfHash() << std::endl;
		std::cout << "Is Hash Valid : " << block.isHashValid() << std::endl
				  << std::endl;
	}
}*/

bool BlockChain::validateBlockChain()
{
	for (uint8_t i = 0; i < chain.size(); i++)
	{
		if (i != 0)
		{
			if (chain[i].validateNonce(i))
				return false;

			if (chain[i].getPreviousHash() != chain[i - 1].getHash())
				return false;
		}
	}
	return true;
}