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
ach::Arcade::Arcade(std::string caption) {
	state         = ach::asStart;
	running       = true;
	tex           = new sf::RenderTexture();
	spr           = new sf::Sprite();
	blip          = new sf::SoundBuffer();
	hit           = new sf::SoundBuffer();
	square        = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_TILE_Y - 1, ARCADE_ARKANOID_TILE_Y - 1));
	border        = new sf::RectangleShape(sf::Vector2f(ARCADE_ARKANOID_SIZE_X + 1, ARCADE_ARKANOID_SIZE_Y + 1));
	labelScore    = new sf::Text("SCORE: 0"          , *font, 30);
	labelCaption  = new sf::Text(caption             , *font, 48);
	labelStart    = new sf::Text("press start button", *font, 24);
	labelGameover = new sf::Text("GAME OVER"         , *font, 50);

	tex->create(SCREEN_X, SCREEN_Y, true);
	tex->setRepeated(false);
	tex->setActive(true);
	tex->setSmooth(false);

	spr->setTexture(tex->getTexture());

	border->setPosition(ARCADE_OFFSET_X - 1, ARCADE_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Transparent);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	blip->loadFromFile("data/sfx/arcade/blip.wav");
	hit->loadFromFile("data/sfx/arcade/hit.wav");

	labelCaption->setPosition ((int)((SCREEN_X - labelCaption->getGlobalBounds ().width) / 2),  50);
	labelStart->setPosition   ((int)((SCREEN_X - labelStart->getGlobalBounds   ().width) / 2), 200);
	labelGameover->setPosition((int)((SCREEN_X - labelGameover->getGlobalBounds().width) / 2),  80);
	labelScore->setPosition   (5, 5);

	pulse.setPulse(1.0f);
}



/***********************************************************************
     * Arcade
     * destructor

***********************************************************************/
ach::Arcade::~Arcade() {
	delete spr;
	delete tex;
	delete blip;
	delete hit;
	delete square;
	delete border;

	delete labelScore;
	delete labelCaption;
	delete labelStart;
	delete labelGameover;
}



/***********************************************************************
     * Arcade
     * update

***********************************************************************/
void ach::Arcade::update() {
	tex->clear(sf::Color::Transparent);
	pulse.process();

	controls();

	switch (state) {
		case ach::asStart:
			tex->draw(*labelCaption);
			if (pulse.status) tex->draw(*labelStart);
			break;

		case ach::asGameOver:
			if (pulse.status) tex->draw(*labelGameover);
			break;

		case ach::asGame:
			tex->draw(*labelScore);
			tex->draw(*border);
			updateSelf();
			break;
	}

	render();
}



/***********************************************************************
     * Arcade
     * render

***********************************************************************/
void ach::Arcade::render() {
	tex->display();
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
	sman->play(blip);
	scoreReset();
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
	sman->play(blip);
	pulse.setPulse(1.0f);
}



/***********************************************************************
     * Arcade
     * gameover

***********************************************************************/
void ach::Arcade::gameover() {
	state = ach::asGameOver;
	sman->play(hit);
	pulse.setPulse(1.0f);
}



/***********************************************************************
     * Arcade
     * scoreInc

***********************************************************************/
void ach::Arcade::scoreInc() {
	score++;
	scoreUpdate();
}



/***********************************************************************
     * Arcade
     * scoreReset

***********************************************************************/
void ach::Arcade::scoreReset() {
	score = 0;
	scoreUpdate();
}



/***********************************************************************
     * Arcade
     * scoreUpdate

***********************************************************************/
void ach::Arcade::scoreUpdate() {
	labelScore->setString("SCORE: " + std::to_string(score));
}
