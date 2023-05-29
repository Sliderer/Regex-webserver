#pragma once

#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

class TCPListener
{
public:
	TCPListener(const char* ipAdress, int m_port)
		: ipAdress(ipAdress), m_port(m_port) {}

	void init();

	void run();

protected:
	// Handler for client connections
	virtual void onClientConnected(int clientSocket) = 0;

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket) = 0;

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length) = 0;

	// Send a message to a client
	void sendToClient(int clientSocket, const char* msg);

	// Broadcast a message from a client
	void broadcastToClients(int sendingClient, const char* msg, int length);

private:
	const char* ipAdress;
	int m_port;
	int m_socket;
	fd_set	m_master;
};

