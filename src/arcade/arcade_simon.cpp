/***********************************************************************
     * File       : arcade_simon.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeSimon
     * constructor

***********************************************************************/
ach::ArcadeSimon::ArcadeSimon() : Arcade("SIMON SAYS") {
	score      = 0;
	border     = new sf::RectangleShape(sf::Vector2f(ARCADE_SIMON_SIZE_X + 1, ARCADE_SIMON_SIZE_Y + 1));
	labelScore = new sf::Text("SCORE: 0", *font, 30);

	border->setPosition(ARCADE_SIMON_OFFSET_X - 1, ARCADE_SIMON_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Black);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	labelScore->setPosition(5, 5);

	shapeUp    = new sf::ConvexShape(4);
	shapeDown  = new sf::ConvexShape(4);
	shapeLeft  = new sf::ConvexShape(4);
	shapeRight = new sf::ConvexShape(4);

	shapeUp->setPoint(0, sf::Vector2f( 45,  10) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeUp->setPoint(1, sf::Vector2f(205,  10) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeUp->setPoint(2, sf::Vector2f(165,  50) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeUp->setPoint(3, sf::Vector2f( 85,  50) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));

	shapeDown->setPoint(0, sf::Vector2f( 45, 190) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeDown->setPoint(1, sf::Vector2f(205, 190) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeDown->setPoint(2, sf::Vector2f(165, 150) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeDown->setPoint(3, sf::Vector2f( 85, 150) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));

	shapeLeft->setPoint(0, sf::Vector2f( 35,  20) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeLeft->setPoint(1, sf::Vector2f( 75,  60) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeLeft->setPoint(2, sf::Vector2f( 75, 140) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeLeft->setPoint(3, sf::Vector2f( 35, 180) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));

	shapeRight->setPoint(0, sf::Vector2f(215,  20) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeRight->setPoint(1, sf::Vector2f(175,  60) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeRight->setPoint(2, sf::Vector2f(175, 140) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));
	shapeRight->setPoint(3, sf::Vector2f(215, 180) + sf::Vector2f(ARCADE_SIMON_OFFSET_X, ARCADE_SIMON_OFFSET_Y));

	shapeUp->setOutlineColor(sf::Color::White);
	shapeDown->setOutlineColor(sf::Color::White);
	shapeLeft->setOutlineColor(sf::Color::White);
	shapeRight->setOutlineColor(sf::Color::White);

	bufUp    = new sf::SoundBuffer();
	bufDown  = new sf::SoundBuffer();
	bufLeft  = new sf::SoundBuffer();
	bufRight = new sf::SoundBuffer();
	bufCorr  = new sf::SoundBuffer();

	bufUp->loadFromFile("data/sfx/arcade/simon/up.wav");
	bufDown->loadFromFile("data/sfx/arcade/simon/down.wav");
	bufLeft->loadFromFile("data/sfx/arcade/simon/left.wav");
	bufRight->loadFromFile("data/sfx/arcade/simon/right.wav");
	bufCorr->loadFromFile("data/sfx/arcade/simon/correct.wav");

	ticker.setTimer(0.33f);
}



/***********************************************************************
     * ArcadeSimon
     * destructor

***********************************************************************/
ach::ArcadeSimon::~ArcadeSimon() {
	delete border;
	delete labelScore;

	delete shapeUp;
	delete shapeDown;
	delete shapeLeft;
	delete shapeRight;

	delete bufUp;
	delete bufDown;
	delete bufLeft;
	delete bufRight;
	delete bufCorr;
}



/***********************************************************************
     * ArcadeSimon
     * initSelf

***********************************************************************/
void ach::ArcadeSimon::initSelf() {
	create();
}



/***********************************************************************
     * ArcadeSimon
     * updateSelf

***********************************************************************/
void ach::ArcadeSimon::updateSelf() {
	tex->draw(*labelScore);
	tex->draw(*border);

	draw(shapeUp   , sf::Color(0, 1, 0), buttons[0] ? 255 : 100);
	draw(shapeDown , sf::Color(0, 0, 1), buttons[1] ? 255 : 100);
	draw(shapeLeft , sf::Color(1, 1, 0), buttons[2] ? 255 : 100);
	draw(shapeRight, sf::Color(1, 0, 0), buttons[3] ? 255 : 100);

	if (!ticker.process()) {
		reset();

		if (demo) press(seq[pos]);
	}
}



/***********************************************************************
     * ArcadeSimon
     * controlsSelf

***********************************************************************/
void ach::ArcadeSimon::controlsSelf() {
	if (ticker.isActive()) return;
	if (demo             ) return;

	if (ctrl->keys[ach::caUp   ].pressed) press(0);
	if (ctrl->keys[ach::caDown ].pressed) press(1);
	if (ctrl->keys[ach::caLeft ].pressed) press(2);
	if (ctrl->keys[ach::caRight].pressed) press(3);
}



/***********************************************************************
     * ArcadeSimon
     * create

***********************************************************************/
void ach::ArcadeSimon::create() {
	for (int i = 0; i < ARCADE_SIMON_SIZE; i++)
		seq[i] = rand() % 4;

	pos  = 0;
	len  = 1;
	demo = true;

	reset();
}



/***********************************************************************
     * ArcadeSimon
     * reset

***********************************************************************/
void ach::ArcadeSimon::reset() {
	buttons[0] = false;
	buttons[1] = false;
	buttons[2] = false;
	buttons[3] = false;
}



/***********************************************************************
     * ArcadeSimon
     * press

***********************************************************************/
void ach::ArcadeSimon::press(int dir) {
	buttons[dir] = true;

	switch (dir) {
		case 0: sman->play(bufUp   ); break;
		case 1: sman->play(bufDown ); break;
		case 2: sman->play(bufLeft ); break;
		case 3: sman->play(bufRight); break;
	}

	ticker.setTimer(0.33f);

	pos++;

	if (pos == len) {
		pos = 0;

		if (demo) {
			demo = false;
		} else {
			demo = true;
			len++;

			if (len == ARCADE_SIMON_SIZE)
				create();
		}
	}
}



/***********************************************************************
     * ArcadeSimon
     * tick

***********************************************************************/
void ach::ArcadeSimon::tick() {
}



/***********************************************************************
     * ArcadeSimon
     * draw

***********************************************************************/
void ach::ArcadeSimon::draw(sf::ConvexShape *shape, sf::Color c, int value) {
	shape->setFillColor(sf::Color(c.r * value, c.g * value, c.b * value));

	if (value == 255) shape->setOutlineThickness(1.0f);
	else              shape->setOutlineThickness(0.0f);

	tex->draw(*shape);
}
