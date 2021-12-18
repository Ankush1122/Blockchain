#pragma once
#include <iostream>

class Input
{
private:
	const uint64_t blockNo;
	const uint8_t txHash;
	const std::string scriptSig;

public:
	Input(const uint64_t blockNo, const u_int8_t txHash, const std::string &scriptSig);
	std::string getHash() const;
	uint64_t getBlockNo() const;
	uint8_t getTxHash() const;
	std::string getScriptSig() const;
};
