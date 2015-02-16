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
	float yPos=0.0f;
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
			if(frameCount%5==0) {
				sf::Vector2f mikeVector=mikeSprite.getPosition();
				
				//If not off the right side of screen, move a pixel to the right
				//If so, move him down ten pixels and reset to 0 on the x axis
				
				if(mikeVector.x>WIDTH){
					yPos+=10;
					mikeSprite.setPosition(0,yPos);
				}
				else {
					mikeSprite.move(1,0);
				}
			}
			window.clear();
			window.draw(mikeSprite);
			window.display();
		}
		elapsedTime=frameTime;
    }

    return 0;
}

