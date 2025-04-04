donut: donut.o
	gcc donut.o -o donut

donut.o: donut.c
	gcc -c donut.c -o donut.o


