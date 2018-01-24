#include "aquarium.h"



Aquarium::Aquarium(int plankCount_, Parametres* para_)
{
	para = para_;
	plankCount = plankCount_;
}


Aquarium::~Aquarium()
{
}

void Aquarium::tick()
{
	while (1)
	{
		std::cout << vect.size() << std::endl;
		for (int i = 0; i < vect.size(); i++)
		{
		
			vect[i]->live();
		}
	}
}

void Aquarium::fillAqua(int plankCount)
{
	for (int i = 0; i < plankCount; i++)
	{
		std::shared_ptr<Plankton> tmp(new Plankton(std::shared_ptr<Aquarium>(this)));
		vect.push_back(tmp);
	}
}

Parametres* Aquarium::getPara()
{
	return para;
}

void Aquarium::addOrganism(std::shared_ptr<Organism> org)
{
	vect.push_back(org);
}
