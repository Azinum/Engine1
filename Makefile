# Makefile

CC = g++

# FLAGS = *.c -o engine3 -Os -std=c99 -Iinclude -lSDL2 -GL -lGLFW -lGLEW -lm

FILES := $(shell find *.cpp)

FLAGS_MAC = $(FILES) -o engine1 -O2 -Iinclude -lSDL2 -lGLEW -lm -lpng -framework OpenGL


all: build_all

build_all:
	$(CC) $(FLAGS_MAC)
	./engine1

run:
	./engine1
