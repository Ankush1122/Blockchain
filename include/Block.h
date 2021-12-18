#pragma once

#include "Transaction.h"
#include <iostream>
#include <vector>
#include "picosha256.h"

class Block
{
private:
	const u_int8_t currentIndex;
	const std::vector<Transaction> transactionVector;
	uint64_t nonce;
	const std::string previousHash;
	std::string selfHash;

public:
	Block(const uint8_t currentIndex, const std::vector<Transaction> &transactionVector, const uint64_t nonce, const std::string &previousHash);
	std::string generateHash();
	std::string getSelfHash();
	std::string getPreviousHash();
	uint8_t getCurrentIndex();
	uint64_t getNonce();
	std::vector<Transaction> getTransactionVector();
	bool validateHash();
	bool validateNonce(uint8_t difficulty);
	void setNonce(uint64_t nonce);
};
