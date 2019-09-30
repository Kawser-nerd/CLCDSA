import java.util.*;
public class Main {
	
	public static class unionfind{
		int[] parent;
		int[] rank;
		int[] size;
		public unionfind(int n){
			this.parent = new int[n+1];
			this.rank = new int[n+1];
			this.size = new int[n+1];
			for(int i = 1; i <= n; i++) set(i);
		}
		public void set(int i) {
			parent[i] = i;
			rank[i] = 0;
			size[i] = 1;
		}
		public int find(int i) {
			if (i == parent[i])
				return parent[i];
			else
				return parent[i] = find(parent[i]);
			
		}
		public void unite(int x, int y) {
			int xroot = find(x);
			int yroot = find(y);
			if(xroot == yroot)
				return;
			if(rank[xroot] > rank[yroot]) {
				parent[yroot] = xroot;
				size[xroot] += size[yroot];
			}
			else if(rank[xroot] < rank[yroot]) {
				parent[xroot] = yroot;
				size[yroot] += size[xroot];
			}
			else {
				parent[yroot] = xroot;
				size[xroot] += size[yroot];
				rank[xroot]++;
			}
		}
		public int getnumber(int i) {
			return size[find(i)];
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] a = new int[M];
		int[] b = new int[M];
		int ans = 0;
		for(int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		for(int i = 0; i < M; i++) {
			unionfind u = new unionfind(N);
			for(int j = 0; j < M; j++) {
				if(j != i)
					u.unite(a[j], b[j]);
			}
			if(u.getnumber(1) != N)
				ans += 1;
		}
		System.out.println(ans);
	}

}