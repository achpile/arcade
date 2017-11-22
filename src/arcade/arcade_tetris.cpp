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
	labelNext  = new sf::Text("next", *font, 24);

	sndLand->loadFromFile("data/sfx/arcade/tetris/land.wav");
	sndLine->loadFromFile("data/sfx/arcade/tetris/line.wav");

	labelNext->setPosition(195, 50);

	border->setPosition(sf::Vector2f(ARCADE_TETRIS_OFFSET_X - 1, ARCADE_OFFSET_Y      - 1));
	border->setSize    (sf::Vector2f(ARCADE_TETRIS_SIZE_X   + 1, ARCADE_BORDER_SIZE_Y + 1));

	ticker.setTimer(0.33f);
}



/***********************************************************************
     * ArcadeTetris
     * destructor

***********************************************************************/
ach::ArcadeTetris::~ArcadeTetris() {
	delete sndLand;
	delete sndLine;
	delete labelNext;
}



/***********************************************************************
     * ArcadeTetris
     * initSelf

***********************************************************************/
void ach::ArcadeTetris::initSelf() {
	for (int i = 0; i < ARCADE_TETRIS_X; i++)
		for (int j = 0; j < ARCADE_TETRIS_Y; j++)
			field[i][j] = false;

	genFigure();
	next();
	genFigure();
}



/***********************************************************************
     * ArcadeTetris
     * updateSelf

***********************************************************************/
void ach::ArcadeTetris::updateSelf() {
	if (!ticker.process()) {
		tick();
		ticker.reset();
	}

	tex->draw(*labelNext);

	for (int i = 0; i < ARCADE_TETRIS_X; i++)
		for (int j = 0; j < ARCADE_TETRIS_Y; j++)
			if(field[i][j])
				draw(i, j, sf::Color::White);

	for (int i = 0; i < 4; i++)
		draw(figure[i].x, figure[i].y, sf::Color::Green);

	for (int i = 0; i < 4; i++)
		draw(upcome[i].x + 9, upcome[i].y + 4, sf::Color::White);
}



/***********************************************************************
     * ArcadeTetris
     * controlsSelf

***********************************************************************/
void ach::ArcadeTetris::controlsSelf() {
	if (ctrl->keys[ach::caLeft ].pressed) move(-1, 0);
	if (ctrl->keys[ach::caRight].pressed) move( 1, 0);
	if (ctrl->keys[ach::caJump ].pressed) rotate();

	if (ctrl->keys[ach::caDown ].state  ) ticker.timer = 0.05f;
	else                                  ticker.timer = 0.33f;
}



/***********************************************************************
     * ArcadeTetris
     * tick

***********************************************************************/
void ach::ArcadeTetris::tick() {
	copy();
	move(0, 1);

	if (!check()) {
		undo();
		land();
		lines();
		next();
		genFigure();
	}
}



/***********************************************************************
     * ArcadeTetris
     * land

***********************************************************************/
void ach::ArcadeTetris::land() {
	for (int i = 0; i < 4; i++)
		field[figure[i].x][figure[i].y] = true;

	sman->play(sndLand);
}



/***********************************************************************
     * ArcadeTetris
     * lines

***********************************************************************/
void ach::ArcadeTetris::lines() {
	bool removed = false;
	int  count;
	int  k = ARCADE_TETRIS_Y - 1;

	for (int i = ARCADE_TETRIS_Y - 1; i >= 0; i--) {
		count = 0;

		for (int j = 0; j < ARCADE_TETRIS_X; j++) {
			if (field[j][i])
				count++;

			field[j][k] = field[j][i];
		}

		if (count < ARCADE_TETRIS_X) {
			k--;
		} else {
			removed = true;
			scoreInc();
		}
	}

	for (; k >= 0; k--)
		for (int j = 0; j < ARCADE_TETRIS_X; j++)
			field[j][k] = false;

	if (removed)
		sman->play(sndLine);
}



/***********************************************************************
     * ArcadeTetris
     * genFigure

***********************************************************************/
void ach::ArcadeTetris::genFigure() {
	switch (rand() % 7) {
		case 0:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(4,1);
			upcome[2] = sf::Vector2i(5,0);
			upcome[3] = sf::Vector2i(5,1);
			break;

		case 1:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(5,0);
			upcome[2] = sf::Vector2i(3,1);
			upcome[3] = sf::Vector2i(4,1);
			break;

		case 2:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(5,0);
			upcome[2] = sf::Vector2i(5,1);
			upcome[3] = sf::Vector2i(6,1);
			break;

		case 3:
			upcome[0] = sf::Vector2i(3,0);
			upcome[1] = sf::Vector2i(4,0);
			upcome[2] = sf::Vector2i(5,0);
			upcome[3] = sf::Vector2i(6,0);
			break;

		case 4:
			upcome[0] = sf::Vector2i(4,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
			break;

		case 5:
			upcome[0] = sf::Vector2i(3,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
			break;

		case 6:
			upcome[0] = sf::Vector2i(5,0);
			upcome[1] = sf::Vector2i(3,1);
			upcome[2] = sf::Vector2i(4,1);
			upcome[3] = sf::Vector2i(5,1);
			break;
	}
}



/***********************************************************************
     * ArcadeTetris
     * draw

***********************************************************************/
void ach::ArcadeTetris::draw(int x, int y, sf::Color color) {
	square->setFillColor(color);
	square->setPosition(ARCADE_TETRIS_OFFSET_X + ARCADE_SQUARE * x,
	                    ARCADE_OFFSET_Y        + ARCADE_SQUARE * y);

	tex->draw(*square);
}



/***********************************************************************
     * ArcadeTetris
     * copy

***********************************************************************/
void ach::ArcadeTetris::copy() {
	for (int i = 0; i < 4; i++)
		backup[i] = figure[i];
}



/***********************************************************************
     * ArcadeTetris
     * undo

***********************************************************************/
void ach::ArcadeTetris::undo() {
	for (int i = 0; i < 4; i++)
		figure[i] = backup[i];
}



/***********************************************************************
     * ArcadeTetris
     * next

***********************************************************************/
void ach::ArcadeTetris::next() {
	for (int i = 0; i < 4; i++)
		figure[i] = upcome[i];

	if (!check())
		gameover();
}



/***********************************************************************
     * ArcadeTetris
     * check

***********************************************************************/
bool ach::ArcadeTetris::check() {
	for (int i = 0; i < 4; i++)
		if (figure[i].x <  0               ||
		    figure[i].x >= ARCADE_TETRIS_X ||
		    figure[i].y >= ARCADE_TETRIS_Y ||
		    field[figure[i].x][figure[i].y]) return false;

	return true;
}



/***********************************************************************
     * ArcadeTetris
     * move

***********************************************************************/
void ach::ArcadeTetris::move(int dx, int dy) {
	copy();

	for (int i = 0; i < 4; i++)
		figure[i] += sf::Vector2i(dx, dy);

	if (!dy && !check())
		undo();
}



/***********************************************************************
     * ArcadeTetris
     * rotate

***********************************************************************/
void ach::ArcadeTetris::rotate() {
	copy();

	sf::Vector2i a = figure[0];
	sf::Vector2i c;
	sf::Vector2i m;

	for (int i = 1; i < 4; i++) {
		if (a.x > figure[i].x) a.x = figure[i].x;
		if (a.y > figure[i].y) a.y = figure[i].y;
	}

	for (int i = 0; i < 4; i++) {
		m.x         = figure[i].y - c.y;
		m.y         = figure[i].x - c.x;
		figure[i].x = c.x - m.x;
		figure[i].y = c.y + m.y;
	}

	m = figure[0] - a;

	for (int i = 1; i < 4; i++) {
		if (m.x > figure[i].x - a.x) m.x = figure[i].x - a.x;
		if (m.y > figure[i].y - a.y) m.y = figure[i].y - a.y;
	}

	for (int i = 0; i < 4; i++)
		figure[i] -= m;

	if (!check())
		undo();
}
