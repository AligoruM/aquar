#pragma once
struct Parametres
{
public:
	//plankton
	int plankLifetime = 60;
	int calForBreeding = 30;
	int plankViewDist = 0;
	int plankBreedingCD = 20;
	int plankCal = 1;
	int planktonMoveRange = 20;
	float plankSpeed = 2;
	sf::Texture plankTexture;
	//fish

	//aquarium
	int sizeX = 800;
	int sizeY = 600;
	int maxPlankCount = 100;
};