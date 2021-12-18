#pragma once
#include <iostream>

class Output
{
private:
	const uint64_t amount;
	const std::string scriptPubKey;

public:
	Output(const uint64_t amount, const std::string &scriptPubKey);
	std::string getHash() const;
	uint64_t getAmount() const;
	std::string getScriptPubKey() const;
};