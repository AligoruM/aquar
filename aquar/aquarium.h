#pragma once
#include <windows.h>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <exception>
#include "plankton.h"
class Organism;


class Aquarium
{
public:
	Aquarium(int plankCount_, Parametres* para_);
	~Aquarium();
	
	void tick();
	void fillAqua(int plankCount);
	Parametres* getPara();
	std::vector<std::shared_ptr<Organism>>* getOrganism();
protected:
	std::vector<std::shared_ptr<Organism>> vect;
	Parametres* para;
	int startPlankCount;
};

