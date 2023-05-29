#pragma once
#include <tuple>
#include <string>
#include <sstream>
#include <vector>

class RoutingManager
{
public:
	std::tuple<int, std::string> GetRequest(const char* request) {
		std::istringstream iss(request);
		std::vector<std::string> requsetStream((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
		const std::string ans = requsetStream[1];
		return std::make_tuple<int, std::string>(200, ans.c_str());
	}

private:


};

