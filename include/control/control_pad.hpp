/***********************************************************************
     * File       : control_pad.hpp
     * Created    : Jun 18, 2016
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __CONTROL_PAD
#define __CONTROL_PAD


namespace ach {
	struct ControlPad {
		ach::ControlKey keys[ach::caCount];


		 ControlPad();
		~ControlPad();

		void update();
		void rebind();
	};
}

#endif
