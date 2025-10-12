#ifndef CONWAY_H
#define CONWAY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define for_x for (int x = 0; x < w; x++)
#define for_y for (int y = 0; y < h; y++)
#define for_xy for_x for_y

int cont_alive(const unsigned char *field, int w, int h, int x, int y);
void evolve(unsigned char *src, unsigned char *dst, int w, int h);
void dump_feld(const unsigned char *field, int w, int h);

#endif
