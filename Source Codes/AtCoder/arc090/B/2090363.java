import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		UnionFind uf = new UnionFind(n);
		boolean ok=true;
		for(int i=0;i<m;i++) {
			ok = ok && uf.union(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
		}
		if(ok) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

class UnionFind {
	int[] parent;
	int[] rank;
	int[] distanceFromParent;
	UnionFind(int num) {
		this.parent=new int[num];
		for(int i=0;i<num;i++) {
			this.parent[i]=i;
		}
		this.rank=new int[num];
		this.distanceFromParent=new int[num];
	}

	public int find(int num) {
		if(this.parent[num]==num) {
			return num;
		} else {
			return find(this.parent[num]);
		}
	}

	public int distanceFromRoot(int num) {
		if(this.parent[num]==num) {
			return 0;
		} else {
			return distanceFromRoot(this.parent[num])+distanceFromParent[num];
		}
	}

	public boolean union(int l, int r, int d) {
		int lRoot=find(l);
		int rRoot=find(r);

		if(lRoot==rRoot) {
			//check consistency
			if(distanceFromRoot(r)-distanceFromRoot(l)==d) {
				return true;
			} else {
				return false;
			}
		} else if(rank[lRoot]<rank[rRoot]) {
			parent[lRoot]=rRoot;
			distanceFromParent[lRoot]=-d-distanceFromRoot(l)+distanceFromRoot(r);
		} else if(rank[lRoot]>rank[rRoot]) {
			parent[rRoot]=lRoot;
			distanceFromParent[rRoot]=d-distanceFromRoot(r)+distanceFromRoot(l);
		} else {
			parent[rRoot]=lRoot;
			distanceFromParent[rRoot]=d-distanceFromRoot(r)+distanceFromRoot(l);
			rank[lRoot]++;
		}
		return true;
	}

}