#pragma once
#include "RoutingManager.h"



class Singleton
{
public:


	Singleton() {
		routingManager = std::move(RoutingManager());
	}

	RoutingManager GetRoutingManager() {
		return routingManager;
	}

private:
	RoutingManager routingManager;
};

static Singleton singleton;