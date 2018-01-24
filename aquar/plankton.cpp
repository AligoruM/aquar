#include "plankton.h"



Plankton::Plankton(std::shared_ptr<Aquarium> pointer)
{
	aquarPtr = pointer;
	std::pair<int, int> size = aquarPtr->getSize();
	x = std::rand() % size.first;
	y = std::rand() % size.second;
	caloriesForBreeding = 200;
	calories = 10;
}

Plankton::Plankton(int x_, int y_, std::shared_ptr<Aquarium> pointer)
{
	aquarPtr = pointer;
	x = x_;
	y = y_;
	caloriesForBreeding = 30;
	calories = 10;
}


Plankton::~Plankton()
{
}

void Plankton::eat()
{
	calories += 10;
}

std::shared_ptr<Organism> Plankton::breeding()
{
	calories = 20;
	std::shared_ptr<Organism> obj(new Plankton(x, y - 1, aquarPtr));
	aquarPtr->addOrganism(obj);
	return obj;
}

void Plankton::move()
{
	if (rand() % 2 == 1)//движение по горизонтали
	{
		if (rand() % 2 == 1)
			if (aquarPtr->getSize().first < x + 1)
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
			if (aquarPtr->getSize().second < y + 1)
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

void Plankton::live()
{
	if (calories >= caloriesForBreeding)
		std::shared_ptr<Organism> trash = breeding();//пока так, может пригодиться
	else
	{
		eat;
		move;
	}
}
