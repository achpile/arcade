/***********************************************************************
     * File       : arcade_simon.hpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_SIMON
#define __ARCADE_SIMON


namespace ach {
	struct ArcadeSimon : Arcade {
		ach::Timer          ticker;
		sf::RectangleShape *square;
		sf::RectangleShape *border;
		sf::ConvexShape    *shapeUp;
		sf::ConvexShape    *shapeDown;
		sf::ConvexShape    *shapeLeft;
		sf::ConvexShape    *shapeRight;
		sf::Text           *labelScore;
		sf::Vector2i        dir;
		sf::Vector2i        fruit;

		unsigned int        score;
		int                 field[ARCADE_SNAKE_X * ARCADE_SNAKE_Y];

		std::vector<sf::Vector2i> snake;


		 ArcadeSimon();
		~ArcadeSimon();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void tick();
		void draw(sf::ConvexShape *shape, sf::Color c, int value);
	};
}

#endif
