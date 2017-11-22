/***********************************************************************
     * File       : misc_string.cpp
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
