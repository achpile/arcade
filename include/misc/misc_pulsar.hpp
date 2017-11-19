/***********************************************************************
     * File       : misc_pulsar.hpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_PULSAR
#define __MISC_PULSAR


namespace ach {
	struct Pulsar {
		float value;
		float pulse;
		bool  status;


		Pulsar() { value = 0.0f; pulse = 0.0f; status = true;};

		void  setPulse(float _pulse);
		void  reset();
		void  process();
	};
}

#endif
