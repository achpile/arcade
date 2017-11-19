/***********************************************************************
     * File       : defines.hpp
     * Created    : Feb 17, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEFINES
#define __DEFINES



/***********************************************************************
     * Main project constants

***********************************************************************/
#define PROJECT_CAPTION          "Arcade"



/***********************************************************************
     * List processing macros

***********************************************************************/
#define deleteList(list)      for (; !(list).empty();) { if ((list).back()) delete (list).back(); (list).pop_back(); }
#define updateList(list)      for (unsigned int i = 0; i < (list).size();) { if (!(list)[i]->update()) {delete (list)[i]; (list).erase((list).begin() + i);} else i++;}



/***********************************************************************
     * Screen constants

***********************************************************************/
#define SCREEN_X                 256
#define SCREEN_Y                 256



/***********************************************************************
     * Arcade constants

***********************************************************************/
#define ARCADE_SNAKE_TILE        10
#define ARCADE_SNAKE_X           25
#define ARCADE_SNAKE_Y           20
#define ARCADE_SNAKE_OFFSET_X    3
#define ARCADE_SNAKE_OFFSET_Y    53

#define ARCADE_ARKANOID_TILE_X   25
#define ARCADE_ARKANOID_TILE_Y   10
#define ARCADE_ARKANOID_X        10
#define ARCADE_ARKANOID_Y        10
#define ARCADE_ARKANOID_PADDLE   75
#define ARCADE_ARKANOID_SIZE_X   250
#define ARCADE_ARKANOID_SIZE_Y   200
#define ARCADE_ARKANOID_OFFSET_X 3
#define ARCADE_ARKANOID_OFFSET_Y 53
#define ARCADE_ARKANOID_SPEED    250.0f

#define ARCADE_SIMON_SIZE_X      250
#define ARCADE_SIMON_SIZE_Y      200
#define ARCADE_SIMON_OFFSET_X    3
#define ARCADE_SIMON_OFFSET_Y    53



/***********************************************************************
     * Math constants

***********************************************************************/
#define PI                       3.1415926f
#define DEG_TO_RAD               0.01745f
#define RAD_TO_DEG               57.29578f

#endif
