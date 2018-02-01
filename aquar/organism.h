#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include "parametres.h"
#include <windows.h>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <exception>
#include <time.h>

class Organism
{
protected:
	Organism(std::vector<std::shared_ptr<Organism>>* organisms_, Parametres* parametres);
	virtual ~Organism();
	std::vector<std::shared_ptr<Organism>>* organisms;
	int lifetime;
	int calories;
	sf::Vector2f pos;
	float moveAngle;
	sf::Vector2f direction;
	sf::Sprite sprite;
	Parametres* para;
	
	void setPosition(sf::Vector2f pos_);
	sf::Vector2f getPosition();

public:
	virtual void death() = 0;
	virtual void move() = 0;
	virtual void breeding() = 0;
	virtual void eat() = 0;
	virtual void live() = 0;
	virtual int getLifetime() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};

