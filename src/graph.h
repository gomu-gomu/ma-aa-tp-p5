#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge
{
  int src, dest;
} Edge;

typedef struct Graph
{
  int sommets, aretes;
  Edge *edge;
} Graph;

Graph *creerGraph(int sommets, int aretes);

void ajouterArete(Graph *graph, int src, int dest, int i);

#endif