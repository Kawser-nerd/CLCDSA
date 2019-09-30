import java.io.*;
import java.util.*;

public class Main {
	public static class UnionFind {
		int[] param;
		int[] rank;
		int N;
		int xlen;
		
		public UnionFind(int n) {
			N=n;
			param = new int[N];
			rank = new int[N];
			for(int i=0; i<N; i++)
				param[i] = i;
		}
		
		public void init() {
			for(int i=0; i<N; i++)
				param[i] = i;
			Arrays.fill(rank, 0);
		}
		
		public UnionFind(int x, int y) {
			this(x*y);
			xlen=y;
		}
		
		public boolean same(int a, int b) {
			return getRoot(a)==getRoot(b);
		}
		
		public int getRoot(int a) {
			if(param[a]==a) return a;
			else return (param[a] = getRoot(param[a]));
		}
		
		public void unite(int a, int b) {
			a = getRoot(a);
			b = getRoot(b);
			if(a==b)
				return;
			
			if(rank[a] < rank[b]) {
				param[a] = b;
			} else {
				param[b] = a;
				if(rank[a]==rank[b])
					rank[a]++;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int S = sc.nextInt()-1;
		ArrayList<ArrayList<Integer>> list = new ArrayList<>();
		for(int i=0; i<N; i++)
			list.add(new ArrayList<Integer>());
		for(int i=0; i<M; i++) {
			int u = sc.nextInt()-1;
			int v = sc.nextInt()-1;
			list.get(u).add(v);
			list.get(v).add(u);
		}
		
		UnionFind uf = new UnionFind(N+1);
		uf.unite(N, S);
		
		boolean[] ans = new boolean[N];
		for(int i=N-1; i>=0; i--) {
			for(int j : list.get(i))
				if(j>i)
					uf.unite(i, j);
			if(uf.same(N, i))
				ans[i] = true;
		}
		
		for(int i=0; i<N; i++)
			if(ans[i])
				pw.println(i+1);
		
		sc.close();
		pw.close();
	}
}