#include "Intro.h"

int main()
{
    Intro intro;
    intro.initIntro();

	while (intro.getPlaying())
	{
		intro.mainMenu();
	}
	
	return 0;
}