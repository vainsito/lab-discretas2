// Archivo main para probar las funciones de la biblioteca APIG24.h

#include "APIG24.h"
#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGrafo24.h"
int main()
{
    Grafo G = ConstruirGrafo();
    if (G == NULL)
    {
        printf("Error al construir el grafo\n");
        return 1;
    }

    printf("Numero de vertices: %d\n", NumeroDeVertices(G));
    printf("Numero de lados: %d\n", NumeroDeLados(G));
    printf("Delta: %d\n", Delta(G));

    for (u32 i = 0; i < NumeroDeVertices(G); i++)
    {
        u32 grado = G->vertices[i].grado;
        color color = G->vertices[i].color;
        printf("Grado del vertice %d: %d\n", i, grado);
        printf("Color del vertice %d: %d\n", i, color);
        printf("Vecinos del vertice %d: ", i);
        for (u32 j = 0; j < G->cant_vertices; j++)
        {
            for(u32 k = 0; k < G->vertices[j].cant_vecinos; k++)
            {
                printf("%d ", G->vertices[j].vecinos[k]->id);
            }
        }
        printf("\n");
    }

/*     color *colores = (color *)malloc(NumeroDeVertices(G) * sizeof(color));
    if (colores == NULL)
    {
        printf("Error al alocar memoria para los colores\n");
        DestruirGrafo(G);
        return 1;
    }

    ExtraerColores(G, colores);
    printf("Colores de los vertices: ");
    for (u32 i = 0; i < NumeroDeVertices(G); i++)
    {
        printf("%d ", colores[i]);
    }
    printf("\n");

    free(colores); */
    DestruirGrafo(G);
    return 0;
}