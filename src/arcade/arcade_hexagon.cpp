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
	player = new sf::CircleShape(2);
	shape  = new sf::ConvexShape(4);

	scrTex->create(ARCADE_BORDER_SIZE_X, ARCADE_BORDER_SIZE_Y, true);
	scrTex->setRepeated(false);
	scrTex->setActive(true);
	scrTex->setSmooth(false);

	scrSpr->setTexture(scrTex->getTexture());
	scrSpr->setPosition(ARCADE_OFFSET_X, ARCADE_OFFSET_Y);

	player->setOrigin(2, 2);
	player->setFillColor(sf::Color::Green);

	center->setOrigin  (ARCADE_HEXAGON_RADIUS   , ARCADE_HEXAGON_RADIUS   );
	center->setPosition(ARCADE_BORDER_SIZE_X / 2, ARCADE_BORDER_SIZE_Y / 2);
	center->setFillColor(sf::Color::Transparent);
	center->setOutlineColor(sf::Color::White);
	center->setOutlineThickness(1);

	line[0].color = sf::Color(100, 100, 100);
	line[1].color = sf::Color(100, 100, 100);

	shape->setFillColor(sf::Color::White);

	ticker.setTimer(1.0f);
}



/***********************************************************************
     * ArcadeHexagon
     * destructor

***********************************************************************/
ach::ArcadeHexagon::~ArcadeHexagon() {
	delete scrTex;
	delete scrSpr;
	delete center;
	delete player;
	delete shape;
}



/***********************************************************************
     * ArcadeHexagon
     * initSelf

***********************************************************************/
void ach::ArcadeHexagon::initSelf() {
	rot      = 0.0f;
	rotSpeed = 1;
	pos      = PI / 3.0f;

	create();
	createRotor();
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

	if (!rotor.process())
		createRotor();

	if (collide(pos))
		gameover();

	rot += rotSpeed * frameClock;

	center->setRotation((rot + PI / 6.0f) * RAD_TO_DEG);

	for (int i = 0; i < 6; i++)
		sectors[i] -= ARCADE_HEXAGON_SPEED * frameClock;

	if (!check())
		create();


	scrTex->clear(sf::Color::Transparent);
	scrTex->draw(*center);

	for (int i = 0; i < 6; i++)
		drawLine(i);

	for (int i = 0; i < 6; i++)
		drawShape(i, sectors[i]);

	player->setPosition(getPos(pos, ARCADE_HEXAGON_OFFSET));
	scrTex->draw(*player);

	scrTex->display();
	tex->draw(*scrSpr);
}



/***********************************************************************
     * ArcadeHexagon
     * controlsSelf

***********************************************************************/
void ach::ArcadeHexagon::controlsSelf() {
	if (ctrl->keys[ach::caLeft ].state)
		if (!collide(pos - frameClock * ARCADE_HEXAGON_MOVE))
			pos -= frameClock * ARCADE_HEXAGON_MOVE;

	if (ctrl->keys[ach::caRight].state)
		if (!collide(pos + frameClock * ARCADE_HEXAGON_MOVE))
			pos += frameClock * ARCADE_HEXAGON_MOVE;

	if (pos < 0.0f     ) pos += 2.0f * PI;
	if (pos > 2.0f * PI) pos -= 2.0f * PI;
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
     * check

***********************************************************************/
bool ach::ArcadeHexagon::check() {
	for (int i = 0; i < 6; i++)
		if (sectors[i] > ARCADE_HEXAGON_RADIUS - ARCADE_HEXAGON_THICKNESS)
			return true;

	return false;
}



/***********************************************************************
     * ArcadeHexagon
     * collide

***********************************************************************/
bool ach::ArcadeHexagon::collide(float angle) {
	if (angle < 0.0f     ) angle += 2.0f * PI;
	if (angle > 2.0f * PI) angle -= 2.0f * PI;

	int section   = floor(angle / (PI / 3.0f));
	float loBound = sectors[section];
	float hiBound = sectors[section] + ARCADE_HEXAGON_THICKNESS;

	if (ARCADE_HEXAGON_OFFSET > loBound &&
	    ARCADE_HEXAGON_OFFSET < hiBound) return true;

	return false;
}



/***********************************************************************
     * ArcadeHexagon
     * create

***********************************************************************/
void ach::ArcadeHexagon::create() {
	std::vector<int> list;
	int              k;

	for (int i = 0; i < 6; i++)
		list.push_back(i);

	std::random_shuffle(list.begin(), list.end());

	switch (rand() % 5) {
		case 0: k = 1; break;
		case 1: k = 2; break;
		case 2: k = 3; break;
		case 3: k = 4; break;
		case 4: k = 5; break;
	}

	for (int i = 0; i < 6; i++)
		sectors[list[i]] = ARCADE_HEXAGON_MINRAD + ARCADE_HEXAGON_STEPRAD * (i / k);
}



/***********************************************************************
     * ArcadeHexagon
     * createRotor

***********************************************************************/
void ach::ArcadeHexagon::createRotor() {
	rotSpeed = (-getSign(rotSpeed)) * getRandomFloat(0.5f * PI, 1.0f * PI);
	rotor.setTimer(fabs(2 * PI / rotSpeed));
}



/***********************************************************************
     * ArcadeHexagon
     * drawLine

***********************************************************************/
void ach::ArcadeHexagon::drawLine(int i) {
	line[0].position = getPos(i, ARCADE_HEXAGON_RADIUS);
	line[1].position = getPos(i, ARCADE_BORDER_SIZE_Y );

	scrTex->draw(line, 2, sf::Lines);
}



/***********************************************************************
     * ArcadeHexagon
     * drawShape

***********************************************************************/
void ach::ArcadeHexagon::drawShape(int i, float dist) {
	shape->setPoint(0, getPos(i    , dist                           ));
	shape->setPoint(1, getPos(i    , dist + ARCADE_HEXAGON_THICKNESS));
	shape->setPoint(2, getPos(i + 1, dist + ARCADE_HEXAGON_THICKNESS));
	shape->setPoint(3, getPos(i + 1, dist                           ));

	scrTex->draw(*shape);
}



/***********************************************************************
     * ArcadeHexagon
     * getPos

***********************************************************************/
sf::Vector2f ach::ArcadeHexagon::getPos(int i, float radius) {
	float angle = 2.0f * PI * i / 6.0f;
	float rad   = (radius < ARCADE_HEXAGON_RADIUS) ? ARCADE_HEXAGON_RADIUS : radius;

	return getPos(angle, rad);
}



/***********************************************************************
     * ArcadeHexagon
     * getPos

***********************************************************************/
sf::Vector2f ach::ArcadeHexagon::getPos(float angle, float radius) {
	return sf::Vector2f(cos(rot + angle), sin(rot + angle)) * radius + sf::Vector2f(ARCADE_BORDER_SIZE_X / 2, ARCADE_BORDER_SIZE_Y / 2);
}
