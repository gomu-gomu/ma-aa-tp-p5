#include <stdlib.h>
#include <stdbool.h>

#include "graph.h"

Graph *creerGraph(int sommets, int aretes)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));

  graph->aretes = aretes;
  graph->sommets = sommets;
  graph->edge = (Edge *)malloc(aretes * sizeof(Edge));
  graph->composant = (int *)malloc(aretes * sizeof(int));

  return graph;
}

void detruireGraph(Graph *graph)
{
  if (graph != NULL)
  {
    graph->aretes = 0;
    graph->sommets = 0;

    if (graph->edge != NULL)
    {
      free(graph->edge);
    }

    if (graph->composant != NULL)
    {
      free(graph->composant);
    }

    free(graph);
  }
}

void ajouterArete(Graph *graph, int src, int dest, int i)
{
  graph->edge[i].src = src;
  graph->edge[i].dest = dest;
}

void DFS(Graph *graph, int sommet, int numComposant, bool visite[])
{
  visite[sommet] = true;
  graph->composant[sommet] = numComposant;

  for (int i = 0; i < graph->aretes; i++)
  {
    if (graph->edge[i].src == sommet && !visite[graph->edge[i].dest])
      DFS(graph, graph->edge[i].dest, numComposant, visite);
  }
}

void trouverComposantsConnexes(Graph *graph)
{
  int visite[graph->sommets];
  for (int i = 0; i < graph->sommets; i++)
  {
    visite[i] = false;
  }

  int numComposant = 0;
  for (int i = 0; i < graph->sommets; i++)
  {
    if (!visite[i])
    {
      DFS(graph, i, numComposant, visite);
      numComposant++;
    }
  }
}