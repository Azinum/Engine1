# Makefile

CC = g++

SOURCE_FILES := $(shell find . -name \*.cpp -print)

FLAGS_MAC = $(SOURCE_FILES) -o engine1 -O2 -Iinclude -lSDL2 -lGLEW -lm -lpng -framework OpenGL

FLAGS_ANDROID = $(SOURCE_FILES) -o engine1_android -O2 -Iinclude -pie -lSDL2 -lGLEW -lm -lpng -framework OpenGL

all: build_all

build_all:
	$(CC) $(FLAGS_MAC)
	./engine1

# In progress
android:
	~/arm/bin/clang $(FLAGS_ANDROID)

run:
	./engine1
