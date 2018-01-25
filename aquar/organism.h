#pragma once

#include <memory>
#include <random>
#include "parametres.h"

class Aquarium;

class Organism
{
public:
	virtual void move() = 0;
	virtual std::shared_ptr<Organism> breeding() = 0;
	virtual void eat() = 0;
	virtual void live() = 0;
	virtual int getLifetime() = 0;
};

