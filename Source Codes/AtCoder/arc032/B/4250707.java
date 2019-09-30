import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		UnionFindTree uft = new UnionFindTree(n);
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			uft.union(a - 1, b - 1);
		}
		System.out.println(uft.countBlock() - 1);
	}
	
	static class UnionFindTree {
		int[] parent;
		int[] rank;
		
		public UnionFindTree(int size) {
			parent = new int[size];
			rank = new int[size];
			for (int i = 0; i < size; i++) {
				parent[i] = i;
			}
		}
		
		public int find(int x) {
			if (parent[x] == x) {
				return x;
			} else {
				int v = find(parent[x]);
				parent[x] = v;
				return v;
			}
		}
		
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		
		public void union(int x, int y) {
			int rootX = find(x);
			int rootY = find(y);
			if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			} else if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			} else if (rootX != rootY) {
				parent[rootX] = rootY;
				rank[rootX]++;
			}
		}
		
		public int countBlock() {
			int count = 0;
			for (int i = 0; i < parent.length; i++) {
				if (parent[i] == i) {
					count++;
				}
			}
			return count;
		}
	}
}