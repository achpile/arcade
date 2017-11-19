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
	state   = ach::asStart;
	running = true;
	tex     = new sf::RenderTexture();
	spr     = new sf::Sprite();

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

	controls();
	render();
}



/***********************************************************************
     * Arcade
     * render

***********************************************************************/
void ach::Arcade::render() {
	app->draw(*spr);
}



/***********************************************************************
     * Arcade
     * controls

***********************************************************************/
void ach::Arcade::controls() {
	switch (state) {
		case ach::asStart:
			if      (ctrl->keys[ach::caJump].pressed) init();
			else if (ctrl->keys[ach::caMenu].pressed) quit();
			break;

		case ach::asGameOver:
			if      (ctrl->keys[ach::caJump].pressed) reset();
			else if (ctrl->keys[ach::caMenu].pressed) quit();
			break;

		case ach::asGame:
			if   (ctrl->keys[ach::caMenu].pressed) reset();
			else controlsSelf();
			break;

	}
}



/***********************************************************************
     * Arcade
     * init

***********************************************************************/
void ach::Arcade::init() {
	state = ach::asGame;

	initSelf();
}



/***********************************************************************
     * Arcade
     * quit

***********************************************************************/
void ach::Arcade::quit() {
	running = false;
}



/***********************************************************************
     * Arcade
     * reset

***********************************************************************/
void ach::Arcade::reset() {
	state = ach::asStart;
}



/***********************************************************************
     * Arcade
     * gameover

***********************************************************************/
void ach::Arcade::gameover() {
	state = ach::asGameOver;
}
