/***********************************************************************
     * File       : control_key.hpp
     * Created    : Jun 18, 2016
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __CONTROL_KEY
#define __CONTROL_KEY


namespace ach {
	enum ControlAction {
		caUp = 0,
		caDown,
		caLeft,
		caRight,
		caJump,
		caMenu,
		caCount
	};


	struct ControlKey {
		sf::Keyboard::Key keyCode;

		bool              state;
		bool              pressed;
		bool              released;


		 ControlKey();
		~ControlKey();

		void update();
		void assign(sf::Keyboard::Key _keyCode);
	};
}

#endif
