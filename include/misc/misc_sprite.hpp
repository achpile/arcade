/***********************************************************************
     * File       : misc_sprite.hpp
     * Created    : Apr 29, 2016
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_SPRITE
#define __MISC_SPRITE


namespace ach {
	struct Sprite {
		sf::Texture  *tex;
		sf::Sprite   *spr;
		sf::Vector2f  size;


		 Sprite(const char *filename, bool repeated, bool centered);
		~Sprite();
	};
}

#endif
