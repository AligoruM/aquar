#include "aquarium.h"


void main()
{
	std::srand(time(NULL));

	Parametres* para = new Parametres;
	para->plankTexture.loadFromFile("C:/Users/Aligor/Source/Repos/aquar/aquar/res/Plankton.png");
	Aquarium aqua = Aquarium(para);
	


	aqua.fillAqua(10);
	aqua.tick();
}