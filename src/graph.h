typedef struct Edge
{
  int src, dest;
} Edge;

typedef struct Graph
{
  int V, E;
  Edge *edge;
} Graph;