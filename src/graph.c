#include <stdlib.h>
#include "graph.h"

Graph *creerGraph(int sommets, int aretes)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));

  graph->sommets = sommets;
  graph->aretes = aretes;
  graph->edge = (Edge *)malloc(aretes * sizeof(Edge));

  return graph;
}

void ajouterArete(Graph *graph, int src, int dest, int i)
{
  graph->edge[i].src = src;
  graph->edge[i].dest = dest;
}