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
	float multiplier=1.1f;
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
	mikeSprite.setScale(0.1f,0.1f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
		frameTime=clock.getElapsedTime().asSeconds();
		
		
		if((frameTime)>=FRAME_RATE)
		{
			clock.restart();
			frameCount++;
			
			if(frameCount%5==0) {
			
				mikeSprite.scale(multiplier,multiplier);
			}
			sf::Vector2f scaleVector=mikeSprite.getScale();
			
			if(scaleVector.x>=5.0f) {
				multiplier=0.9;
			}
			if(scaleVector.x<0.1) {
				multiplier=1.1;
			}

			window.clear();
			window.draw(mikeSprite);
			window.display();
		}
		
    }

    return 0;
}

