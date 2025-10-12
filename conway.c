#include "conway.h"

int count_alive(const unsigned char *field, int w, int h, int x, int y)
{
	int n =0;
	for (int y1 = y - 1; y1 <= y + 1; y1++) 
	{
		for (int x1 = x - 1; x1 <= x + 1; x1++)
		{
			if (field[(y1 % h) * w + (x1 % w)] && !(x1 == x && y1 == y))
				n++;
		}
	}
	return n;
}


void evolve(unsigned char *src, unsigned char *dst, int w, int h)
{
	for_xy
		{
			int n = count_alive(src, w, h, x, y);
			dst[y * w + x] = (n == 3 || (n == 2 && src[y * w + x]));
		}
}
