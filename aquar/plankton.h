#pragma once
#include "organism.h"

class Plankton: public Organism
{
public:
	Plankton() = delete;
	Plankton(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres);
	Plankton(int x, int y, std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres);
	~Plankton();


	virtual void death();
	virtual void eat();
	virtual void breeding();
	virtual void move();
	virtual int getLifetime();
	virtual void live();
	virtual void draw(sf::RenderWindow* window);
protected:
};

