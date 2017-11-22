/***********************************************************************
     * File       : arcade_hexagon.hpp
     * Created    : Nov 22, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __ARCADE_HEXAGON
#define __ARCADE_HEXAGON


namespace ach {
	struct ArcadeHexagon : Arcade {
		ach::Timer          ticker;
		sf::CircleShape    *center;
		sf::RenderTexture  *scrTex;
		sf::Sprite         *scrSpr;
		sf::Vertex          line[2];

		float               rot;


		 ArcadeHexagon();
		~ArcadeHexagon();

		void initSelf();
		void updateSelf();
		void controlsSelf();

		void tick();
		void drawLine(int i);

		sf::Vector2f getPos(float angle, float radius);
	};
}

#endif
