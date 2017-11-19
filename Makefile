########################################################################
#                                                                       
#               Main Makefile for ARCADE project                        
#                                                                       
########################################################################
PROJECT     = arcade
INCLUDE_DIR = $(PWD)/include
OBJS        = $(patsubst %.cpp,%.o,$(sort $(wildcard src/*/*.cpp)))
NPROCS      = $(shell grep -c ^processor /proc/cpuinfo)
TOTAL       = $(words $(OBJS))
LEN         = $(shell echo -n ${TOTAL} | wc -c)

CMAKE       = CMakeFiles          \
              CMakeCache.txt      \
              cmake_install.cmake

GARBAGE     = $(OBJS) $(PROJECT) $(CMAKE)

CC          = @g++
STRIP       = @strip
MAKE        = @make -j${NPROCS} --no-print-directory
ECHO        = @echo
CLEAN       = @rm -rf
PROGRESS    = \[`echo $(OBJS) | sed "s/\ /\n/g" | grep -n $@ | cut -f1 -d: | tr -d '\n' | xargs -0 printf "%0$(LEN)d"`\/$(TOTAL)\]


NORMAL      = "\033[0m"
PURPLE      = "\033[1;35m"
YELLOW      = "\033[0;33m"
GREEN       = "\033[0;32m"
CYAN        = "\033[1;36m"
RED         = "\033[1;31m"

LDFLAGS     = -static-libstdc++ \
              -static-libgcc    \
              -lsfml-graphics   \
              -lsfml-window     \
              -lsfml-system     \
              -lsfml-audio      \
              -lm

CFLAGS      = -Wall                       \
              -Wextra                     \
              -std=c++11                  \
              -I$(INCLUDE_DIR)            \
              -I$(INCLUDE_DIR)/meta


all: info
	$(MAKE) $(PROJECT)


info:
	$(ECHO) $(CYAN)
	$(ECHO) $(CYAN) "         ▄                    ▗▖     "
	$(ECHO) $(CYAN) "        ▐█▌                   ▐▌     "
	$(ECHO) $(CYAN) "        ▐█▌  █▟█▌ ▟██▖ ▟██▖ ▟█▟▌ ▟█▙ "
	$(ECHO) $(CYAN) "        █ █  █▘  ▐▛  ▘ ▘▄▟▌▐▛ ▜▌▐▙▄▟▌"
	$(ECHO) $(CYAN) "        ███  █   ▐▌   ▗█▀▜▌▐▌ ▐▌▐▛▀▀▘"
	$(ECHO) $(CYAN) "       ▗█ █▖ █   ▝█▄▄▌▐▙▄█▌▝█▄█▌▝█▄▄▌"
	$(ECHO) $(CYAN) "       ▝▘ ▝▘ ▀    ▝▀▀  ▀▀▝▘ ▝▀▝▘ ▝▀▀ "
	$(ECHO) $(NORMAL)
	$(ECHO) $(RED) "C  flags:" $(YELLOW) $(CFLAGS)  $(NORMAL)
	$(ECHO) $(RED) "LD flags:" $(YELLOW) $(LDFLAGS) $(NORMAL)
	$(ECHO)
	$(ECHO) $(PURPLE) "Building $(TOTAL) files in $(NPROCS) threads" $(NORMAL)
	$(ECHO) $(PURPLE) "Building: $(PROJECT)" $(NORMAL)
	$(ECHO)


$(PROJECT): $(OBJS)
	$(ECHO)
	$(ECHO) $(CYAN) Linking $(PROJECT) $(NORMAL)
	$(CC) $(OBJS) -o $(PROJECT) $(LDFLAGS)

	$(ECHO) $(CYAN) Stripping $(PROJECT) $(NORMAL)
	$(STRIP) $(PROJECT)


.cpp.o:
	$(ECHO) $(GREEN) "  Compiling" $(NORMAL)$(PROGRESS)$(GREEN) ": $(*F)" $(NORMAL)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	$(ECHO) $(YELLOW)$(GARBAGE) $(NORMAL)
	$(CLEAN) $(GARBAGE)
