#pragma once

#include <memory>
#include <random>
#include "aquarium.h"

class Organism
{
public:
	Organism();
	Organism(std::shared_ptr<Aquarium> pointer);
	virtual ~Organism();
	Organism(int x, int y, std::shared_ptr<Aquarium> pointer);

	virtual void move() = 0;
	virtual std::shared_ptr<Organism> breeding() = 0;
	virtual void eat() = 0;
	virtual void live() = 0;
protected:
	std::shared_ptr<Aquarium> aquarPtr;
	int lifetime;
	int calories;
	int caloriesForBreeding;
	int cooldownBreeding;
	double visionRad = 0;
	int x;
	int y;

};

