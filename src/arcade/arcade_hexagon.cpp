/***********************************************************************
     * File       : arcade_hexagon.cpp
     * Created    : Nov 22, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeHexagon
     * constructor

***********************************************************************/
ach::ArcadeHexagon::ArcadeHexagon() : Arcade("HEXAGON") {
	scrTex = new sf::RenderTexture();
	scrSpr = new sf::Sprite();
	center = new sf::CircleShape(ARCADE_HEXAGON_RADIUS, 6);

	scrTex->create(ARCADE_BORDER_SIZE_X, ARCADE_BORDER_SIZE_Y, true);
	scrTex->setRepeated(false);
	scrTex->setActive(true);
	scrTex->setSmooth(false);

	scrSpr->setTexture(scrTex->getTexture());
	scrSpr->setPosition(ARCADE_OFFSET_X, ARCADE_OFFSET_Y);

	center->setOrigin  (ARCADE_HEXAGON_RADIUS   , ARCADE_HEXAGON_RADIUS   );
	center->setPosition(ARCADE_BORDER_SIZE_X / 2, ARCADE_BORDER_SIZE_Y / 2);
	center->setFillColor(sf::Color::Transparent);
	center->setOutlineColor(sf::Color::White);
	center->setOutlineThickness(1);

	ticker.setTimer(1.0f);
}



/***********************************************************************
     * ArcadeHexagon
     * destructor

***********************************************************************/
ach::ArcadeHexagon::~ArcadeHexagon() {
	delete scrTex;
	delete scrSpr;
}



/***********************************************************************
     * ArcadeHexagon
     * initSelf

***********************************************************************/
void ach::ArcadeHexagon::initSelf() {
	rot = 0.0f;
}



/***********************************************************************
     * ArcadeHexagon
     * updateSelf

***********************************************************************/
void ach::ArcadeHexagon::updateSelf() {
	if (!ticker.process()) {
		tick();
		ticker.reset();
	}

	center->setRotation(rot * RAD_TO_DEG);

	scrTex->clear(sf::Color::Transparent);

	scrTex->draw(*center);

	for (int i = 0; i < 6; i++)
		drawLine(i);

	scrTex->display();
	tex->draw(*scrSpr);
}



/***********************************************************************
     * ArcadeHexagon
     * controlsSelf

***********************************************************************/
void ach::ArcadeHexagon::controlsSelf() {
}



/***********************************************************************
     * ArcadeHexagon
     * tick

***********************************************************************/
void ach::ArcadeHexagon::tick() {
	scoreInc();
}



/***********************************************************************
     * ArcadeHexagon
     * drawLine

***********************************************************************/
void ach::ArcadeHexagon::drawLine(int i) {
	line[0].color = sf::Color(100, 100, 100);
	line[1].color = sf::Color(100, 100, 100);

	line[0].position = getPos(2.0f * PI * ((float)i + 0.5f) / 6.0f, ARCADE_HEXAGON_RADIUS);
	line[1].position = getPos(2.0f * PI * ((float)i + 0.5f) / 6.0f, ARCADE_BORDER_SIZE_Y );

	scrTex->draw(line, 2, sf::Lines);
}



/***********************************************************************
     * ArcadeHexagon
     * getPos

***********************************************************************/
sf::Vector2f ach::ArcadeHexagon::getPos(float angle, float radius) {
	return sf::Vector2f(cos(angle + rot), sin(angle + rot)) * radius + sf::Vector2f(ARCADE_BORDER_SIZE_X / 2, ARCADE_BORDER_SIZE_Y / 2);
}
