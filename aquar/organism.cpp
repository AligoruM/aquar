#include "organism.h"

Organism::Organism(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres)
{
	organisms = organisms_;
	para = parametres;
}

void Organism::setPosition(sf::Vector2i pos_)
{
	pos = pos_;
}

sf::Vector2i Organism::getPosition()
{
	return pos;
}


