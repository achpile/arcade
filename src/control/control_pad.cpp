/***********************************************************************
     * File       : control_pad.cpp
     * Created    : Jun 18, 2016
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ControlPad
     * constructor

***********************************************************************/
ach::ControlPad::ControlPad() {
	rebind();
}



/***********************************************************************
     * ControlPad
     * destructor

***********************************************************************/
ach::ControlPad::~ControlPad() {
}



/***********************************************************************
     * ControlPad
     * update

***********************************************************************/
void ach::ControlPad::update() {
	for (int i = 0; i < ach::caCount; i++)
		keys[i].update();
}



/***********************************************************************
     * ControlPad
     * rebind

***********************************************************************/
void ach::ControlPad::rebind() {
	keys[ach::caUp   ].assign(sf::Keyboard::Up    );
	keys[ach::caDown ].assign(sf::Keyboard::Down  );
	keys[ach::caLeft ].assign(sf::Keyboard::Left  );
	keys[ach::caRight].assign(sf::Keyboard::Right );
	keys[ach::caJump ].assign(sf::Keyboard::Space );
	keys[ach::caMenu ].assign(sf::Keyboard::Escape);
}
