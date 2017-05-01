// O(|E| + |V|^2)


typedef int Vertex;

struct TableEntry
{
  List Header;  // Adjacency list
  int Known;
  DistType Dist;
  Vertex Path;
};

// vertices are numbered from 0

# define NotAVertex (-1)

typedef struct TableEntry Table[ NumVertex ];

// init

void InitTable ( Vertex Start, Graph G, Table T)
{
  int i;

  ReadGraph(G, T); // read graph somehow

  for ( i = 0; i < NumVertex; i++)
    {
      T[i].Known = False;
      T[i].Dist = Infinity;
      T[i].Path = NotAVertex;
    }
  T[ Start ].dist = 0;
}

// print shortest path to V after dijkstra has run
// assume that the path exists

void PrintPath( Vertex V, Table T)
{
  if (T[V].Path != NotAVertex)
    {
      PrintPath( T[V].Path, T);
      printf(" to ");
    }
  printf("%v", V);
}

void Dijkstra( Table T)
{
  Vertex V, W;

  for ( ; ; )
    {
      V = smallest unknown distance vertex;
      if (V == NotAVertex)
	break;

      T[V].Known = True;
      for each W Adjacent to V
		 if (!T[W].Known)
		   if (T[V].Dist + Cvw < T[W].Dist )
		     {
		       // update W
		       Decrease(T[W].Dist to T[V].Dist + Cvw);
		       T[W].Path = V;
		     }
    }
}
