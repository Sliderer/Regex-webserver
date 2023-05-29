#include <string>
#include <istream>
#include <sstream>
#include <streambuf>
#include <vector>
#include <iterator>
#include <tuple>

#include "WebServer.h"
#include "RoutingManager.h"
#include "Singleton.h"

// Handler for when a message is received from the client
void WebServer::onMessageReceived(int clientSocket, const char* msg, int length)
{

	std::tuple<int, std::string> answer = singleton.GetRoutingManager().GetRequest(msg);

	int responseCode = std::get<int>(answer);
	std::string content = std::get<std::string>(answer);

	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 " << responseCode << " OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: text/html\r\n";
	oss << "Content-Length: " << content.size() << "\r\n";
	oss << "\r\n";
	oss << content;

	std::string output = oss.str();
	int size = output.size() + 1;

	sendToClient(clientSocket, output.c_str());
}

// Handler for client connections
void WebServer::onClientConnected(int clientSocket)
{

}

// Handler for client disconnections
void WebServer::onClientDisconnected(int clientSocket)
{

}