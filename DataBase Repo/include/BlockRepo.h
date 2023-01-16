#pragma once

#include "DataBaseRepo.h"
#include "../../include/Block.h"
#include "../../include/Transaction.h"

class BlockRepo : public DataBaseRepo
{
public:
	int insertBlock(Block block);
	int removeBlock(int index);
	int getBlock(int index, Block block);
};

/*
class BaseRepo
{
	int a, b, c;

public:
	virtual void save() {}
};

class FileRepo : public BaseRepo
{
	int a;

public:
	void save() {}
};

class DataBaseRepo : public BaseRepo
{
public:
	void save() {}
};

int saveBlock(BaseRepo b) {}

int fb()
{
	saveBlock(FileRepo());
}
*/