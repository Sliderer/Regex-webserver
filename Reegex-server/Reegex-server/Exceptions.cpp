#include "Exceptions.h"

std::exception Exceptions::GetException(Exception exceptionType) {
	if (exceptions.find(exceptionType) == exceptions.end()) {
		std::cout << "EXCEPTION IS NOT FOUND\n";
		std::terminate;

	}
	return exceptions.at(exceptionType);
}

std::map<Exceptions::Exception, std::exception> Exceptions::exceptions = {
	std::make_pair(BAD_TCP_LISTENER, BadTCPListener()),
	std::make_pair(BAD_SOCKET, BadSocket()),
	std::make_pair(SOKCET_ERROR, SocketError())
};

