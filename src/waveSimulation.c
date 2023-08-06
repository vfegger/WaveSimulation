#include <stdlib.h>
#include "..\include\waveSimulation.h"

struct Wave createWave(int Li, int Lj, double height, double width)
{
    struct Wave wave;
    wave.data = (double *)malloc(sizeof(double) * (Li + 2) * (Lj + 2));
    wave.aux = (double *)malloc(sizeof(double) * (Li + 2) * (Lj + 2));
    for (int i = 0; i < (Li + 2) * (Lj + 2); ++i)
    {
        wave.data[i] = 0.0;
        wave.aux[i] = 0.0;
    }
    wave.Li = Li;
    wave.Lj = Lj;
    wave.height = height;
    wave.width = width;
    return wave;
}

void destroyWave(struct Wave wave)
{
    free(wave.aux);
    free(wave.data);
    return;
}

int index(int i, int j, int stride)
{
    return j * stride + i;
}

void updateWave(struct Wave wave, double dt)
{
    double dx2 = (wave.height / wave.Li) * (wave.height / wave.Li);
    double dy2 = (wave.width / wave.Lj) * (wave.width / wave.Lj);
    // Interior Points - Boundary Points are not updated
    for (int j = 0; j < wave.Li; ++j)
    {
        for (int i = 0; i < wave.Lj; ++i)
        {
            double iL = wave.data[index(i + 0, j + 1, wave.height+2)];
            double iR = wave.data[index(i + 2, j + 1, wave.height+2)];
            double jL = wave.data[index(i + 1, j + 0, wave.height+2)];
            double jR = wave.data[index(i + 1, j + 2, wave.height+2)];
            double c = wave.data[index(i + 1, j + 1, wave.height+2)];
            wave.aux[index(i + 1, j + 1, wave.height+2)] = dt * ((iL - 2 * c + iR) / dx2 + (jL - 2 * c + jR) / dy2);
        }
    }
    // Update Points
    for (int j = 0; j < wave.width; ++j)
    {
        for (int i = 0; i < wave.height; ++i)
        {
            wave.data[index(i + 1, j + 1, wave.height+2)] += wave.aux[index(i + 1, j + 1, wave.height+2)];
        }
    }
    return;
}