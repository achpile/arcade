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
		sf::SoundBuffer    *sndLand;
		sf::SoundBuffer    *sndLine;


		 ArcadeTetris();
		~ArcadeTetris();

		void initSelf();
		void updateSelf();
		void controlsSelf();
	};
}

#endif
