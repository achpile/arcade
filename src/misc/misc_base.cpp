/***********************************************************************
     * File       : misc_base.cpp
     * Created    : Feb 17, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * utf8

***********************************************************************/
sf::String utf8(std::string str) {
	return sf::String::fromUtf8(str.begin(), str.end());
}



/***********************************************************************
     * getRandomFloat

***********************************************************************/
float getRandomFloat(float min, float max) {
	return min + (max - min) * (float)(rand() % 100) / 100.0f;
}



/***********************************************************************
     * getSign

***********************************************************************/
int getSign(float x) {
	if (x < 0.0f)
		return -1;
	else if (x > 0.0f)
		return 1;
	else
		return 0;
}