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

	//Set to tile, if not, weird stretch occurs outside actual image size
	//Then produce a sprite and give it a geometric shape (position X,Y + width/height)
	mikeTexture.setRepeated(true);
	mikeSprite.setTexture(mikeTexture);
	mikeSprite.setTextureRect(sf::IntRect(0,0,800,800));

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

		//Translation animation - really necessary for example?

		if((frameTime-elapsedTime)>=FRAME_RATE)
		{
			frameCount++;
			/*if(frameCount%5==0) {
				sf::Vector2f mikeVector=mikeSprite.getPosition();
				if(mikeVector.x>WIDTH){
					yPos+=10;
					mikeSprite.setPosition(0,yPos);
				}
				else {
					mikeSprite.move(1,0);
				}
			}*/
			window.clear();
			window.draw(mikeSprite);
			window.display();
		}

		elapsedTime=frameTime;
    }

    return 0;
}

