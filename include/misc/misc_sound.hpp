/***********************************************************************
     * File       : misc_sound.hpp
     * Created    : Feb 18, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_SOUND
#define __MISC_SOUND


namespace ach {
	struct SoundManager {
		std::vector<sf::Sound*>       sounds;
		std::vector<sf::SoundBuffer*> bufs;


		 SoundManager();
		~SoundManager();

		void update();
		void add();
		void addSound(sf::SoundBuffer *buf);
		void play(sf::SoundBuffer *buf);
	};
}

#endif
