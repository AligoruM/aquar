#include "aquarium.h"


void main()
{
	Parametres* para = new Parametres;
	Aquarium aqua = Aquarium(10,para);

	aqua.fillAqua(10);
	aqua.tick();
}