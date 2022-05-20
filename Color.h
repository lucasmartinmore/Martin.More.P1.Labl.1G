#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int idColor;
    char nombreColor[20];
} Color;

#endif // COLOR_H_INCLUDED

void cargarDescripcionColor(char descripcionColor[], int idColor, Color colores[], int tamColores); //COLOR
void mostrarColor(Color color); //COLOR
int mostrarColores(Color colores[], int tamColores); //COLOR
