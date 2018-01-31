#include "aquarium.h"



Aquarium::Aquarium(Parametres* para_)
{
	para = para_;
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
		std::srand(time(NULL));
		for (auto elem=vect.begin(); elem!=vect.end();)
		{
			if ((*elem)->getLifetime() > para->plankLifetime) 
			{
				elem = vect.erase(elem);
			}
			else
				elem++;
		}
		for (int i = 0; i < vect.size(); i++) 
		{
			vect[i]->live();
			vect[i]->draw(window);
		}
		window->display();
		Sleep(5);
	}
}

void Aquarium::fillAqua(int plankCount)
{
	for (int i = 0; i < plankCount; i++)
	{
		std::shared_ptr<Plankton> tmp(new Plankton(&vect, para));
		vect.push_back(tmp);
	}
}

Parametres* Aquarium::getPara()
{
	return para;
}

std::vector<std::shared_ptr<Organism>>* Aquarium::getOrganism()
{
	return &vect;
}

