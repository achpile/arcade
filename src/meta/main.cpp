/* *********************************************************************
                                                                        
                       ▄                    ▗▖                          
                      ▐█▌                   ▐▌                          
                      ▐█▌  █▟█▌ ▟██▖ ▟██▖ ▟█▟▌ ▟█▙                      
                      █ █  █▘  ▐▛  ▘ ▘▄▟▌▐▛ ▜▌▐▙▄▟▌                     
                      ███  █   ▐▌   ▗█▀▜▌▐▌ ▐▌▐▛▀▀▘                     
                     ▗█ █▖ █   ▝█▄▄▌▐▙▄█▌▝█▄█▌▝█▄▄▌                     
                     ▝▘ ▝▘ ▀    ▝▀▀  ▀▀▝▘ ▝▀▝▘ ▝▀▀                      
                                                                        
********************************************************************* */
/***********************************************************************
     * File       : main.cpp
     * Created    : Feb 16, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"
#include "globals.hpp"



/***********************************************************************
     * createWindow

***********************************************************************/
static void createWindow() {
	app->create(sf::VideoMode(SCREEN_X, SCREEN_Y, 32), PROJECT_CAPTION, sf::Style::Default);
	app->setFramerateLimit(60);
	app->setMouseCursorVisible(false);

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i  offset;

	offset.x = (desktop.width  - SCREEN_X) / 2;
	offset.y = (desktop.height - SCREEN_Y) / 2;

	if (offset.x > 0 && offset.y > 0)
		app->setPosition(offset);
}



/***********************************************************************
     * Main function

***********************************************************************/
int main() {
	ach::Arcade *arcade;
	sf::Event    event;
	long         lastClock;
	long         currentClock;

	srand(time(NULL));

	font   = new sf::Font();
	font->loadFromFile("data/fonts/FSEX300.ttf");

	app    = new sf::RenderWindow();
	Clock  = new sf::Clock;
	ctrl   = new ach::ControlPad();
	arcade = new ach::ArcadeSnake();

	createWindow();

	while(app->isOpen()) {
		currentClock = Clock->getElapsedTime().asMilliseconds();
		frameClock   = (currentClock - lastClock) / 1000.0;
		lastClock    = currentClock;

		while (app->pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					app->close();
					break;

				case sf::Event::Resized:
					app->setView(sf::View(sf::FloatRect(0, 0, SCREEN_X, SCREEN_Y)));
					break;

				default: break;
			}
		}

		app->clear();
		ctrl->update();
		arcade->update();
		app->display();

		if (!arcade->running) app->close();
	}

	delete app;
	delete Clock;
	delete ctrl;
	delete arcade;
	delete font;

	return EXIT_SUCCESS;
}
