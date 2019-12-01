/***********************************************************************
     * File       : arcade_spear.cpp
     * Created    : Dec 01, 2019
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeSpear
     * constructor

***********************************************************************/
ach::ArcadeSpear::ArcadeSpear() : Arcade("SPEAR") {
	block = new sf::RectangleShape();

	block->setFillColor(sf::Color::White);
	block->setSize  (sf::Vector2f(ARCADE_SPEAR_BLOCK_SIZE       , ARCADE_SPEAR_BLOCK_SIZE       ));
	block->setOrigin(sf::Vector2f(ARCADE_SPEAR_BLOCK_SIZE / 2.0f, ARCADE_SPEAR_BLOCK_SIZE / 2.0f));

	player[0].color = sf::Color::Green;
	player[1].color = sf::Color::Green;
	player[2].color = sf::Color::Green;

	player[0].position = sf::Vector2f(0.0f, 0.0f);
	player[1].position = sf::Vector2f( ARCADE_SPEAR_PLAYER_SIZE, -ARCADE_SPEAR_PLAYER_SIZE);
	player[2].position = sf::Vector2f(-ARCADE_SPEAR_PLAYER_SIZE, -ARCADE_SPEAR_PLAYER_SIZE);

	transform.translate(sf::Vector2f(ARCADE_OFFSET_X + ARCADE_BORDER_SIZE_X / 2.0f, ARCADE_OFFSET_Y + ARCADE_BORDER_SIZE_Y / 2.0f));
}



/***********************************************************************
     * ArcadeSpear
     * destructor

***********************************************************************/
ach::ArcadeSpear::~ArcadeSpear() {
	delete block;

	enemies.clear();
}



/***********************************************************************
     * ArcadeSpear
     * initSelf

***********************************************************************/
void ach::ArcadeSpear::initSelf() {
	dir = 0;

	enemies.clear();
	ticker.setTimer(0.35f);
}



/***********************************************************************
     * ArcadeSpear
     * updateSelf

***********************************************************************/
void ach::ArcadeSpear::updateSelf() {
	if (!ticker.process()) {
		tick();
		ticker.reset();
	}

	for (unsigned int i = 0; i < enemies.size();) {
		enemies[i].dist -= genSpeed(enemies[i].speed) * ARCADE_SPEAR_SPEED * frameClock;

		if (enemies[i].dist < ARCADE_SPEAR_BLOCK_SIZE * 2.0f && dir == enemies[i].dir) {
			enemies.erase(enemies.begin() + i);
			scoreInc();
			continue;
		} else if (enemies[i].dist < ARCADE_SPEAR_BLOCK_SIZE)
			gameover();

		drawEnemy(enemies[i].dir, enemies[i].dist, enemies[i].speed);
		i++;
	}

	transform.rotate( 90 * dir);
	tex->draw(player, 3, sf::LineStrip, transform);
	transform.rotate(-90 * dir);
}



/***********************************************************************
     * ArcadeSpear
     * controlsSelf

***********************************************************************/
void ach::ArcadeSpear::controlsSelf() {
	if (ctrl->keys[ach::caUp   ].pressed) dir = 0;
	if (ctrl->keys[ach::caDown ].pressed) dir = 2;
	if (ctrl->keys[ach::caLeft ].pressed) dir = 3;
	if (ctrl->keys[ach::caRight].pressed) dir = 1;
}



/***********************************************************************
     * ArcadeSpear
     * tick

***********************************************************************/
void ach::ArcadeSpear::tick() {
	enemies.push_back(ach::ArcadeSpearEnemy(rand() % 4, rand() % 3));
}



/***********************************************************************
     * ArcadeSpear
     * drawEnemy

***********************************************************************/
void ach::ArcadeSpear::drawEnemy(int dir, float dist, int speed) {
	sf::Vector2f offset;

	switch (speed) {
		case 0: block->setFillColor(sf::Color::White); break;
		case 1: block->setFillColor(sf::Color::Cyan ); break;
		case 2: block->setFillColor(sf::Color::Red  ); break;
	}

	switch (dir) {
		case 0: offset = sf::Vector2f( 0.0f, -1.0f); break;
		case 1: offset = sf::Vector2f( 1.0f,  0.0f); break;
		case 2: offset = sf::Vector2f( 0.0f,  1.0f); break;
		case 3: offset = sf::Vector2f(-1.0f,  0.0f); break;
	}

	offset *= dist;
	offset += sf::Vector2f(ARCADE_OFFSET_X + ARCADE_BORDER_SIZE_X / 2.0f, ARCADE_OFFSET_Y + ARCADE_BORDER_SIZE_Y / 2.0f);

	block->setPosition(offset);
	tex->draw(*block);
}



/***********************************************************************
     * ArcadeSpear
     * genSpeed

***********************************************************************/
float ach::ArcadeSpear::genSpeed(int speed) {
	switch (speed) {
		case 0 : return 1.0f;
		case 1 : return 1.4f;
		case 2 : return 1.7f;
		default: return 1.0f;
	}
}
