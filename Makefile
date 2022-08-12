# Mac, gcc och sdl2 genom homebrew
# Windows, gcc och sdl2 genom MSYS2 mingw-w64

SRC_DIR = src
BUILD_DIR = build/debug
CC = /usr/local/Cellar/llvm/14.0.6_1/bin/clang++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
# Mac INCLUDE_PATHS
INCLUDE_PATHS =	-Iinclude -I/usr/local/include	-I/usr/local/Cellar/sdl2_image/2.6.0/include/SDL2	-I/usr/local/Cellar/sdl2/2.0.22/include/SDL2
# Windows INCLUDE_PATHS
#INCLUDE_PATHS = -Iinclude -IC:/msys64/mingw64/include
# Mac LIBRARY_PATHS
LIBRARY_PATHS = -Llib -L/usr/local/lib
# Windows LIBRARY_PATHS
#LIBRARY_PATHS = -Llib -LC:/msys64/mingw64/lib
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g
#CXXFLAGS = -std=c++11 -Wall -O0 -g
#LINKER_FLAGS = 
# Om SDL2 används, Mac LINKER_FLAGS!
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# Om SDL2 används, Windows LINKER_FLAGS!
#LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#ASAN_FLAGS = -fsanitize=leak  #-fno-omit-frame-pointer

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

