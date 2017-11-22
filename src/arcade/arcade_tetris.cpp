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
