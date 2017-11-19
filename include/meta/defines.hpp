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
     * Math constants

***********************************************************************/
#define PI                       3.1415926f
#define DEG_TO_RAD               0.01745f
#define RAD_TO_DEG               57.29578f

#endif
