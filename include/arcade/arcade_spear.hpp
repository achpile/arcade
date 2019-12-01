/***********************************************************************
     * File       : arcade_spear.hpp
     * Created    : Dec 01, 2019
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_SPEAR
#define __ARCADE_SPEAR


namespace ach {
	struct ArcadeSpearEnemy {
		int   dir;
		int   speed;
		float dist;


		ArcadeSpearEnemy(int _dir, int _speed) {dir = _dir; speed = _speed; dist = ARCADE_SPEAR_DIST;};
	};


	struct ArcadeSpear : Arcade {
		ach::Timer          ticker;
		sf::RectangleShape *block;
		sf::Transform       transform;
		sf::Vertex          player[3];

		std::vector<ach::ArcadeSpearEnemy> enemies;

		int dir;


		 ArcadeSpear();
		~ArcadeSpear();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void  tick();
		void  drawEnemy(int dir, float dist, int speed);
		float genSpeed(int speed);
	};
}

#endif
