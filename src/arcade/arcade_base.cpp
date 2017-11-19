/***********************************************************************
     * File       : arcade_base.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Arcade
     * constructor

***********************************************************************/
ach::Arcade::Arcade() {
	tex = new sf::RenderTexture();
	spr = new sf::Sprite();

	tex->create(SCREEN_X, SCREEN_Y, true);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(false);

	spr->setTexture(tex->getTexture());
}



/***********************************************************************
     * Arcade
     * destructor

***********************************************************************/
ach::Arcade::~Arcade() {
	delete spr;
	delete tex;
}



/***********************************************************************
     * Arcade
     * update

***********************************************************************/
void ach::Arcade::update() {
	tex->clear(sf::Color::Black);

	render();
}



/***********************************************************************
     * Arcade
     * render

***********************************************************************/
void ach::Arcade::render() {
	app->draw(*spr);
}
