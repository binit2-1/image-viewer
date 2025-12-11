CC = gcc



all: image-viewer

image-viewer:image-viewer.c
	$(CC) -o image-viewer image-viewer.c
