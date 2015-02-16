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
	bool order=true;

	sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");
    sf::CircleShape bigCircle(200);
	sf::CircleShape mediumCircle(100);
	sf::CircleShape smallCircle(50);

    bigCircle.setFillColor(sf::Color(255,0,0));
	mediumCircle.setFillColor(sf::Color(0,255,0));
	smallCircle.setFillColor(sf::Color(0,0,255));

	bigCircle.setPosition(WIDTH/2,HEIGHT/2);
	mediumCircle.setPosition(WIDTH/2,HEIGHT/2);
	smallCircle.setPosition(WIDTH/2,HEIGHT/2);
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
		sf::Time time=clock.getElapsedTime();
		if(time.asSeconds()>5) {
			order=!order;
			clock.restart();
		}
		window.clear();
		if(order) {
			window.draw(bigCircle);
			window.draw(mediumCircle);
			window.draw(smallCircle);
		}
		else {
			window.draw(smallCircle);
			window.draw(mediumCircle);
			window.draw(bigCircle);
		}
		window.display();
		
		
    }

    return 0;
}

