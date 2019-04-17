# Makefile

CC = g++

SOURCE_FILES := $(shell find . -name \*.cpp -print)

FLAGS_MAC = $(SOURCE_FILES) -o engine1 -O2 -Iinclude -lSDL2 -lGLEW -lm -lpng -framework OpenGL -Wall

all: build_all

build_all:
	$(CC) $(FLAGS_MAC)
	./engine1

run:
	./engine1
