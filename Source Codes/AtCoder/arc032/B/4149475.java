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
		UnionFind road = new UnionFind(n);
		for(int i = 0; i < m; i++){
			a[i] = scanner.nextInt()-1;
			b[i] = scanner.nextInt()-1;
			road.unite(a[i],b[i]);
		}
		Map<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i = 0; i < n; i++){
			if(!map.containsKey(road.find(i))){
				map.put(road.find(i),1);
			}else{
				map.put(road.find(i), map.get(road.find(i)+1));
			}
		}
		System.out.println(map.size()-1);
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