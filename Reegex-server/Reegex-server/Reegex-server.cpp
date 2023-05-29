#include <iostream>
#include <winsock2.h>
#include "WebServer.h"
#include "Singleton.h"

int main()
{
	WebServer webServer("127.0.0.1", 8080);

	try {
		webServer.init();
	}
	catch (std::exception exception) {
		std::cout << exception.what();
	}
	webServer.run();
}