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
	struct Arcade {
		sf::RenderTexture *tex;
		sf::Sprite        *spr;


		 Arcade();
		~Arcade();

		void update();
		void render();
	};
}

#endif
