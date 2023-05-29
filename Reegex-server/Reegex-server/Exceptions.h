#pragma once
#include<map>
#include<iostream>

class Exceptions
{

public:
	enum Exception {
		BAD_TCP_LISTENER, 
		BAD_SOCKET, 
		SOKCET_ERROR
	};

	static std::exception GetException(Exception exceptionType);
	

private:
	static class BadTCPListener : public std::exception {
	public:
		const char* what() const override {
			return "ERROR WITH CREATING TCP LISTENER\n";
		}
	};

	static class BadSocket : public std::exception {
	public:
		const char* what() const override {
			return "ERROR WITH CREATING SOCKET\n";
		}
	};

	static class SocketError : public std::exception {
	public:
		const char* what() const override {
			return "ERROR IN SOCKET\n";
		}
	};

	static std::map<Exception, std::exception> exceptions;	

};

