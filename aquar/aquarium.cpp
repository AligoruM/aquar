#include "aquarium.h"



Aquarium::Aquarium(Parametres* para_)
{
	window = new sf::RenderWindow(sf::VideoMode(para_->sizeX, para_->sizeY), "Aquarium");
	para = para_;
}


Aquarium::~Aquarium()
{

}

void Aquarium::tick()
{

	while (window->isOpen())
	{
		window->clear();
		std::cout << vect.size() << std::endl;
		std::srand(time(NULL));
		for (auto elem=vect.begin(); elem!=vect.end();)
		{
			if ((*elem)->getLifetime() > para->plankLifetime) 
			{
				elem->reset();
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
		Sleep(20);
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

void Aquarium::drawAquar()
{
	for (int i = 0; i < vect.size(); i++)
		vect[i]->draw(window);
}

