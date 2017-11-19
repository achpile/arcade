/***********************************************************************
     * File       : misc_pulsar.cpp
     * Created    : Nov 19, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Pulsar
     * setTimer

***********************************************************************/
void ach::Pulsar::setPulse(float _pulse) {
	pulse  = _pulse;
	value  = 0.0f;
	status = true;
}



/***********************************************************************
     * Pulsar
     * reset

***********************************************************************/
void ach::Pulsar::reset() {
	value  = 0.0f;
	status = true;
}



/***********************************************************************
     * Pulsar
     * process

***********************************************************************/
void ach::Pulsar::process() {
	value += frameClock;

	if (pulse <= 0.0f)
		return;

	status = sin(value * 2.0f * PI / pulse) >= 0.0f;
}
