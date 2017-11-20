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
	enum ArcadeSimonState {
		assDemo,
		assPause,
		assInput,
		assCorrect,
		assCreate
	};


	struct ArcadeSimon : Arcade {
		ach::ArcadeSimonState  state;
		ach::Timer             ticker;
		sf::RectangleShape    *square;
		sf::RectangleShape    *border;
		sf::ConvexShape       *shapeUp;
		sf::ConvexShape       *shapeDown;
		sf::ConvexShape       *shapeLeft;
		sf::ConvexShape       *shapeRight;
		sf::Text              *labelScore;
		sf::SoundBuffer       *bufUp;
		sf::SoundBuffer       *bufDown;
		sf::SoundBuffer       *bufLeft;
		sf::SoundBuffer       *bufRight;
		sf::SoundBuffer       *bufCorr;

		unsigned int           score;
		int                    seq[ARCADE_SIMON_SIZE];
		bool                   buttons[4];
		int                    len;
		int                    pos;


		 ArcadeSimon();
		~ArcadeSimon();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void create();
		void reset();
		void press(int dir);
		void tick();
		void draw(sf::ConvexShape *shape, sf::Color c, int value);
	};
}

#endif
