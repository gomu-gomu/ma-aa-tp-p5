#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct Edge
{
  int src, dest;
} Edge;

typedef struct Graph
{
  Edge *edge;
  int *composant;
  int sommets, aretes;
} Graph;

Graph *creerGraph(int sommets, int aretes);

void detruireGraph(Graph *graph);

void ajouterArete(Graph *graph, int src, int dest, int i);

void DFS(Graph *graph, int sommet, int nomComposant, bool visite[]);

void trouverComposantsConnexes(Graph *graph);

#endif