#include "include/Transaction.h"

Transaction::Transaction(const std::vector<Input> &inputs, const std::vector<Output> &outputs)
	: inputs{inputs}, outputs{outputs}
{
	txHash = generateTxHash();
}

std::string Transaction::generateTxHash()
{
	std::string inputHash;
	std::string outputHash;
	for (uint i = 0; i < inputs.size(); i++)
	{
		inputHash += inputs[i].getHash();
	}
	for (uint i = 0; i < outputs.size(); i++)
		outputHash += outputs[i].getHash();
	std::string str = inputHash + outputHash;
	return picosha2::hash256_hex_string(str);
}

std::vector<Input> Transaction::getInputs() const
{
	return inputs;
}

std::vector<Output> Transaction::getOutputs() const
{
	return outputs;
}

std::string Transaction::getTxHash() const
{
	return txHash;
}
