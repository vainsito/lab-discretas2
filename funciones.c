#include <stdio.h>
#include <stdlib.h>
#include "APIG24.h"
#include <math.h>
#include "EstructuraGrafo24.h"

// Hace algo.
// Funcion auxiliar para agregar vecinos a un vertice
void agregar_vecino(struct Vertice *vertice, struct Vertice *vecino)
{
    // Reasigno memoria para los vecinos, ya que voy a agregar un vecino mas
    vertice->vecinos = (struct Vertice **)realloc(vertice->vecinos, (vertice->cant_vecinos + 1) * sizeof(struct Vertice *));
    // Manejo de errores si no se pudo alocar memoria
    if (vertice->vecinos == NULL){
        // Si no se pudo alocar memoria, salgo del programa
        exit(1);
    }
    // Agrego el vecino al vertice
    vertice->vecinos[vertice->cant_vecinos] = vecino;
    vertice->cant_vecinos++;
}
// Funcion auxiliar para agregar un lado al grafo
void agregar_lado(Grafo grafo, struct Vertice *v1, struct Vertice *v2, u32 posicion)
{
    // No mem dinamica, tenemos una cantidad fija de aristas
    grafo->aristas[posicion].v1 = *v1; // Asigno el v1 de la tupla de vertices
    grafo->aristas[posicion].v2 = *v2; // Asigno el v2 de la tupla de vertices

}


Grafo ConstruirGrafo(){
    // Inicializo el grafo y le aloco memoria
    Grafo grafo = (Grafo)malloc(sizeof(struct GrafoSt)); // Aloco memoria para el grafo
    if(grafo == NULL){ // Si no se pudo alocar memoria
        return NULL; // Retorno NULL
    }
    grafo->cant_vertices = 0; // Inicializo la cantidad de vertices en 0
    grafo->cant_lados = 0; // Inicializo la cantidad de lados en 0
    grafo->delta = 0; // Inicializo el delta en 0

    // Leo la cantidad de vertices y lados
    u32 cant_vert = 0, cant_aristas = 0; // Inicio las variables en 0
    char line[1024]; // Creo un buffer para leer la linea de stdin

    while (fgets(line, sizeof(line), stdin)) // Mientras pueda leer una linea de stdin
    {
        if (line[0] == 'c') {
            continue; // Si la linea empieza con 'c' sigo leyendo
        }
        
        if (line[0] == 'p') // Si la linea empieza con 'p'
        {
            sscanf(line, "p edge %d %d", &cant_vert, &cant_aristas); // Leo la cantidad de vertices y lados
            break; // Salgo del while
        }
    }

    if (cant_vert == 0 || cant_aristas == 0) // Si no se pudo leer la cantidad de vertices o lados
    {
        free(grafo); // Libero la memoria del grafo
        return NULL; // Retorno NULL
    }
    
    grafo->cant_vertices = cant_vert; // Asigno la cantidad de vertices al grafo
    grafo->cant_lados = cant_aristas; // Asigno la cantidad de lados al grafo
    // Voy a ir cargando los vertices y lados en el grafo, pero primero tengo que alocar memoria para los vertices y lados
    grafo->vertices = (struct Vertice*)malloc(cant_vert * sizeof(struct Vertice)); // Aloco memoria para los vertices
    if(grafo->vertices == NULL){ // Si no se pudo alocar memoria
        free(grafo->vertices); // Libero la memoria de los vertices
        free(grafo); // Libero la memoria del grafo
        return NULL; // Retorno NULL
    }
    grafo->aristas = (struct TuplaVertice*)malloc(cant_aristas * sizeof(struct TuplaVertice)); // Aloco memoria para las aristas
    if(grafo->aristas == NULL){ // Si no se pudo alocar memoria
        free(grafo->aristas); // Libero la memoria de los vertices
        free(grafo); // Libero la memoria del grafo
        return NULL; // Retorno NULL
    }
    // Ahora voy a cargar los vertices y lados en el grafo
    // For no sirve, ya que el orden de los grafos no es secuencial, sino que puede ser cualquier orden
    // Entonces tengo que leer cada linea y cargar los vertices y lados en el grafo, en el vertice correspondiente
    u32 cant_vert_leidos = 0; // Inicializo la cantidad de lineas en 0, para indexar array de vertices y aristas
    while (fgets(line, sizeof(line), stdin)) // Mientras pueda leer una linea de stdin
    {
        if (line[0] == 'c' || line[0] == 'p') {
            continue; // Si la linea empieza con 'c' sigo leyendo
        }
        
        if (line[0] == 'e') // Si la linea empieza con 'e'
        {
            u32 v1 = 0, v2 = 0; // Inicializo las variables en 0
            sscanf(line, "e %d %d", &v1, &v2); // Leo los vertices de la arista
            // Ahora tengo que cargar la arista en el grafo
            // Primero tengo que buscar los vertices en el grafo
            struct Vertice *vertice1 = malloc(sizeof(struct Vertice)); // Asigno memoria para vertice1
            struct Vertice *vertice2 = malloc(sizeof(struct Vertice)); // Asigno memoria para vertice2

            if (vertice1 == NULL || vertice2 == NULL) {
                // Manejar error de asignación de memoria
                printf("Error: No se pudo asignar memoria para los vertices\n");
                return NULL;
                }

            vertice1->color = 0;
            vertice1->grado = 0;
            vertice1->id = v1;
            vertice2->id = v2;
            agregar_vecino(vertice1, vertice2);
            grafo->vertices[cant_vert_leidos] = *vertice1; // Asigno el vertice1 al grafo en orden de lectura
            agregar_lado(grafo, vertice1, vertice2, cant_vert_leidos); // Agrego la arista al grafo
            cant_vert_leidos++; // Aumento la cantidad de lineas
            }
        }

    return grafo; // Retorno el grafo
}

void DestruirGrafo(Grafo G){
    for (u32 i = 0; i < G->cant_vertices; i++){
        for (u32 j = 0; j < G->vertices[i].cant_vecinos; j++){
            free(G->vertices[i].vecinos[j]);
        }
        free(G->vertices[i].vecinos);
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
    u32 res = G->vertices[i].grado;
    return res;
}

color Color(u32 i,Grafo G){
    if(i < G->cant_vertices){
        color res = G->vertices[i].color;
        return res;
    } else {
        return (u32)(pow(2,32)-1); // Investigar como hacer potencias en C dios mio dios mio
    }
}

u32 Vecino(u32 j,u32 i,Grafo G){
    if(i >= G->cant_vertices || (i < G->cant_vertices) ^ (j >= Grado(i,G))){
        return (u32)(pow(2,32)-1);
    }
    u32 id_vecino = G->vertices[i].vecinos[j]->id;
    return id_vecino;
}

void AsignarColor(color x,u32 i,Grafo  G){
    if(i <= G->cant_vertices){
        G->vertices[i].color = x;
    }
}

void ExtraerColores(Grafo G,color* Color){
    for(u32 i = 0 ; i < G->cant_vertices ; i++){ //entre 0 y n-1
        Color[i] = G->vertices[i].color;
    }
}

void ImportarColores(color* Color,Grafo  G){
    for(u32 i = 0 ; i < G->cant_vertices ; i++){ //entre 0 y n-1
        G->vertices[i].color = Color[i];
    }
}