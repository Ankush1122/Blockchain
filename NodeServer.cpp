#include "include/NodeServer.h"

int NodeServer::connect(const char *ip, int port)
{
	sock.nodeSocket(ip, port);
	return 0;
}

int NodeServer::recv()
{
	while (true)
	{
		communication.recieveMes(sock.getSelfSock());
	}
	return 0;
}

std::vector<std::vector<Block>> NodeServer::reqChain()
{
	std::vector<std::vector<Block>> allChains;
	const std::string type = "RequestChain";
	communication.sendMes(type, sock.getSelfSock());
	return allChains;
}
