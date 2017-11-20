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
	clear      = new sf::SoundBuffer();

	border->setPosition(ARCADE_ARKANOID_OFFSET_X - 1, ARCADE_ARKANOID_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Transparent);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	paddle->setFillColor(sf::Color::Green);
	square->setFillColor(sf::Color::Red  );
	tile->setFillColor  (sf::Color::White);

	labelScore->setPosition(5, 5);

	hitWall->loadFromFile("data/sfx/arcade/arkanoid/wall.wav");
	hitTile->loadFromFile("data/sfx/arcade/arkanoid/tile.wav");
	clear->loadFromFile("data/sfx/arcade/arkanoid/clear.wav");
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
	delete clear;
	delete labelScore;
}



/***********************************************************************
     * ArcadeArkanoid
     * initSelf

***********************************************************************/
void ach::ArcadeArkanoid::initSelf() {
	score = 0;
	lives = 3;

	labelScore->setString("SCORE: " + std::to_string(score));

	create();
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

	drawLives();
	drawPaddle();
	drawSquare();
}



/***********************************************************************
     * ArcadeArkanoid
     * controlsSelf

***********************************************************************/
void ach::ArcadeArkanoid::controlsSelf() {
	if (ctrl->keys[ach::caLeft ].state  ) posX -= frameClock * ARCADE_ARKANOID_SPEED;
	if (ctrl->keys[ach::caRight].state  ) posX += frameClock * ARCADE_ARKANOID_SPEED;
	if (ctrl->keys[ach::caJump ].pressed) shot();

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

	if (!check()) {
		if (lives == 0) gameover();
		else            die();
	}

	finish();
}



/***********************************************************************
     * ArcadeArkanoid
     * shot

***********************************************************************/
void ach::ArcadeArkanoid::shot() {
	if (!glue) return;

	glue  =  false;
	vel.x =  ARCADE_ARKANOID_SPEED * cos(PI / 4);
	vel.y = -ARCADE_ARKANOID_SPEED * sin(PI / 4);
}



/***********************************************************************
     * ArcadeArkanoid
     * die

***********************************************************************/
void ach::ArcadeArkanoid::die() {
	lives--;
	glue  = true;
	sman->play(hit);
}



/***********************************************************************
     * ArcadeArkanoid
     * create

***********************************************************************/
void ach::ArcadeArkanoid::create() {
	posX  = (ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_PADDLE) / 2.0f;
	glue  = true;

	for (int i = 0; i < ARCADE_ARKANOID_X; i++)
		for (int j = 0; j < ARCADE_ARKANOID_Y; j++)
			tiles[i][j] = true;

	move();
}



/***********************************************************************
     * ArcadeArkanoid
     * check

***********************************************************************/
bool ach::ArcadeArkanoid::check() {
	if (pos.x < 0                                              ) {vel.x = -vel.x; pos.x = 0.0f                                           ; sman->play(hitWall);}
	if (pos.x > ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_TILE_Y) {vel.x = -vel.x; pos.x = ARCADE_ARKANOID_SIZE_X - ARCADE_ARKANOID_TILE_Y; sman->play(hitWall);}
	if (pos.y < 0                                              ) {vel.y = -vel.y; pos.y = 0.0f                                           ; sman->play(hitWall);}
	if (pos.y > ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y) return false;

	if (pos.y > ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y * 2.0f)
		collidePaddle();

	collideTiles();

	return true;
}



/***********************************************************************
     * ArcadeArkanoid
     * finish

***********************************************************************/
void ach::ArcadeArkanoid::finish() {
	for (int i = 0; i < ARCADE_ARKANOID_X; i++)
		for (int j = 0; j < ARCADE_ARKANOID_Y; j++)
			if (tiles[i][j])
				return;

	sman->play(clear);
	create();
}



/***********************************************************************
     * ArcadeArkanoid
     * collidePaddle

***********************************************************************/
void ach::ArcadeArkanoid::collidePaddle() {
	if (pos.x < posX - ARCADE_ARKANOID_TILE_Y ||
	    pos.x > posX + ARCADE_ARKANOID_PADDLE) return;

	float angle;
	angle  = 10.0f * ((posX + ARCADE_ARKANOID_PADDLE) - pos.x);
	angle /= (ARCADE_ARKANOID_PADDLE + ARCADE_ARKANOID_TILE_Y);
	angle += 1.0f;
	angle *= (PI / 12.0f);

	pos.y =  ARCADE_ARKANOID_SIZE_Y - ARCADE_ARKANOID_TILE_Y * 2.0f;
	vel.x =  ARCADE_ARKANOID_SPEED * cos(angle);
	vel.y = -ARCADE_ARKANOID_SPEED * sin(angle);

	sman->play(hitWall);
}



/***********************************************************************
     * ArcadeArkanoid
     * collideTiles

***********************************************************************/
void ach::ArcadeArkanoid::collideTiles() {
	sf::Vector2i  to;
	sf::Vector2i  from;

	from.x = floor(pos.x / ARCADE_ARKANOID_TILE_X);
	from.y = floor(pos.y / ARCADE_ARKANOID_TILE_Y);

	to.x = ceil((pos.x + ARCADE_ARKANOID_TILE_Y) / ARCADE_ARKANOID_TILE_X);
	to.y = ceil((pos.y + ARCADE_ARKANOID_TILE_Y) / ARCADE_ARKANOID_TILE_Y);

	if (from.x < 0) from.x = 0;
	if (from.y < 0) from.y = 0;

	if (to.x >= ARCADE_ARKANOID_X) to.x = ARCADE_ARKANOID_X - 1;
	if (to.y >= ARCADE_ARKANOID_Y) to.y = ARCADE_ARKANOID_Y - 1;

	for (int i = from.x; i <= to.x; i++)
		for (int j = from.y; j <= to.y; j++)
			if (tiles[i][j])
				if (collideTile(sf::FloatRect(i * ARCADE_ARKANOID_TILE_X, j * ARCADE_ARKANOID_TILE_Y, ARCADE_ARKANOID_TILE_X, ARCADE_ARKANOID_TILE_Y)))
					tiles[i][j] = false;
}



/***********************************************************************
     * ArcadeArkanoid
     * collideTile

***********************************************************************/
bool ach::ArcadeArkanoid::collideTile(sf::FloatRect rect) {
	sf::FloatRect intersection;
	sf::FloatRect sqr;

	sqr = sf::FloatRect(pos.x, pos.y, ARCADE_ARKANOID_TILE_Y, ARCADE_ARKANOID_TILE_Y);

	if (rect.intersects(sqr, intersection)) {
		if (fabs(intersection.width ) < 0.1f) return false;
		if (fabs(intersection.height) < 0.1f) return false;

		score++;
		sman->play(hitTile);
		labelScore->setString("SCORE: " + std::to_string(score));

		if (fabs(intersection.width) > fabs(intersection.height)) {
			vel.y  = -vel.y;

			if (pos.y < rect.top) pos.y -= fabs(intersection.height);
			else                  pos.y += fabs(intersection.height);
		} else {
			vel.x  = -vel.x;

			if (pos.x < rect.left) pos.y -= fabs(intersection.width);
			else                   pos.y += fabs(intersection.width);
		}

		return true;
	}

	return false;
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
     * drawLives

***********************************************************************/
void ach::ArcadeArkanoid::drawLives() {
	for (unsigned int i = 1; i <= lives; i++) {
		square->setPosition(SCREEN_X - 15 * i, (ARCADE_ARKANOID_OFFSET_Y - ARCADE_ARKANOID_TILE_Y) / 2.0f);
		tex->draw(*square);
	}
}



/***********************************************************************
     * ArcadeArkanoid
     * drawTile

***********************************************************************/
void ach::ArcadeArkanoid::drawTile(int x, int y) {
	tile->setPosition(ARCADE_ARKANOID_OFFSET_X + ARCADE_ARKANOID_TILE_X * x, ARCADE_ARKANOID_OFFSET_Y + ARCADE_ARKANOID_TILE_Y * y);
	tex->draw(*tile);
}
