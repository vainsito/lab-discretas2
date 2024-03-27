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
    grafo->cant_vertices = 0; // Inicializo la cantidad de vertices en 0
    grafo->cant_lados = 0; // Inicializo la cantidad de lados en 0
    grafo->delta = 0; // Inicializo el delta en 0
    // Leo de estandar input la cantidad de vertices y aristas
    scanf("%u %u", &grafo->cant_vertices, &grafo->cant_lados);                           
}

void DestruirGrafo(Grafo G){
    
    for (u32 i = 0; i < G->cant_vertices; i++)
    {
        free(G->vertices[i]->vecinos);
        
    } 
    free(G->vertices);
    free(G);
    G = NULL;
}

// Funciones para sacar informacion
u32 NumeroDeVertices(Grafo G){
    return G->cant_vertices;
}

u32 NumeroDeLados(Grafo G)
{
    return G->cant_lados; 
}


u32 Delta(Grafo G)
{
    return G->delta; 
}

u32 Grado(u32 i,Grafo G){
    if(i >= G->cant_vertices){
        return 0;
    }
    return G->vertices[i]->grado;
}

color Color(u32 i,Grafo G){
    if(i <= G->cant_verticesert){
         return G->vertices[i]->color;
    } else {
        return (u32)(pow(2,32)-1); // Investigar como hacer potencias en C dios mio dios mio
    }
}

u32 Vecino(u32 j,u32 i,Grafo G){
    if(i >= G->cant_verticesert || j >= Grado(i,G)){
        return (u32)(pow(2,32)-1);
    }
    return G->vertices[i]->vecinos[j]->id;
}

void AsignarColor(color x,u32 i,Grafo  G){
    if(i <= G->cant_verticesert){
        G->vertices[i]->color = x;
    }
    return;
}

void ExtraerColores(Grafo G,color* Color){
    for(int i = 0 ; i < G->cant_vertices ; i++){ //entre 0 y n-1
        Color[i] = G->vertices[i]->color;
    }
    return;
}

void ImportarColores(color* Color,Grafo  G){
    for(int i = 0 ; i < G->cant_vertices ; i++){ //entre 0 y n-1
        G->vertices[i]->color = Color[i];
    }
}