#include <stdio.h>
#include <stdlib.h>
#include "APIG24.h"
#include <math.h>

// Hace algo.
Grafo ConstruccionDelGrafo(){
    // Inicializo el grafo y le aloco memoria
    Grafo grafo = (Grafo)malloc(sizeof(struct GrafoSt)); // Aloco memoria para el grafo
    if(grafo == NULL){ // Si no se pudo alocar memoria
        return NULL; // Retorno NULL
    }
    grafo->cant_v = 0; // Inicializo la cantidad de vertices en 0
    grafo->cant_l = 0; // Inicializo la cantidad de lados en 0
    grafo->delta = 0; // Inicializo el delta en 0
    // Leo de estandar input la cantidad de vertices y aristas
    scanf("%u %u", &grafo->cant_v, &grafo->cant_l);                           
}

void DestruirGrafo(Grafo G){
    
}

// Funciones para sacar informacion
u32 NumeroDeVertices(Grafo G){
    return G->cant_v;
}

u32 NumeroDeLados(Grafo G)
{
    return G->cant_l; 
}


u32 Delta(Grafo G)
{
    return G->delta; 
}

u32 Grado(u32 i,Grafo G){
    if(i >= G->cant_v){
        return 0;
    }
    return G->vertices[i]->grado;
}

color Color(u32 i,Grafo G){
    if(i <= G->cant_v){
         return G->vertices[i]->color;
    } else {
        return (2**5 - 1); // Investigar como hacer potencias en C dios mio dios mio
    }
}

u32 Vecino(u32 j,u32 i,Grafo G){
    
}

void AsignarColor(color x,u32 i,Grafo  G);

void ExtraerColores(Grafo G,color* Color);

void ImportarColores(color* Color,Grafo  G);