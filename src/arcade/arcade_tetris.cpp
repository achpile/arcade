/***********************************************************************
     * File       : arcade_tetris.cpp
     * Created    : Nov 22, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeTetris
     * constructor

***********************************************************************/
ach::ArcadeTetris::ArcadeTetris() : Arcade("TETЯIS") {
	sndLand    = new sf::SoundBuffer();
	sndLine    = new sf::SoundBuffer();

	sndLand->loadFromFile("data/sfx/arcade/tetris/land.wav");
	sndLine->loadFromFile("data/sfx/arcade/tetris/line.wav");

	border->setPosition(sf::Vector2f(ARCADE_TETRIS_OFFSET_X - 1, ARCADE_OFFSET_Y      - 1));
	border->setSize    (sf::Vector2f(ARCADE_TETRIS_SIZE_X   + 1, ARCADE_BORDER_SIZE_Y + 1));
}



/***********************************************************************
     * ArcadeTetris
     * destructor

***********************************************************************/
ach::ArcadeTetris::~ArcadeTetris() {
	delete sndLand;
	delete sndLine;
}



/***********************************************************************
     * ArcadeTetris
     * initSelf

***********************************************************************/
void ach::ArcadeTetris::initSelf() {
}



/***********************************************************************
     * ArcadeTetris
     * updateSelf

***********************************************************************/
void ach::ArcadeTetris::updateSelf() {
}



/***********************************************************************
     * ArcadeTetris
     * controlsSelf

***********************************************************************/
void ach::ArcadeTetris::controlsSelf() {
}
