#pragma once

#include "plankton.h"
class Organism;


class Aquarium
{
public:
	Aquarium(Parametres* para_);
	~Aquarium();
	
	void tick();
	void fillAqua(int plankCount);
	Parametres* getPara();
	std::vector<std::shared_ptr<Organism>>* getOrganism();
	void drawAquar();


protected:
	std::vector<std::shared_ptr<Organism>> vect;
	sf::RenderWindow* window;
	Parametres* para;

	int startPlankCount;
};

