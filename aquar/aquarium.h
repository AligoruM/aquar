#pragma once
#include <vector>
#include "organism.h"
#include <memory>
class Aquarium
{
public:
	Aquarium();
	~Aquarium();
	
	void tick();

	std::pair<int, int> getSize();

protected:
	std::vector<std::shared_ptr<Organism>> vect;
	int heigh;
	int width;
};

