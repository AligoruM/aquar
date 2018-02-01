#include "plankton.h"


#define PI 3.14159265
#define FRAME 20

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
	moveAngle = rand() % 360;
}

Plankton::Plankton(int x_, int y_, std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres) : Organism(organisms_, parametres)
{
	//std::cout << "constr pointer and cords" << std::endl;
	pos.x = x_;
	pos.y = y_;
	calories = 10;
	sprite.setTexture(para->plankTexture);
	sprite.setPosition(pos.x, pos.y);
	moveAngle = rand() % 360;
}


Plankton::~Plankton()
{
	
}

void Plankton::death()
{
	delete this;
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
	//srand(time(NULL));

	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);

	pos += sf::Vector2f(direction.x * para->plankSpeed, direction.y * para->plankSpeed);

	sprite.setPosition(pos);

	if (pos.x <= 0)
	{
		moveAngle = 0 + rand() % 20 - 10;
	}
	else if (pos.x >= para->sizeX - FRAME)
	{
		moveAngle = 180 + rand() % 20 - 10;
	}
	else if (pos.y <= 0)
	{
		moveAngle = 90 + rand() % 20 - 10;
	}
	else if (pos.y >= para->sizeY - FRAME)
	{
		moveAngle = 270 + rand() % 20 - 10;
	}
	else
	{
		moveAngle += rand() % para->planktonMoveRange - para ->planktonMoveRange / 2;
	}

	if (moveAngle >= 360)
		moveAngle -= 360;
	if (moveAngle < 0)
	{
		moveAngle += 360;
	}




/*	if (rand() % 3 == 1)//движение по вертикали
	{
		if ((rand() % 2) == 1)
		{
			if (para->sizeY < (pos.y + 1))
			{
				sprite.setPosition(pos.x, pos.y + 1);
				pos.y += 1;
			}
		}
		else
		{
			if (pos.y - 1 > 0)
			{
				sprite.setPosition(pos.x, pos.y - 1);
				pos.y -= 1;
			}
		}
	}*/
}

int Plankton::getLifetime()
{
	return lifetime;
}

void Plankton::live()
{
	lifetime++;
	if ((calories >= (para->calForBreeding + (rand()%25)))&&(organisms->size()<para->maxPlankCount))
	{
		breeding();//пока так, может пригодиться
	}
	else
	{
		this->eat();
		this->move();
		/*if (lifetime >= para->plankLifetime)
			death();*/
	}
}

void Plankton::draw(sf::RenderWindow* window)
{
	//std::cout << moveAngle << std::endl;
	window->draw(sprite);
}
