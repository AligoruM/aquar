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
}

Plankton::Plankton(int x_, int y_, std::shared_ptr<Aquarium> pointer)
{
	//std::cout << "constr pointer and cords" << std::endl;
	aquarPtr = pointer;
	para = pointer->getPara();
	x = x_;
	y = y_;
	calories = 10;
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
				x += 1;
			else
			{
				x -= 1;
				return;
			}
		else
			if (x - 1 > 0)
				x -= 1;
			else
			{
				x += 1;
				return;
			}
	}
	if (rand() % 3 == 1)//движение по вертикали
	{
		if (rand() % 2 == 1)
			if (aquarPtr->getPara()->sizeY < y + 1)
				y += 1;
			else
			{
				y -= 1;
				return;
			}
		else
			if (y - 1 > 0)
				y -= 1;
			else
			{
				y += 1;
				return;
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
