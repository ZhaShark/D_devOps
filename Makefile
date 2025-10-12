all: conway

conway: main.o conway.o
	gcc main.o conway.o -o conway

main.o: main.c conway.h
	gcc -Wall -Wextra -std=c99 -O2 -c main.c

conway.o: conway.c conway.h
	gcc -Wall -Wextra -std=c99 -O2 -c conway.c

clean:
	rm -f *.o conway

.PHONY: all clean
