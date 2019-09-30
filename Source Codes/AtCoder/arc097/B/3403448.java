import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int p[] = new int[N];
		for(int i = 0; i < N; i++) {
			p[i] = sc.nextInt();
		}
		int x[] = new int[M];
		int y[] = new int[M];
		for(int  i = 0; i < M; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}
		
		UnionFind.init(N);
		for(int i = 0; i < M; i++) {
			UnionFind.unite(x[i] - 1, y[i] - 1);
		}
		
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(UnionFind.same(p[i] - 1, i)) {
				cnt++;
			}
		}
		
		System.out.println(cnt);
	}
}

class UnionFind {
	static int N;
	static int par[];
	static int rank[];
	public static void init(int n) {
		N = n;
		par = new int[N];
		rank = new int[N];
		for(int i = 0; i < N; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	public static int find(int x) {
		if(par[x] == x) {
			return x;
		} else {
			return par[x] = find(par[x]);
		}
	}
	
	public static void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
	
	public static boolean same(int x, int y) {
		return find(x) == find(y);
	}
}