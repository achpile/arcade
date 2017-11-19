/***********************************************************************
     * File       : control_key.cpp
     * Created    : Jun 18, 2016
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ControlKey
     * constructor

***********************************************************************/
ach::ControlKey::ControlKey() {
}



/***********************************************************************
     * ControlKey
     * destructor

***********************************************************************/
ach::ControlKey::~ControlKey() {
}



/***********************************************************************
     * ControlKey
     * update

***********************************************************************/
void ach::ControlKey::update() {
	bool newState = sf::Keyboard::isKeyPressed(keyCode);

	if ( newState && newState != state) pressed = true;
	else                                pressed = false;

	if (!newState && newState != state) released = true;
	else                                released = false;

	state = newState;
}



/***********************************************************************
     * ControlKey
     * assign

***********************************************************************/
void ach::ControlKey::assign(sf::Keyboard::Key _keyCode) {
	keyCode = _keyCode;
	state   = sf::Keyboard::isKeyPressed(keyCode);
}
