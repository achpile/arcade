/***********************************************************************
     * File       : arcade_arkanoid.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeArkanoid
     * constructor

***********************************************************************/
ach::ArcadeArkanoid::ArcadeArkanoid() : Arcade("ARKANOID") {
	score      = 0;
	pos        = (ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE) / 2.0f;
	tile       = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_TILE_X - 1, ARCADE_ARKANOID_TILE_Y - 1));
	paddle     = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_PADDLE - 1, ARCADE_ARKANOID_TILE_Y - 1));
	square     = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_TILE_Y - 1, ARCADE_ARKANOID_TILE_Y - 1));
	border     = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_SIZE_X + 1, ARCADE_ARKANOID_SIZE_Y + 1));
	labelScore = new sf::Text("SCORE: 0", *font, 30);
	hitWall    = new sf::SoundBuffer();
	hitTile    = new sf::SoundBuffer();

	border->setPosition(ARCADE_SNAKE_OFFSET_X - 1, ARCADE_SNAKE_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Black);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	paddle->setFillColor(sf::Color::Green);
	square->setFillColor(sf::Color::Red  );
	tile->setFillColor  (sf::Color::White);

	labelScore->setPosition(5, 5);

	hitWall->loadFromFile("data/sfx/arcade/arkanoid/wall.wav");
	hitTile->loadFromFile("data/sfx/arcade/arkanoid/tile.wav");
}



/***********************************************************************
     * ArcadeArkanoid
     * destructor

***********************************************************************/
ach::ArcadeArkanoid::~ArcadeArkanoid() {
	delete square;
	delete border;
	delete tile;
	delete paddle;
	delete hitWall;
	delete hitTile;
	delete labelScore;
}



/***********************************************************************
     * ArcadeArkanoid
     * initSelf

***********************************************************************/
void ach::ArcadeArkanoid::initSelf() {
}



/***********************************************************************
     * ArcadeArkanoid
     * updateSelf

***********************************************************************/
void ach::ArcadeArkanoid::updateSelf() {
	tex->draw(*labelScore);
	tex->draw(*border);

	paddle->setPosition(pos + ARCADE_ARKANOID_OFFSET_X, ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y + ARCADE_ARKANOID_OFFSET_Y);
	tex->draw(*paddle);
}



/***********************************************************************
     * ArcadeArkanoid
     * controlsSelf

***********************************************************************/
void ach::ArcadeArkanoid::controlsSelf() {
	if (ctrl->keys[ach::caLeft ].state) pos -= frameClock * ARCADE_ARKANOID_SPEED;
	if (ctrl->keys[ach::caRight].state) pos += frameClock * ARCADE_ARKANOID_SPEED;

	if (pos < 0.0f                                           ) pos = 0.0f;
	if (pos > ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE) pos = ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE;
}



/***********************************************************************
     * ArcadeArkanoid
     * move

***********************************************************************/
void ach::ArcadeArkanoid::move() {
}



/***********************************************************************
     * ArcadeArkanoid
     * check

***********************************************************************/
bool ach::ArcadeArkanoid::check() {
	return true;
}
