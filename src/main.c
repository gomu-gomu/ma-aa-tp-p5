#include <stdio.h>
#include "graph.h"

void afficherGraph(Graph *graph)
{
  int i;

  for (i = 0; i < graph->aretes; ++i)
  {
    printf("%d -> %d\n", graph->edge[i].src, graph->edge[i].dest);
  }
}

int main()
{
  int sommets = 5;
  int aretes = 7;

  Graph *graph = creerGraph(sommets, aretes);

  ajouterArete(graph, 0, 1, 0);
  ajouterArete(graph, 0, 4, 1);
  ajouterArete(graph, 1, 4, 2);
  ajouterArete(graph, 1, 3, 3);
  ajouterArete(graph, 1, 2, 4);
  ajouterArete(graph, 2, 3, 5);
  ajouterArete(graph, 3, 4, 6);

  printf("Affichage de graph :\n");
  afficherGraph(graph);

  printf("Affichage des composants :\n");
  trouverComposantsConnexes(graph);
  for (int i = 0; i < graph->sommets; i++)
  {
    printf("Le sommet %d est dans la composante %d\n", i, graph->composant[i]);
  }

  detruireGraph(graph);

  return 0;
}