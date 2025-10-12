#include "conway.h"

void dump_field(const unsigned char *field, int w, int h)
{
	for_xy
	{
		printf(field[y * w + x] ? "* " : "@");
		if (x == w - 1) printf("\n");
	}
	printf("\n");
}

int main()
{
	int w = 30, h = 30;
	unsigned char *field = malloc(w * h);
	unsigned char *next = malloc(w * h);

	for_xy field[y * w + x] = rand() < RAND_MAX / 10 ? 1 : 0;

	printf("Conway's Game of Life\n");
	printf("Press Crel+C to exit\n\n");

	for (int i = 0; i < 100; i++)
	{
		dump_field(field, w, h);
		evolve(field, next, w, h);
		unsigned char *tmp = field;
		field = next;
		next = tmp;
		usleep(200000);
		printf("\033[2J\033[H");
	}

	free(field);
	free(next);
	return 0;
}
