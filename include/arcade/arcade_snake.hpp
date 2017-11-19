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
		sf::RectangleShape *square;
		sf::RectangleShape *border;
		sf::Vector2i        dir;
		sf::Vector2i        fruit;

		std::vector<sf::Vector2i> snake;


		 ArcadeSnake();
		~ArcadeSnake();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void tick();
		void draw(sf::Vector2i pos, bool red);
	};
}

#endif
