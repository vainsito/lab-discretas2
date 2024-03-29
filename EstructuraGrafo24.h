#ifndef EstructuraGrafo24_H
#define EstructuraGrafo24_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32; 
typedef u32 color;

struct Vertice
{
    u32 id;
    color color;
    u32 grado;
    u32 cant_vecinos;
    struct Vertice **vecinos; // Arreglo dinamico de vertices que son vecinos
};

struct TuplaVertice
{
    struct Vertice v1;
    struct Vertice v2; // Tupla de vertices
};

struct GrafoSt {
    u32 delta; //delta
    u32 cant_vertices; //Cantidad de vertices 
    u32 cant_lados; //Cantidad de lados
    struct Vertice *vertices; // Array de vertices
    struct TuplaVertice *aristas; // Array de aristas (tuplas de vertices)
};

// grafo = (int vertices, lista aristas) (lista de int, )
// Grafo = 5 vertices, [(1,2), (2,3), (3,4), (4,5), (5,1)], 

#endif 