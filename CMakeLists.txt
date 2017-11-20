CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
PROJECT ( arcade )

INCLUDE_DIRECTORIES ("include" "include/meta" )
FILE ( GLOB SRC "src/*/*.cpp" )

SET ( CMAKE_CXX_FLAGS_COMMON "-std=c++11" )
SET ( CMAKE_EXE_FLAGS_COMMON "" )


IF ( WIN32 )
	SET ( CMAKE_CXX_FLAGS_ARCH  "-s" )
	SET ( CMAKE_EXE_FLAGS_ARCH  "-mwindows -s -static-libgcc -static-libstdc++" )
ELSEIF ( APPLE )
	SET ( CMAKE_CXX_FLAGS_ARCH  "" )
	SET ( CMAKE_EXE_FLAGS_ARCH  "" )
ELSEIF ( UNIX )
	SET ( CMAKE_CXX_FLAGS_ARCH  "-s" )
	SET ( CMAKE_EXE_FLAGS_ARCH  "-s -static-libgcc -static-libstdc++" )
ENDIF ( )


SET ( CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS_ARCH} ${CMAKE_CXX_FLAGS_COMMON}" )
SET ( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_FLAGS_ARCH} ${CMAKE_EXE_FLAGS_COMMON}" )

ADD_EXECUTABLE ( arcade ${SRC} )
TARGET_LINK_LIBRARIES ( arcade sfml-audio sfml-graphics sfml-window sfml-system m )
FILE(COPY "${PROJECT_SOURCE_DIR}/data" DESTINATION ${PROJECT_BINARY_DIR})
