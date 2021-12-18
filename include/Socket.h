#pragma once

#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

class Socket
{
private:
	int selfSock;
	struct sockaddr_in listeningAddress;

public:
	Socket();
	int serverSocket(int port);
	int nodeSocket(const char *ip, int port);
	int getSelfSock();
	struct sockaddr_in getListeningAddress();
	~Socket();
};
