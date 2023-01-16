#pragma once
#include <iostream>

class Output
{
private:
	const uint64_t amount;
	const std::string pubKey;

public:
	Output(const uint64_t amount, const std::string &pubKey);
	std::string getHash() const;
	uint64_t getAmount() const;
	std::string getPubKey() const;
};