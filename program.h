#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdint.h>

typedef struct {
    const uint8_t *data;
    uint16_t width;
    uint16_t height;
} tImage;

extern const tImage colors;
extern const tImage prog_fire;
extern const tImage prog_sauron;
extern const tImage prog_stars;
extern const tImage prog_water;

#endif // PROGRAM_H
