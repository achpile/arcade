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
	posX = (ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE) / 2.0f;
	glue = true;

	for (int i = 0; i < ARCADE_ARKANOID_X; i++)
		for (int j = 0; j < ARCADE_ARKANOID_Y; j++)
			tiles[i][j] = true;

	move();
}



/***********************************************************************
     * ArcadeArkanoid
     * updateSelf

***********************************************************************/
void ach::ArcadeArkanoid::updateSelf() {
	tex->draw(*labelScore);
	tex->draw(*border);

	move();

	for (int i = 0; i < ARCADE_ARKANOID_X; i++)
		for (int j = 0; j < ARCADE_ARKANOID_Y; j++)
			if (tiles[i][j])
				drawTile(i, j);

	drawPaddle();
	drawSquare();
}



/***********************************************************************
     * ArcadeArkanoid
     * controlsSelf

***********************************************************************/
void ach::ArcadeArkanoid::controlsSelf() {
	if (ctrl->keys[ach::caLeft ].state) posX -= frameClock * ARCADE_ARKANOID_SPEED;
	if (ctrl->keys[ach::caRight].state) posX += frameClock * ARCADE_ARKANOID_SPEED;

	if (posX < 0.0f                                           ) posX = 0.0f;
	if (posX > ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE) posX = ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE;
}



/***********************************************************************
     * ArcadeArkanoid
     * move

***********************************************************************/
void ach::ArcadeArkanoid::move() {
	if (glue) {
		pos.x = posX + (ARCADE_ARKANOID_PADDLE - ARCADE_ARKANOID_TILE_Y) / 2.0f;
		pos.y = ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y * 2.0f;
	} else {
		pos += vel * frameClock;
	}
}



/***********************************************************************
     * ArcadeArkanoid
     * check

***********************************************************************/
bool ach::ArcadeArkanoid::check() {
	return true;
}



/***********************************************************************
     * ArcadeArkanoid
     * drawPaddle

***********************************************************************/
void ach::ArcadeArkanoid::drawPaddle() {
	paddle->setPosition(posX + ARCADE_ARKANOID_OFFSET_X, ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y + ARCADE_ARKANOID_OFFSET_Y);
	tex->draw(*paddle);
}



/***********************************************************************
     * ArcadeArkanoid
     * drawSquare

***********************************************************************/
void ach::ArcadeArkanoid::drawSquare() {
	square->setPosition(pos.x + ARCADE_ARKANOID_OFFSET_X, pos.y + ARCADE_ARKANOID_OFFSET_Y);
	tex->draw(*square);
}



/***********************************************************************
     * ArcadeArkanoid
     * drawTile

***********************************************************************/
void ach::ArcadeArkanoid::drawTile(int x, int y) {
	tile->setPosition(ARCADE_ARKANOID_OFFSET_X + ARCADE_ARKANOID_TILE_X * x, ARCADE_ARKANOID_OFFSET_Y + ARCADE_ARKANOID_TILE_Y * y);
	tex->draw(*tile);
}
