/***********************************************************************
     * File       : misc_timer.cpp
     * Created    : Jun 29, 2014
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Timer
     * setTimer

***********************************************************************/
void ach::Timer::setTimer(float _timer) {
	timer = _timer;
	value = _timer;
}



/***********************************************************************
     * Timer
     * reset

***********************************************************************/
void ach::Timer::reset() {
	value = timer;
}



/***********************************************************************
     * Timer
     * process

***********************************************************************/
bool ach::Timer::process() {
	if (value == 0) return false;

	value -= frameClock;
	if (value <= 0) {
		value = 0;
		return false;
	} else
		return true;
}



/***********************************************************************
     * Timer
     * isActive

***********************************************************************/
bool ach::Timer::isActive() {
	if (value <= 0) return false;
	return true;
}



/***********************************************************************
     * Timer
     * getPercent

***********************************************************************/
float ach::Timer::getPercent() {
	if (timer == 0) return 0;

	return (1.0f - value / timer);
}



/***********************************************************************
     * Timer
     * getPassed

***********************************************************************/
float ach::Timer::getPassed() {
	return timer - value;
}
