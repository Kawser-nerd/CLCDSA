import java.util.Scanner;
class Pair{
	int x;
	int y;
	public Pair(int x,int y) {this.x=x;this.y=y;}
}
class UnionFind{
	int[] par;
	public UnionFind(int N) {
		par=new int[N];
		for(int i=0;i<N;i++)par[i]=i;
	}
	int root(int x) {
		if(par[x]==x)return x;
		return par[x]=root(par[x]);
	}
	void unite(int x,int y) {
		int rx=root(x);
		int ry=root(y);
		if(rx==ry)return;
		par[rx]=ry;
	}
	boolean same(int x,int y) {
		int rx=root(x);
		int ry=root(y);
		return rx==ry;
	}
}

public class Main {
	static int N;
	static int M;
	static int[]p;
	static Pair[]sw;
	static UnionFind uf;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt();
		M= sc.nextInt();
		p=new int[N+1];
		sw=new Pair[M+1];
		for(int i=1;i<=N;i++) {
			p[i]=sc.nextInt();
		}
		for(int i=1;i<=M;i++) {
			sw[i]=new Pair(sc.nextInt(),sc.nextInt());
		}
		uf=new UnionFind(N+1);

		for(int i=1;i<=M;i++) {
			Pair s=sw[i];
			uf.unite(s.x, s.y);
		}
		int sum=0;
		for(int i=1;i<=N;i++) {
			if(uf.same(i, p[i]))sum++;
		}
		System.out.println(sum);
	}
}