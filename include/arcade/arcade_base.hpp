/***********************************************************************
     * File       : arcade_base.hpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_BASE
#define __ARCADE_BASE


namespace ach {
	enum ArcadeState {
		asStart,
		asGame,
		asGameOver
	};


	struct Arcade {
		ach::ArcadeState  state;
		sf::RenderTexture *tex;
		sf::Sprite        *spr;

		bool               running;


		         Arcade();
		virtual ~Arcade();

		void update();
		void render();
		void controls();
		void init();
		void quit();
		void reset();
		void gameover();

		virtual void initSelf()     {};
		virtual void updateSelf()   {};
		virtual void controlsSelf() {};
	};
}

#endif
