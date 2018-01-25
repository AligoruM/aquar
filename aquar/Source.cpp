#include "aquarium.h"


void main()
{
	Parametres* para = new Parametres;
	para->plankTexture.loadFromFile("C:/Users/Admin/Documents/GitHub/aquar/aquar/res/Plankton.png");
	Aquarium aqua = Aquarium(10,para);
	


	aqua.fillAqua(10);
	aqua.tick();
}