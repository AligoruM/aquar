#pragma once
#include <vector>
#include "organism.h"
#include <memory>
#include "plankton.h"
#include <iostream>
#include <algorithm>
#include <exception>
class Organism;


class Aquarium
{
public:
	Aquarium(int plankCount_, Parametres* para_);
	~Aquarium();
	
	void tick();
	void fillAqua(int plankCount);
	Parametres* getPara();
	void addOrganism(std::shared_ptr<Organism> org);
protected:
	std::vector<std::shared_ptr<Organism>> vect;
	Parametres* para;
	int plankCount;
};

