#include "include/Communication.h"

#define HEADERSIZE 10
#define BUFFERLENGTH 1023

int lengthOf(int size)
{
	int m = size;
	for (int i = 1;; i++)
	{
		m = m / 10;
		if (m < 1)
		{
			return i;
		}
	}
}

std::string Communication::recieveMes(int nodeSocket)
{
	int buffRecv = 1023;
	std::string mes;
	char buffer[BUFFERLENGTH];
	char s[HEADERSIZE];
	std::memset(s, 0, HEADERSIZE);
	int a = recv(nodeSocket, s, HEADERSIZE, 0);
	if (a == 0)
	{
		return "DISCONNECTED";
	}
	if (a < 0)
	{
		perror("error recieving message");
		return "ERROR";
	}
	int size = atoi(s);
	for (int i = 0; i <= ((size - 1) / BUFFERLENGTH); i++)
	{
		if (i == (size - 1) / BUFFERLENGTH)
		{
			buffRecv = size % BUFFERLENGTH;
		}
		memset(buffer, 0, BUFFERLENGTH);
		int bytesRecieved = recv(nodeSocket, buffer, buffRecv, 0);

		if (bytesRecieved < 0)
		{
			perror("error recieving message");
			return "ERROR";
		}
		mes = mes + buffer;
	}
	return mes;
}

int Communication::sendMes(std::string message, int nodeSocket)
{
	int size = message.size();
	std::string msg = std::to_string(size);
	int x = HEADERSIZE - lengthOf(size);
	for (int i = 0; i < x; i++)
	{
		msg = msg + " ";
	}
	msg = msg + message;

	int bytesSent = send(nodeSocket, msg.c_str(), msg.length(), 0);
	if (bytesSent < 0)
	{
		perror("could not send");
		return 1;
	}
	return 0;
}