#include "include/BlockRepo.h"

int callback(void *ptr, int argc, char **argv, char **azColName)
{
	Block *p = reinterpret_cast<Block *>(&ptr);
	p->getNonce();
	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int BlockRepo::insertBlock(Block block)
{
	std::string index = std::to_string(block.getCurrentIndex());
	std::string nonce = std::to_string(block.getNonce());
	std::string previousHash = block.getPreviousHash();
	std::string selfHash = block.getHash();

	sqlQuery = "INSERT INTO Block (index,nonce,previousHash,selfHash) "
			   "VALUES (" +
			   index + "," + nonce + "," + previousHash + "," + selfHash + ");";
	rc = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &errorMes);

	if (handleError(rc, sqlite3_errmsg(db)))
		return 1;
	// insert Transaction
	// insert Inputs
	// insert Outputs
	return 0;
}

int BlockRepo::removeBlock(int index)
{
	sqlQuery = "DELETE FROM Block WHERE index=" + std::to_string(index) + ";";
	rc = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &errorMes);
	if (handleError(rc, sqlite3_errmsg(db)))
		return 1;
	return 0;
}

int BlockRepo::getBlock(int index, Block block)
{
	void *ptr = reinterpret_cast<void *>(&block);
	sqlQuery = "SELECT * FROM Block WHERE index=" + std::to_string(index) + ";";
	rc = sqlite3_exec(db, sqlQuery.c_str(), callback, ptr, &errorMes);
	if (handleError(rc, sqlite3_errmsg(db)))
		return 1;
	return 0;
}