/***********************************************************************
     * File       : misc_sound.cpp
     * Created    : Feb 17, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * SoundManager
     * constructor

***********************************************************************/
ach::SoundManager::SoundManager() {
}



/***********************************************************************
     * SoundManager
     * destructor

***********************************************************************/
ach::SoundManager::~SoundManager() {
	deleteList(sounds);
}



/***********************************************************************
     * SoundManager
     * update

***********************************************************************/
void ach::SoundManager::update() {
	std::sort(bufs.begin(), bufs.end());
	bufs.erase(std::unique(bufs.begin(), bufs.end()), bufs.end());

	add();

	for (unsigned int i = 0; i < sounds.size();)
		if (sounds[i]->getStatus() == sf::Sound::Stopped) {
			delete sounds[i];
			sounds.erase(sounds.begin() + i);
		} else
			i++;
}



/***********************************************************************
     * SoundManager
     * play

***********************************************************************/
void ach::SoundManager::play(sf::SoundBuffer *buf) {
	bufs.push_back(buf);
}



/***********************************************************************
     * SoundManager
     * add

***********************************************************************/
void ach::SoundManager::add() {
	while (!bufs.empty()) {
		addSound(bufs.back());
		bufs.pop_back();
	}
}



/***********************************************************************
     * SoundManager
     * addSound

***********************************************************************/
void ach::SoundManager::addSound(sf::SoundBuffer *buf) {
	sf::Sound *sound = new sf::Sound();
	sound->setBuffer(*buf);
	sound->setVolume(100);
	sound->play();

	sounds.push_back(sound);
}
