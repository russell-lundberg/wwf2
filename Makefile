UNAME_S := $(shell uname -s)

CFLAGS=-g -Wall -Wextra -std=c++17
#CFLAGS += -fsyntax-only
CFLAGS += -fmax-errors=4

CCFLAGS=-D BOOST_MATH_STANDALONE
# I always keep my source files in a directory called "src"
SRC=src
SRCS=$(wildcard $(SRC)/*.cpp)

OBJ=obj
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

# executables
BINDIR=bin
BIN = $(BINDIR)/main

ifeq ($(UNAME_S),Linux)
    CC=/usr/bin/g++
    CCFLAGS += -D LINUX 
    #CCFLAGS += -D LINUX -D BOOST_MATH_STANDALONE
    BOOST_ROOT=/home/lundberg/coding/libs/boost/1.83.0
endif
ifeq ($(UNAME_S),Darwin)
    CC=/opt/homebrew/Cellar/gcc/13.2.0/bin/g++-13
    CCFLAGS += -D OSX 
    BOOST_ROOT=/opt/homebrew/Cellar/boost/1.83.0
endif

INCLUDE=-Iinclude -I$(BOOST_ROOT)/include

LDFLAGS=

LDLIBS=-L$(BOOST_ROOT)/lib -lstdc++ -lboost_system -l:libboost_program_options.a

all:$(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*
