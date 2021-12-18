#include "include/Output.h"
#include "include/picosha256.h"

Output::Output(const uint64_t amount, const std::string &scriptPubKey) : amount{amount}, scriptPubKey{scriptPubKey}
{
}

std::string Output::getHash() const
{
	std::string str = scriptPubKey + std::to_string(amount);
	return picosha2::hash256_hex_string(str);
}

std::string Output::getScriptPubKey() const
{
	return scriptPubKey;
}

uint64_t Output::getAmount() const
{
	return amount;
}