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
}



/***********************************************************************
     * ArcadeArkanoid
     * controlsSelf

***********************************************************************/
void ach::ArcadeArkanoid::controlsSelf() {
//	if (ctrl->keys[ach::caLeft ].pressed) dir = sf::Vector2i(-1,  0);
//	if (ctrl->keys[ach::caRight].pressed) dir = sf::Vector2i( 1,  0);
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
