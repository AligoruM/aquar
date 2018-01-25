#pragma once
struct Parametres
{
public:
	//plankton
	int plankLifetime = 50;
	int calForBreeding = 40;
	int plankViewDist = 0;
	int plankBreedingCD = 20;
	int plankCal = 1;
	sf::Texture plankTexture;
	//fish

	//aquarium
	int sizeX = 800;
	int sizeY = 600;
};