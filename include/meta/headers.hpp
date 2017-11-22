/***********************************************************************
     * File       : headers.hpp
     * Created    : Feb 16, 2015
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __HEADERS
#define __HEADERS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <jansson.h>

#include "defines.hpp"

#include "misc/misc_timer.hpp"
#include "misc/misc_pulsar.hpp"
#include "misc/misc_sprite.hpp"
#include "misc/misc_sound.hpp"
#include "misc/misc_string.hpp"

#include "control/control_key.hpp"
#include "control/control_pad.hpp"

#include "arcade/arcade_base.hpp"
#include "arcade/arcade_snake.hpp"
#include "arcade/arcade_arkanoid.hpp"
#include "arcade/arcade_simon.hpp"
#include "arcade/arcade_tetris.hpp"
#include "arcade/arcade_hexagon.hpp"

#include "externs.hpp"

#endif
