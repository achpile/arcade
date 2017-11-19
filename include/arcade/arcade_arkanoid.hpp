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
		sf::Vector2f        pos;
		sf::Vector2f        vel;

		unsigned int        score;
		float               posX;
		bool                tiles[ARCADE_ARKANOID_X][ARCADE_ARKANOID_Y];
		bool                glue;


		 ArcadeArkanoid();
		~ArcadeArkanoid();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void move();
		bool check();
		void drawPaddle();
		void drawSquare();
		void drawTile(int x, int j);
	};
}

#endif
