#include "include/Output.h"
#include "include/picosha256.h"

Output::Output(const uint64_t amount, const std::string &pubKey) : amount{amount}, pubKey{pubKey}
{
}

std::string Output::getHash() const
{
	std::string str = pubKey + std::to_string(amount);
	return picosha2::hash256_hex_string(str);
}

std::string Output::getPubKey() const
{
	return pubKey;
}

uint64_t Output::getAmount() const
{
	return amount;
}