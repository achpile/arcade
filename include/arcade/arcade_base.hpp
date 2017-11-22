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
		ach::ArcadeState    state;
		ach::Pulsar         pulse;
		sf::SoundBuffer    *blip;
		sf::SoundBuffer    *hit;
		sf::RenderTexture  *tex;
		sf::Sprite         *spr;
		sf::RectangleShape *border;
		sf::RectangleShape *square;

		sf::Text           *labelScore;
		sf::Text           *labelCaption;
		sf::Text           *labelStart;
		sf::Text           *labelGameover;

		unsigned int        score;
		bool                running;


		         Arcade(std::string caption);
		virtual ~Arcade();

		void update();
		void render();
		void controls();
		void init();
		void quit();
		void reset();
		void gameover();

		void scoreInc();
		void scoreReset();
		void scoreUpdate();

		virtual void initSelf()     {};
		virtual void updateSelf()   {};
		virtual void controlsSelf() {};
	};
}

#endif
