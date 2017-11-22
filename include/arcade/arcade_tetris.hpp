/***********************************************************************
     * File       : arcade_tetris.hpp
     * Created    : Nov 22, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_TETRIS
#define __ARCADE_TETRIS


namespace ach {
	struct ArcadeTetris : Arcade {
		ach::Timer          ticker;
		sf::SoundBuffer    *sndLand;
		sf::SoundBuffer    *sndLine;
		sf::Text           *labelNext;
		sf::Vector2i        figure[4];
		sf::Vector2i        upcome[4];
		sf::Vector2i        backup[4];

		bool                field[ARCADE_TETRIS_X][ARCADE_TETRIS_Y];


		 ArcadeTetris();
		~ArcadeTetris();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void tick();
		void land();
		void lines();
		void genFigure();
		void draw(int x, int y, sf::Color color);
		void copy();
		void undo();
		void next();
		bool check();
		void move(int dx, int dy);
		void rotate();
	};
}

#endif
