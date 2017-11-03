all: main.c
	gcc -o dir_scan main.c

run: all
	./dir_scan
