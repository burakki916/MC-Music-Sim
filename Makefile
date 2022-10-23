CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -w -static

BIN		:= bin
SRC		:= src
INCLUDE	:= include -I C:\SFML-2.5.1\include -DSFML_STATIC
LIB		:= lib -L C:\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-audio-s -lsfml-window-s -lsfml-system-s -lgdi32 -lwinmm -lopengl32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg

LIBRARIES	:= C:\SFML-2.5.1lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -static-libgcc -static-libstdc++
EXECUTABLE	:= main.exe


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $^ $(CXX_FLAGS)  -I$(INCLUDE) -L$(LIB)  -o $@

clean:
	-rm $(BIN)/*.exe
