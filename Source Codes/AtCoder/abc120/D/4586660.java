import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		UnionFind uf = new UnionFind(num);
		int numEdge = sc.nextInt();
		int edge[][] = new int[numEdge][2];
		for(int i = 0; i < numEdge; i ++) {
			edge[i][0] = sc.nextInt() - 1;
			edge[i][1] = sc.nextInt() - 1;
		}

		long ans[] = new long[numEdge + 1];
		ans[numEdge] = (long) num * (num - 1) / 2;
		for(int i = numEdge - 1; i >= 0; i --) {
			ans[i] = ans[i + 1];
			if(!uf.same(edge[i][0], edge[i][1])) {
				ans[i] -= (long) uf.getSize(edge[i][0]) * uf.getSize(edge[i][1]);
				uf.unite(edge[i][0], edge[i][1]);
			}
		}

		for(int i = 1; i <= numEdge; i ++) {
			System.out.println(ans[i]);
		}
	}
}

class UnionFind {
	int parent[];
	int size[];

	public UnionFind(int num) {
		parent = new int[num];
		size = new int[num];
		for(int i = 0; i < num; i ++) {
			initNode(i);
		}
	}

	public void initNode(int i) {
		parent[i] = i;
		size[i] = 1;
	}

	public void unite(int x, int y) {
		int xRoot = getRoot(x);
		int yRoot = getRoot(y);
		if(size[yRoot] > size[xRoot]) {
			parent[xRoot] = yRoot;
			size[yRoot] += size[xRoot];
		}else {
			parent[yRoot] = xRoot;
			size[xRoot] += size[yRoot];
		}
	}

	public int getSize(int i) {
		return size[getRoot(i)];
	}

	public int getRoot(int i) {
		if(i != parent[i]) {
			parent[i] = getRoot(parent[i]);
		}
		return parent[i];
	}

	public boolean same(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
}