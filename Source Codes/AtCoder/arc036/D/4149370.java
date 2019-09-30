import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Map;
import java.util.HashMap;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int q = scanner.nextInt();
		int[] w = new int[q];
		int[] x = new int[q];
		int[] y = new int[q];
		int[] z = new int[q];
		for(int i = 0; i < q; i++){
			//w??????
			w[i] = scanner.nextInt();
			//x[i]??
			x[i] = scanner.nextInt() - 1;
			//y[i]??
			y[i] = scanner.nextInt() - 1;
 			//x[i]?y[i]????
			z[i] = scanner.nextInt();
 		}
		UnionFind road = new UnionFind(2 * n);
		for(int i = 0; i < q; i++){
			if(w[i] == 1){
				if(z[i] % 2 == 0){
					road.unite(x[i], y[i]);
					road.unite(x[i]+n, y[i]+n);
				}else if(z[i] % 2 != 0){
					road.unite(x[i], y[i]+n);
					road.unite(x[i]+n, y[i]);
				}
			}else if(w[i] == 2){
				if(road.same(x[i],y[i])){
					System.out.println("YES");
				}else{
					System.out.println("NO");
				}
			}
		}
	}

	public static class UnionFind{
		int n;
		int[] parent;
		int[] rank;
		UnionFind(int n){
			this.n = n;
			parent = new int[n];
			rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
				rank[i] = 0;
			}
		}
		public void unite(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;

			if(rank[x] < rank[y]){
				parent[x] = y;
			}else{
				parent[y] = x;
				if(rank[x] == rank[y]) rank[x]++;
			}
		}
		public int find(int x){
			if(parent[x] == x){
				return x;
			}else{
				return parent[x] = find(parent[x]);
			}
		}
		public boolean same(int x, int y){
			return find(x) == find(y);
		}
	}
}