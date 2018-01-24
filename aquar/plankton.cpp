#include "plankton.h"



Plankton::Plankton(std::shared_ptr<Aquarium> pointer)
{
	aquarPtr = pointer;
	std::pair<int, int> size = aquarPtr->getSize();
	x = std::rand() % size.first;
	y = std::rand() % size.second;
}

Plankton::Plankton(int x, int y, std::shared_ptr<Aquarium> pointer)
{
	
}


Plankton::~Plankton()
{
}

void Plankton::eat()
{
	calories += 1;
}

std::shared_ptr<Organism> Plankton::breeding()
{

	return std::shared_ptr<Organism>();
}

void Plankton::move()
{
}
