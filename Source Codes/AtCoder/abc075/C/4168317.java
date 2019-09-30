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
		int m = scanner.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		for(int i = 0; i < m; i++){
			a[i] = scanner.nextInt()-1;
			b[i] = scanner.nextInt()-1;
		}
		int count = 0;
		for(int i = 0; i < m; i++){
			UnionFind road = new UnionFind(n);
			Map<Integer,Integer> map = new HashMap<Integer,Integer>();
			for(int j = 0; j < m; j++){
				if(i == j) continue;
				road.unite(a[j],b[j]);
			}
			for(int j = 0; j < n; j++){
				if(!map.containsKey(road.find(j))){
					map.put(road.find(j),1);
				}else{
					map.put(road.find(j),map.get(road.find(j))+1);
				}
			}
			if(map.size() > 1){
				count++;
			}
		}
		System.out.println(count);
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