#include "include/DataBaseRepo.h"

int DataBaseRepo::openDB()
{
	rc = sqlite3_open("database.db", &db);
	if (rc)
	{
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Opened database successfully" << std::endl;
		return 0;
	}
}

void DataBaseRepo::closeDB()
{
	sqlite3_close(db);
}

int DataBaseRepo::handleError(int rc, const std::string &errorMes)
{
	if (rc)
	{
		std::cerr << "Error Communicating with DB " << errorMes << "\n";
		return 1;
	}
	else
	{
		std::cout << "DB Operation Successful"
				  << "\n";
		return 0;
	}
}