#pragma once

#include "Socket.h"
#include "Communication.h"
#include "Block.h"
#include "BlockChain.h"
#include <vector>

class NodeServer
{
private:
	Communication communication;
	Socket sock;

public:
	int connect(const char *ip, int port);
	int recv();
	std::vector<std::vector<Block>> reqChain();
};