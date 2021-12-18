#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include "Output.h"
#include "Input.h"
#include "picosha256.h"

class Transaction
{
private:
	const std::vector<Input> inputs;
	const std::vector<Output> outputs;
	std::string txHash;

public:
	Transaction(const std::vector<Input> &inputs, const std::vector<Output> &outputs);
	std::string generateTxHash();
	std::string getTxHash() const;
	std::vector<Input> getInputs() const;
	std::vector<Output> getOutputs() const;
};