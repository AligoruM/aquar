#include "plankton.h"



/*Plankton::Plankton()
{
	aquarPtr = nullptr;
	x = 1;
	y = 1;
	calories = 10;
}*/

Plankton::Plankton(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres) : Organism(organisms_, parametres)
{
	//std::cout << "constr pointer" << std::endl;
	pos.x = std::rand() % para->sizeX;
	pos.y = std::rand() % para->sizeY;
	calories = 10;
	sprite.setTexture(para->plankTexture);
	sprite.setPosition(pos.x, pos.y);
}

Plankton::Plankton(int x_, int y_, std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres) : Organism(organisms_, parametres)
{
	//std::cout << "constr pointer and cords" << std::endl;
	pos.x = x_;
	pos.y = y_;
	calories = 10;
	sprite.setTexture(para->plankTexture);
	sprite.setPosition(pos.x, pos.y);
}


Plankton::~Plankton()
{
	
}

void Plankton::eat()
{
	//std::cout << "eat" << std::endl;
	calories += para->plankCal;
}

void Plankton::breeding()
{
	//std::cout << "breed" << std::endl;

	calories = 20;
	std::shared_ptr<Organism> obj(new Plankton(pos.x, pos.y - 1, organisms, para));
	organisms->push_back(obj);
}

void Plankton::move()
{
	//std::cout << "move" << std::endl;
	if (rand() % 2 == 1)//движение по горизонтали
	{
		if (rand() % 2 == 1)
			if (para->sizeX < pos.x + 1)
			{
				sprite.setPosition(pos.x + 1, pos.y);
				pos.x += 1;
			}
			else
			{
				sprite.setPosition(pos.x - 1, pos.y);
				pos.x -= 1;
			}
		else
			if (pos.x - 1 > 0)
			{
				sprite.setPosition(pos.x - 1, pos.y);
				pos.x -= 1;
			}
			else
			{
				sprite.setPosition(pos.x + 1, pos.y);
				pos.x += 1;
			}
	}
	if (rand() % 3 == 1)//движение по вертикали
	{
		if (rand() % 2 == 1)
			if (para->sizeY < pos.y + 1)
			{
				sprite.setPosition(pos.x, pos.y +1);
				pos.y += 1;
			}
			else
			{
				sprite.setPosition(pos.x, pos.y - 1);
				pos.y -= 1;
			}
		else
			if (pos.y - 1 > 0)
			{
				sprite.setPosition(pos.x, pos.y-1);
				pos.y -= 1;
			}
			else
			{
				sprite.setPosition(pos.x, pos.y+1);
				pos.y += 1;
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
		breeding();//пока так, может пригодиться
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
