#include <stdio.h>
#include "graph.h"

int main()
{
  int sommets = 4;
  int aretes = 5;

  Graph *graph = creerGraph(sommets, aretes);
  ajouterArete(graph, 0, 1, 0);

  printf("Success!\n");
  return 0;
}