# Compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11

# Directories
SRCDIR := src
INCDIR := include

# Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Targets
EXECUTABLE := Game # $@

all:
	$(CC) -I$(INCDIR) $(CFLAGS) -o $(EXECUTABLE) $(SRCS) $(LIBS)
	-rm ../Flappy_Bird_AI/Game
	-rm -r ../Flappy_Bird_AI/assets
	cp Game ../Flappy_Bird_AI
	cp -r assets ../Flappy_Bird_AI

clean:
	rm -f $(EXECUTABLE)
run: clean all
	./$(EXECUTABLE)