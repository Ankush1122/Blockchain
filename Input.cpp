
#include "include/Input.h"
#include "include/picosha256.h"

Input::Input(const uint64_t blockNo, const uint8_t txHash, const std::string &scriptSig) : blockNo{blockNo}, txHash{txHash}, scriptSig{scriptSig}
{
}

std::string Input::getHash() const
{
	std::string str = scriptSig + std::to_string(blockNo) + std::to_string(txHash);
	return picosha2::hash256_hex_string(str);
}

std::string Input::getScriptSig() const
{
	return scriptSig;
}

uint64_t Input::getBlockNo() const
{
	return blockNo;
}

uint8_t Input::getTxHash() const
{
	return txHash;
}