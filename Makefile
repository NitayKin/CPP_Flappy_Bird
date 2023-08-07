# Compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11
GUI_CFLAGS := -Wall -Wextra -std=c++11 -DENABLE_FEATURE_GUI=1

# Directories
SRCDIR := src
INCDIR := include

# Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Targets
EXECUTABLE := Game
EXECUTABLE_GUI := Game_GUI

all:
	$(CC) -I$(INCDIR) $(CFLAGS) -o $(EXECUTABLE) $(SRCS) $(LIBS)
	-rm ../Flappy_Bird_AI/$(EXECUTABLE)
	-rm -r ../Flappy_Bird_AI/assets
	cp $(EXECUTABLE) ../Flappy_Bird_AI
	cp -r assets ../Flappy_Bird_AI

clean:
	rm -f $(EXECUTABLE)
run: clean all
	./$(EXECUTABLE)
gui:
	$(CC) -I$(INCDIR) $(GUI_CFLAGS) -o $(EXECUTABLE_GUI) $(SRCS) $(LIBS)
	-rm ../Flappy_Bird_AI/$(EXECUTABLE_GUI)
	-rm -r ../Flappy_Bird_AI/assets
	cp $(EXECUTABLE_GUI) ../Flappy_Bird_AI
	cp -r assets ../Flappy_Bird_AI