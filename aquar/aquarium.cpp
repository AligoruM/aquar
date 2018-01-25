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
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(para->sizeX, para->sizeY), "Aquarium");

	while (window->isOpen())
	{
		window->clear();
		std::cout << vect.size() << std::endl;
		for (auto elem=vect.begin(); elem!=vect.end();)
		{
			if ((*elem)->getLifetime() > para->plankLifetime) 
			{
				elem = vect.erase(elem);
			}
			else
				elem++;
		}
		//try {
		//vect.erase(std::remove_if(vect.begin(), vect.end(), [](std::shared_ptr<Organism> vect) { return  vect->getLifetime() >= 200; }));
		//}
		//catch (std::exception exc)
		//{
		//	std::cout << exc.what() << std::endl;
		//}
		for (int i = 0; i < vect.size(); i++) 
		{
			vect[i]->live();
			vect[i]->draw(window);
		}
		window->display();
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
