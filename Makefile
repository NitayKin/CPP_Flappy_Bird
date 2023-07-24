# Compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11

# Directories
SRCDIR := src
INCDIR := include

# Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,%.o,$(SRCS))
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Targets
EXECUTABLE := Game # $@

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -I$(INCDIR)

clean:
	rm -f $(OBJS) $(EXECUTABLE)
run: clean all
	./$(EXECUTABLE)