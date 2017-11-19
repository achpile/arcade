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

	ticker.setTimer(0.1f);
}



/***********************************************************************
     * ArcadeSimon
     * destructor

***********************************************************************/
ach::ArcadeSimon::~ArcadeSimon() {
	delete border;
	delete labelScore;
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
