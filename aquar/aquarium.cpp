#include "aquarium.h"



Aquarium::Aquarium()
{
}


Aquarium::~Aquarium()
{
}

void Aquarium::tick()
{

	for (int i = 0; i < vect.size(); i++)
		vect[i]->live();
}

std::pair<int, int> Aquarium::getSize()
{
	return std::pair<int, int>(width, heigh);
}