/***********************************************************************
     * File       : arcade_snake.hpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_SNAKE
#define __ARCADE_SNAKE


namespace ach {
	struct ArcadeSnake : Arcade {
		ach::Timer          ticker;
		sf::SoundBuffer    *pickup;
		sf::RectangleShape *square;
		sf::RectangleShape *border;
		sf::Text           *labelScore;
		sf::Vector2i        dir;
		sf::Vector2i        fruit;

		unsigned int        score;
		int                 field[ARCADE_SNAKE_X * ARCADE_SNAKE_Y];

		std::vector<sf::Vector2i> snake;


		 ArcadeSnake();
		~ArcadeSnake();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void tick();
		void move();
		void genFruit();
		bool check();
		void draw(sf::Vector2i pos, sf::Color color);
	};
}

#endif
