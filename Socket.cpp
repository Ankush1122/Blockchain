#include "include/Socket.h"

Socket::Socket()
{
	selfSock = socket(AF_INET, SOCK_STREAM, 0);
	if (selfSock < 0)
	{
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}
}

int Socket::serverSocket(int port)
{
	int opted = 1;
	if (setsockopt(selfSock, SOL_SOCKET, SO_REUSEADDR, &opted, sizeof(opted)))
	{
		perror("Can't set the socket");
		exit(EXIT_FAILURE);
	}

	memset(&listeningAddress, 0, sizeof(listeningAddress));
	listeningAddress.sin_family = AF_INET;
	listeningAddress.sin_port = htons(port);
	listeningAddress.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(selfSock, (struct sockaddr *)&listeningAddress, sizeof(listeningAddress)) < 0)
	{
		perror("could not bind");
		exit(EXIT_FAILURE);
	}
	if (listen(selfSock, 3) < 0)
	{
		perror("Can't listen from the server !");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Socket::nodeSocket(const char *ip, int port)
{
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	// Converting IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address ! This IP Address is not supported !\n");
		return -1;
	}

	if (connect(selfSock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Connection Failed : Can't establish a connection over this socket !");
		return -1;
	}
	std::string client_ip = inet_ntoa(serv_addr.sin_addr);
	int client_port = ntohs(serv_addr.sin_port);

	std::cout << "connected to @" << client_ip << ":" << client_port << std::endl;
	return 0;
}

struct sockaddr_in Socket::getListeningAddress()
{
	return listeningAddress;
}

int Socket::getSelfSock()
{
	return selfSock;
}

Socket::~Socket()
{
	close(selfSock);
}
