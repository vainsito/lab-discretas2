#ifndef EstrucGrafo24_H
#define EstrucGrafo24_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32; 
typedef u32 color; 


struct Vertice
{
    u32 id;
    color color;
    u32 grado;
    struct Vertice *vecinos; // Arreglo de vertices que son vecinos 
};

struct TuplaVertice
{
    struct Vertice v1;
    struct Vertice v2;
};

struct GrafoSt
{
    u32 delta; //delta
    u32 cant_vertices; //Cantidad de vertices 
    u32 cant_lados; //Cantidad de lados
    struct Vertice *vertices; // Vertices del grafo
};

// grafo = (int vertices, lista aristas) (lista de int, )
// Grafo = 5 vertices, [(1,2), (2,3), (3,4), (4,5), (5,1)], 

#endif 