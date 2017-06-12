CC = g++
CFLAGS = -g -std=c++11
lFLAGS = -lpanel -lncurses

.PHONY: clean

all: MenuTests

MenuTests: main.cpp Menu.cpp Menu.hpp Ants.hpp Ants.cpp AG.hpp Game.cpp Game.hpp
	$(CC) $(CFLAGS) main.cpp Menu.cpp Ants.cpp Game.cpp AG.hpp -o bin/Tests/Menutest $(lFLAGS)

clean:
	cd bin/Tests && rm -f Menutest
