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
	void addOrganism(std::shared_ptr<Organism> org);
protected:
	std::vector<std::shared_ptr<Organism>> vect;
	int heigh;
	int width;
};

