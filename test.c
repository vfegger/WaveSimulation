#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/waveSimulation.h"

void PrintArray(double *array, int Li, int Lj)
{
    for (int i = 0; i < Li; ++i)
    {
        printf("[ ");
        for (int j = 0; j < Lj; ++j)
        {
            printf("%.2lf ", array[j * Li + i]);
        }
        printf("]\n");
    }
    printf("\n");
}

void main()
{
    int Li = 100;
    int Lj = 100;
    int Lt = 1000;
    double height = 1.0;
    double width = 1.0;
    double duration = 1.0;
    struct Wave wave = createWave(Li, Lj, height, width);
    wave.data[((Lj + 2) / 2) * (Li + 2) + (Li + 2) / 2] = 1.0;
    for (int t = 0; t < Lt; ++t)
    {
        if (t == Lt % (Lt / 10))
        {
            PrintArray(wave.data, Li + 2, Lj + 2);
        }
        updateWave(wave, duration / Lt);
    }
    PrintArray(wave.data, Li + 2, Lj + 2);
}