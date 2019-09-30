import java.util.*;

public class Main {

  public static void main(String args[]) {
    int rep = 1;
    if( args.length > 0 ) { rep = Integer.parseInt(args[0]); }
    (new Main()).__solve(rep);
  }

  void __solve(int rep) {

    try (
      Scanner cin = new Scanner(System.in);
    ) {

      for( int i = 0; i < rep; ++i ) {
        __solve(cin);
      }

    }

  }

  void __solve(Scanner cin) {

	  int N = cin.nextInt();
	  int K = cin.nextInt();
	  
	  int array[] = new int[N];
	  for( int i = 0; i < N; ++i ) {
		  array[i] = cin.nextInt() - 1;
	  }
	  
	  UnionFind uf = new UnionFind(N);
	  
	  for( int i = 0; i < K; ++i ) {
		  int L = cin.nextInt() - 1;
		  int R = cin.nextInt() - 1;
		  uf.merge(L, R);
	  }
	  
	  int ret = 0;
	  for( int i = 0; i < N; ++i ) {
		  if( uf.same(array[i], i) ) { ++ret; }
	  }
	  System.out.println(ret);
	  
  }

  class UnionFind {

	  private static final boolean ufDebug = false;
	  private static final int ROOT = -1;

	  private int group[];
	  private int size;
	  private int rest;

	  private int count[];

	  public UnionFind(int N) {
	    size = rest = N;
	    group = new int[size];
	    for(int i=0; i<N; ++i) { group[i] = ROOT; }
	    count = new int[size];
	  }

	  public int size() {
	    return rest;
	  }

	  public int find(int index) {
	    if( index < 0 || index >= size ) { return -1; }
	    int ret = index;
	    while( group[ret] != ROOT ) { ret = group[ret]; }
	    return ret;
	  }

	  public boolean same(int a, int b) {
	    return find(a) == find(b);
	  }

	  public void merge(int a, int b) {
	    int A = find(a);
	    int B = find(b);
	    if( A == B ) { return; }
	    if( count[A] <= count[B] ) { subMerge(A, B); }
	    else { subMerge(B, A); }
	  }

	  // merge A (small) into B (large)
	  private void subMerge(int A, int B) {
	    if( group[A] != ROOT || group[B] != ROOT ) {
	      if( ufDebug ) { throw new RuntimeException("Implementation Error !"); }
	      return;
	    }
	    group[A] = B;
	    count[B] += count[A] + 1;
	    --rest;
	  }

	}

}