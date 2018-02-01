#include "organism.h"

Organism::Organism(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres)
{
	organisms = organisms_;
	para = parametres;
}

Organism::~Organism()
{
	
}

void Organism::setPosition(sf::Vector2f pos_)
{
	pos = pos_;
}

sf::Vector2f Organism::getPosition()
{
	return pos;
}


