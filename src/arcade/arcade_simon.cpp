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

	ticker.setTimer(0.1f);
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
}



/***********************************************************************
     * ArcadeSimon
     * initSelf

***********************************************************************/
void ach::ArcadeSimon::initSelf() {
}



/***********************************************************************
     * ArcadeSimon
     * updateSelf

***********************************************************************/
void ach::ArcadeSimon::updateSelf() {
	tex->draw(*labelScore);
	tex->draw(*border);

	draw(shapeUp   , sf::Color(0, 1, 0), 100);
	draw(shapeDown , sf::Color(0, 0, 1), 100);
	draw(shapeLeft , sf::Color(1, 1, 0), 100);
	draw(shapeRight, sf::Color(1, 0, 0), 100);

	if (!ticker.process()) {
		tick();
		ticker.reset();
	}
}



/***********************************************************************
     * ArcadeSimon
     * controlsSelf

***********************************************************************/
void ach::ArcadeSimon::controlsSelf() {
	//if (ctrl->keys[ach::caLeft ].pressed) dir = sf::Vector2i(-1,  0);
	//if (ctrl->keys[ach::caRight].pressed) dir = sf::Vector2i( 1,  0);
	//if (ctrl->keys[ach::caUp   ].pressed) dir = sf::Vector2i( 0, -1);
	//if (ctrl->keys[ach::caDown ].pressed) dir = sf::Vector2i( 0,  1);
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
