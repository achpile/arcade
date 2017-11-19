/***********************************************************************
     * File       : arcade_snake.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ArcadeSnake
     * constructor

***********************************************************************/
ach::ArcadeSnake::ArcadeSnake() : Arcade("SNAKE") {
	score      = 0;
	square     = new sf::RectangleShape(sf::Vector2f(ARCADE_SNAKE_TILE - 1, ARCADE_SNAKE_TILE - 1));
	border     = new sf::RectangleShape(sf::Vector2f(ARCADE_SNAKE_TILE * ARCADE_SNAKE_X + 1, ARCADE_SNAKE_TILE * ARCADE_SNAKE_Y + 1));
	labelScore = new sf::Text("SCORE: 0", *font, 30);

	border->setPosition(ARCADE_SNAKE_OFFSET_X - 1, ARCADE_SNAKE_OFFSET_Y - 1);
	border->setFillColor(sf::Color::Black);
	border->setOutlineColor(sf::Color::White);
	border->setOutlineThickness(1);

	labelScore->setPosition(5, 5);

	ticker.setTimer(0.2f);
}



/***********************************************************************
     * ArcadeSnake
     * destructor

***********************************************************************/
ach::ArcadeSnake::~ArcadeSnake() {
	delete square;
	delete border;
	delete labelScore;
}



/***********************************************************************
     * ArcadeSnake
     * initSelf

***********************************************************************/
void ach::ArcadeSnake::initSelf() {
	dir = sf::Vector2i(1, 0);

	snake.clear();
	snake.push_back(sf::Vector2i(3, ARCADE_SNAKE_Y / 2));
	snake.push_back(sf::Vector2i(2, ARCADE_SNAKE_Y / 2));
	snake.push_back(sf::Vector2i(1, ARCADE_SNAKE_Y / 2));
	snake.push_back(sf::Vector2i(0, ARCADE_SNAKE_Y / 2));

	genFruit();
}



/***********************************************************************
     * ArcadeSnake
     * updateSelf

***********************************************************************/
void ach::ArcadeSnake::updateSelf() {
	tex->draw(*labelScore);
	tex->draw(*border);

	if (!ticker.process()) {
		tick();
		ticker.reset();
	}

	for (unsigned int i = 0; i < snake.size(); i++)
		draw(snake[i], false);

	if (pulse.status) draw(fruit, true);
}



/***********************************************************************
     * ArcadeSnake
     * controlsSelf

***********************************************************************/
void ach::ArcadeSnake::controlsSelf() {
	if (dir.x == 0) {
		if (ctrl->keys[ach::caLeft ].pressed) dir = sf::Vector2i(-1, 0);
		if (ctrl->keys[ach::caRight].pressed) dir = sf::Vector2i( 1, 0);
	} else {
		if (ctrl->keys[ach::caUp   ].pressed) dir = sf::Vector2i(0, -1);
		if (ctrl->keys[ach::caDown ].pressed) dir = sf::Vector2i(0,  1);
	}
}



/***********************************************************************
     * ArcadeSnake
     * tick

***********************************************************************/
void ach::ArcadeSnake::tick() {
	if (check()) move();
	else         gameover();
}



/***********************************************************************
     * ArcadeSnake
     * move

***********************************************************************/
void ach::ArcadeSnake::move() {
	for (unsigned int i = snake.size() - 1; i > 0; i--)
		snake[i] = snake[i-1];

	snake[0] += dir;
}



/***********************************************************************
     * ArcadeSnake
     * genFruit

***********************************************************************/
void ach::ArcadeSnake::genFruit() {
	bool generated = false;

	do {
		generated = true;

		fruit.x = rand() % ARCADE_SNAKE_X;
		fruit.y = rand() % ARCADE_SNAKE_Y;

		//for (unsigned int i = 0; )
	} while (!generated);
}



/***********************************************************************
     * ArcadeSnake
     * check

***********************************************************************/
bool ach::ArcadeSnake::check() {
	sf::Vector2i next = snake[0] + dir;

	if (next.x < 0) return false;
	if (next.y < 0) return false;

	if (next.x >= ARCADE_SNAKE_X) return false;
	if (next.y >= ARCADE_SNAKE_Y) return false;

	for (unsigned int i = 0; i < snake.size(); i++)
		if (next == snake[i])
			return false;

	if (next == fruit) {
		snake.push_back(sf::Vector2i(0, 0));
		genFruit();

		score++;
		labelScore->setString("SCORE: " + std::to_string(score));
	}

	return true;
}



/***********************************************************************
     * ArcadeSnake
     * draw

***********************************************************************/
void ach::ArcadeSnake::draw(sf::Vector2i pos, bool red) {
	square->setPosition(ARCADE_SNAKE_OFFSET_X + ARCADE_SNAKE_TILE * pos.x,
	                    ARCADE_SNAKE_OFFSET_Y + ARCADE_SNAKE_TILE * pos.y);

	if (red) square->setFillColor(sf::Color::Red);
	else     square->setFillColor(sf::Color::White);

	tex->draw(*square);
}
