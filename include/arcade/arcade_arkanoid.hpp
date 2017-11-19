/***********************************************************************
     * File       : arcade_arkanoid.hpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_ARKANOID
#define __ARCADE_ARKANOID


namespace ach {
	struct ArcadeArkanoid : Arcade {
		sf::SoundBuffer    *hitWall;
		sf::SoundBuffer    *hitTile;
		sf::RectangleShape *tile;
		sf::RectangleShape *paddle;
		sf::RectangleShape *square;
		sf::RectangleShape *border;
		sf::Text           *labelScore;

		unsigned int        score;


		 ArcadeArkanoid();
		~ArcadeArkanoid();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void move();
		bool check();
	};
}

#endif
