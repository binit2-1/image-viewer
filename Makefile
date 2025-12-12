CC = gcc



all: image-viewer

image-viewer:image-viewer.c
	$(CC) -Wall -Wextra -fpermissive -o image-viewer image-viewer.c `sdl2-config --cflags --libs`

push:
	git add .
	git commit -m "Changed readme"
	git push origin main

clean:
	rm -f image-viewer