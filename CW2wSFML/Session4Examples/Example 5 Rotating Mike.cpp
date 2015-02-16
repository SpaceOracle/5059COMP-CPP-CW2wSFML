// ConsoleApplicatioSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace  std;



const int HEIGHT=800;
const int WIDTH=800;
const float FRAME_RATE=1.0f/24.0f;




int _tmain(int argc, _TCHAR* argv[])
{
	float elapsedTime=0.0;
	float frameTime=0.0;
	int frameCount=0;
	int red=255;
	sf::Clock clock;
	sf::Time time;

    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");
    
    
	sf::Texture mikeTexture;
	sf::Sprite mikeSprite;

	if(!mikeTexture.loadFromFile("mikeTile.png"))
	{
		cout << "Error loading Mike" << endl;
	}
	
	mikeSprite.setTexture(mikeTexture);
	mikeSprite.setPosition(WIDTH/2,HEIGHT/2);
	mikeSprite.setOrigin(32,32);
	mikeSprite.setRotation(180);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
		time=clock.getElapsedTime();
		frameTime=time.asMilliseconds();
		if((frameTime-elapsedTime)>=FRAME_RATE)
		{
			frameCount++;
			if(frameCount%10==0) {
				mikeSprite.rotate(1);
			}
			window.clear();
			window.draw(mikeSprite);
			window.display();
		}
		elapsedTime=frameTime;
    }

    return 0;
}

