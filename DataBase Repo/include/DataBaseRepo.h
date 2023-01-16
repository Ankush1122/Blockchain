#pragma once

#include "sqlite3/sqlite3.h"
#include <iostream>
#include <vector>

class DataBaseRepo
{
protected:
	sqlite3 *db;
	char *errorMes;
	int rc;
	std::string sqlQuery;

public:
	int openDB();
	void closeDB();
	int handleError(int rc, const std::string &errorMes);
};
