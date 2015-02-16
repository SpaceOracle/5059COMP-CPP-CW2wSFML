// ConsoleApplicatioSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace  std;

const int HEIGHT=800;
const int WIDTH=800;

int _tmain(int argc, _TCHAR* argv[])
{
	
	//PrintFullPath( ".\\" );

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

        window.clear();
		window.draw(mikeSprite);
        window.display();
    }

    return 0;
}

