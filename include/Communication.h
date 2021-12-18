#pragma once

#include <iostream>
#include <arpa/inet.h>
#include <cstring>

class Communication
{
public:
	std::string recieveMes(int nodeSocket);

	int sendMes(std::string message, int nodeSocket);
};