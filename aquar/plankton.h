#pragma once
#include "organism.h"
class Plankton: public Organism
{
public:
	Plankton();
	Plankton(std::shared_ptr<Aquarium> pointer);
	Plankton(int x, int y, std::shared_ptr<Aquarium> pointer);
	~Plankton();

	virtual void eat();
	virtual std::shared_ptr<Organism> breeding();
	virtual void move();

	virtual void live();
};

