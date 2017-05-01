// O(|E| + |V|)

void Unweighted(Table T)
{
  Queue Q;
  Vertex V, W;

  Q = CreateQueue( NumVertex ); MakeEmpty(Q);

  Enqueue(S, Q);

  while(!IsEmpty(Q))
    {
      V = Dequeue( Q );
      T[V].Known = True;

      for each W adjacent to V
		 if (T[W].Dist == Infinity)
		   {
		     T[W].Dist = T[V].Dist + 1;
		     T[W].Path = V;
		     Enqueue(W, Q);
		   }
    }
  DisposeQueue( Q );
			       
}
