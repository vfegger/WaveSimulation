#ifndef WAVESIMULATION_HEADER
#define WAVESIMULATION_HEADER

struct Wave
{
    double *data;
    double *aux;
    int Li, Lj;
    double height, width;
};

struct Wave createWave(int Li, int Lj, double height, double width);
void destroyWave(struct Wave wave);
void updateWave(struct Wave wave, double dt);

#endif