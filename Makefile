CC = gcc



all: image-viewer

image-viewer:image-viewer.c
	$(CC) -Wall -Wextra -fpermissive -o image-viewer image-viewer.c `sdl2-config --cflags --libs`
