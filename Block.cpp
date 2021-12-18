#include "include/Block.h"

Block::Block(const uint8_t currentIndex, const std::vector<Transaction> &transactionVector, const uint64_t nonce, const std::string &previousHash)
	: currentIndex{currentIndex}, transactionVector{transactionVector}, nonce{nonce}, previousHash{previousHash}
{
	selfHash = generateHash();
}

bool Block::validateHash()
{
	return getSelfHash() == generateHash();
}

std::string generateTxVectorHash(const std::vector<Transaction> &transactionVector)
{
	std::string hash;
	for (uint i = 0; i < transactionVector.size(); i++)
	{
		hash += transactionVector[i].getTxHash();
	}
	return picosha2::hash256_hex_string(hash);
}

std::string Block::generateHash()
{
	std::string str = std::to_string(getCurrentIndex()) + generateTxVectorHash(transactionVector) + std::to_string(getNonce());
	return picosha2::hash256_hex_string(str);
}

uint8_t Block::getCurrentIndex()
{
	return currentIndex;
}

std::vector<Transaction> Block::getTransactionVector()
{
	return transactionVector;
}

uint64_t Block::getNonce()
{
	return nonce;
}

std::string Block::getSelfHash()
{
	return selfHash;
}

std::string Block::getPreviousHash()
{
	return previousHash;
}

void Block::setNonce(uint64_t nonce)
{
	this->nonce = nonce;
}

bool Block::validateNonce(uint8_t difficulty)
{
	for (uint64_t i = 0; i < difficulty; i++)
	{
		if (selfHash[i] != '0')
		{
			return false;
		}
	}
	return true;
}