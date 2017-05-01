// O (|E| + |V|)

void Topsort( Graph G )
{
  Queue Q;
  int Counter = 0;
  Vertex V, W;

  Q = CreateQueue( NumVertex ); MakeEmpty( Q );
  for each vertex V
	     if (Indegree[V] == 0)
	       Enqueue(V, Q);

  while(  !IsEmpty(Q) )
    {
      V = Dequeue(Q);
      TopNum[V] = ++Counter;
      for each W adjacent to V
		 if (--Indegree[W] == 0)
		   Enqueue(W, Q);
    }

  if (Counter != NumVertex)
    Error("Graph has a cycle");

  DisposeQueue(Q);
}
