#pragma once
#include "organism.h"
#include "aquarium.h"

class Plankton: public Organism
{
public:
	Plankton() = delete;
	Plankton(std::shared_ptr<Aquarium> pointer);
	Plankton(int x, int y, std::shared_ptr<Aquarium> pointer);
	~Plankton();

	virtual void eat();
	virtual std::shared_ptr<Organism> breeding();
	virtual void move();

	virtual void live();
protected:
	std::shared_ptr<Aquarium> aquarPtr;
	int lifetime;
	int calories;
	int x;
	int y;

	Parametres* para;
};

