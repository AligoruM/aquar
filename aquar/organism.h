#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <random>
#include "parametres.h"
class Organism
{
protected:
	Organism(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres);
	std::vector<std::shared_ptr<Organism>>* organisms;
	int lifetime;
	int calories;
	sf::Vector2i pos;
	sf::Sprite sprite;
	Parametres* para;



	void setPosition(sf::Vector2i pos_);
	sf::Vector2i getPosition();


public:	
	virtual void move() = 0;
	virtual void breeding() = 0;
	virtual void eat() = 0;
	virtual void live() = 0;
	virtual int getLifetime() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};

