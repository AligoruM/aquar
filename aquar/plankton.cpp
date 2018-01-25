#include "plankton.h"



/*Plankton::Plankton()
{
	aquarPtr = nullptr;
	x = 1;
	y = 1;
	calories = 10;
}*/

Plankton::Plankton(std::shared_ptr<Aquarium> pointer)
{
	//std::cout << "constr pointer" << std::endl;
	aquarPtr = pointer;
	para = pointer->getPara();
	x = std::rand() % para->sizeX;
	y = std::rand() % para->sizeY;
	calories = 10;
	sprite.setTexture(para->plankTexture);
	sprite.setPosition(x, y);
}

Plankton::Plankton(int x_, int y_, std::shared_ptr<Aquarium> pointer)
{
	//std::cout << "constr pointer and cords" << std::endl;
	aquarPtr = pointer;
	para = pointer->getPara();
	x = x_;
	y = y_;
	calories = 10;
	sprite.setTexture(para->plankTexture);
	sprite.setPosition(x, y);
}


Plankton::~Plankton()
{
	
}

void Plankton::eat()
{
	//std::cout << "eat" << std::endl;
	calories += para->plankCal;
}

std::shared_ptr<Organism> Plankton::breeding()
{
	//std::cout << "breed" << std::endl;

	calories = 20;
	std::shared_ptr<Organism> obj(new Plankton(x, y - 1, aquarPtr));
	aquarPtr->addOrganism(obj);
	return obj;
}

void Plankton::move()
{
	//std::cout << "move" << std::endl;
	if (rand() % 2 == 1)//движение по горизонтали
	{
		if (rand() % 2 == 1)
			if (aquarPtr->getPara()->sizeX < x + 1)
			{
				sprite.setPosition(x+1, y);
				x += 1;
			}
			else
			{
				sprite.setPosition(x-1, y);
				x -= 1;
			}
		else
			if (x - 1 > 0)
			{
				sprite.setPosition(x-1, y);
				x -= 1;
			}
			else
			{
				sprite.setPosition(x+1, y);
				x += 1;
			}
	}
	if (rand() % 3 == 1)//движение по вертикали
	{
		if (rand() % 2 == 1)
			if (aquarPtr->getPara()->sizeY < y + 1)
			{
				sprite.setPosition(x, y+1);
				y += 1;
			}
			else
			{
				sprite.setPosition(x, y - 1);
				y -= 1;
			}
		else
			if (y - 1 > 0)
			{
				sprite.setPosition(x, y-1);
				y -= 1;
			}
			else
			{
				sprite.setPosition(x, y+1);
				y += 1;
			}
	}
}

int Plankton::getLifetime()
{
	return lifetime;
}

void Plankton::live()
{
	lifetime++;
	if (calories >= (para->calForBreeding + (rand()%25)))
	{
		std::shared_ptr<Organism> trash = breeding();//пока так, может пригодиться
	}
	else
	{
		this->eat();
		this->move();
	}
}

void Plankton::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}
