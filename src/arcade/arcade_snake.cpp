/***********************************************************************
     * File       : arcade_snake.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeSnake
     * constructor

***********************************************************************/
ach::ArcadeSnake::ArcadeSnake() : Arcade("SNAKE") {
	square = new sf::RectangleShape(sf::Vector2f(ARCADE_SNAKE_TILE - 1, ARCADE_SNAKE_TILE - 1));
	border = new sf::RectangleShape(sf::Vector2f(ARCADE_SNAKE_TILE * ARCADE_SNAKE_X + 1, ARCADE_SNAKE_TILE * ARCADE_SNAKE_Y + 1));

	border->setPosition(ARCADE_SNAKE_OFFSET_X - 1, ARCADE_SNAKE_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Black);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	ticker.setTimer(0.2f);
}



/***********************************************************************
     * ArcadeSnake
     * destructor

***********************************************************************/
ach::ArcadeSnake::~ArcadeSnake() {
	delete square;
	delete border;
}



/***********************************************************************
     * ArcadeSnake
     * initSelf

***********************************************************************/
void ach::ArcadeSnake::initSelf() {
}



/***********************************************************************
     * ArcadeSnake
     * updateSelf

***********************************************************************/
void ach::ArcadeSnake::updateSelf() {
	tex->draw(*border);

	if (!ticker.process()) {
		tick();
		ticker.reset();
	}
}



/***********************************************************************
     * ArcadeSnake
     * controlsSelf

***********************************************************************/
void ach::ArcadeSnake::controlsSelf() {
}



/***********************************************************************
     * ArcadeSnake
     * tick

***********************************************************************/
void ach::ArcadeSnake::tick() {
}



/***********************************************************************
     * ArcadeSnake
     * draw

***********************************************************************/
void ach::ArcadeSnake::draw(sf::Vector2i pos, bool red) {
	square->setPosition(ARCADE_SNAKE_OFFSET_X + ARCADE_SNAKE_TILE * pos.x,
	                    ARCADE_SNAKE_OFFSET_X + ARCADE_SNAKE_TILE * pos.y);

	if (red) square->setFillColor(sf::Color::Red);
	else     square->setFillColor(sf::Color::White);

	tex->draw(*square);
}
