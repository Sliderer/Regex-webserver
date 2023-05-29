#pragma once
#include "TCPListener.h"

class WebServer : public TCPListener
{
public:

	WebServer(const char* ipAddress, int port) :
		TCPListener(ipAddress, port) { }

protected:

	// Handler for client connections
	virtual void onClientConnected(int clientSocket) override;

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket) override;

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length) override;
};