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
	shapeUp    = new sf::ConvexShape(4);
	shapeDown  = new sf::ConvexShape(4);
	shapeLeft  = new sf::ConvexShape(4);
	shapeRight = new sf::ConvexShape(4);

	shapeUp->setPoint(0, sf::Vector2f( 45,  10) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeUp->setPoint(1, sf::Vector2f(205,  10) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeUp->setPoint(2, sf::Vector2f(165,  50) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeUp->setPoint(3, sf::Vector2f( 85,  50) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));

	shapeDown->setPoint(0, sf::Vector2f( 45, 190) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeDown->setPoint(1, sf::Vector2f(205, 190) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeDown->setPoint(2, sf::Vector2f(165, 150) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeDown->setPoint(3, sf::Vector2f( 85, 150) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));

	shapeLeft->setPoint(0, sf::Vector2f( 35,  20) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeLeft->setPoint(1, sf::Vector2f( 75,  60) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeLeft->setPoint(2, sf::Vector2f( 75, 140) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeLeft->setPoint(3, sf::Vector2f( 35, 180) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));

	shapeRight->setPoint(0, sf::Vector2f(215,  20) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeRight->setPoint(1, sf::Vector2f(175,  60) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeRight->setPoint(2, sf::Vector2f(175, 140) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));
	shapeRight->setPoint(3, sf::Vector2f(215, 180) + sf::Vector2f(ARCADE_OFFSET_X, ARCADE_OFFSET_Y));

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
	draw(shapeUp   , sf::Color(0, 1, 0), buttons[0] ? 255 : 100);
	draw(shapeDown , sf::Color(0, 0, 1), buttons[1] ? 255 : 100);
	draw(shapeLeft , sf::Color(1, 1, 0), buttons[2] ? 255 : 100);
	draw(shapeRight, sf::Color(1, 0, 0), buttons[3] ? 255 : 100);

	if (!ticker.process())
		tick();
}



/***********************************************************************
     * ArcadeSimon
     * controlsSelf

***********************************************************************/
void ach::ArcadeSimon::controlsSelf() {
	if (state != ach::assInput) return;

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

	pos   = 0;
	len   = 1;
	state = ach::assDemo;

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
	if (dir != seq[pos]) {
		gameover();
		return;
	}

	reset();
	buttons[dir] = true;

	switch (dir) {
		case 0: sman->play(bufUp   ); break;
		case 1: sman->play(bufDown ); break;
		case 2: sman->play(bufLeft ); break;
		case 3: sman->play(bufRight); break;
	}

	ticker.setTimer(0.33f);

	pos++;

	switch (state) {
		case ach::assDemo:
			if (pos == len) {
				pos   = 0;
				state = ach::assInput;
			}

			break;


		case ach::assInput:
			scoreInc();

			if (pos == len) {
				pos   = 0;
				state = ach::assCorrect;
			}

			break;


		default:
			break;
	}
}



/***********************************************************************
     * ArcadeSimon
     * tick

***********************************************************************/
void ach::ArcadeSimon::tick() {
	switch (state) {
		case ach::assDemo:
			state = ach::assPause;
			ticker.setTimer(0.1f);
			reset();
			break;


		case ach::assPause:
			state = ach::assDemo;
			press(seq[pos]);
			break;


		case ach::assInput:
			reset();
			break;


		case ach::assCorrect:
			pos   = 0;
			state = ach::assPause;

			len++;
			ticker.setTimer(0.66f);
			reset();

			if (len > ARCADE_SIMON_SIZE) {
				buttons[0] = true;
				buttons[1] = true;
				buttons[2] = true;
				buttons[3] = true;
				state      = ach::assCreate;

				sman->play(bufCorr);
			}
			break;


		case ach::assCreate:
			create();
			break;
	}
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
