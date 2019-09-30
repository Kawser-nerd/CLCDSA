import java.io.PrintWriter;
import java.util.*;
 
public class Main {
	static class Bridge {
		int a,b;
		int y;
		public Bridge(int a, int b, int y) {
			this.a = a;
			this.b = b;
			this.y = y;
		}
		
	}
	
	static class Person {
		int idx;
		int v;
		int y;
		public Person(int idx, int v, int y) {
			this.idx = idx;
			this.v = v;
			this.y = y;
		}
	}
	
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
		
		public boolean same(int x1, int y1, int x2, int y2) {
			return same(x1*xlen+y1, x2*xlen+y2);
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
		
		public void unite(int x1, int y1, int x2, int y2) {
			unite(x1*xlen+y1, x2*xlen+y2);
		}
	}
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		Bridge[] bridge = new Bridge[M];
		for(int i=0; i<M; i++)
			bridge[i] = new Bridge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
		
		int Q = sc.nextInt();
		Person[] person = new Person[Q];
		for(int i=0; i<Q; i++)
			person[i] = new Person(i, sc.nextInt()-1, sc.nextInt());
		
		Arrays.sort(bridge, new Comparator<Bridge>() {
			public int compare(Bridge b1, Bridge b2) {
				return -(b1.y-b2.y);
			}
		});
		Arrays.sort(person, new Comparator<Person>() {
			public int compare(Person p1, Person p2) {
				return -(p1.y-p2.y);
			}
		});
		
		UnionFind uf = new UnionFind(N);
		int[] cnt = new int[N];
		Arrays.fill(cnt, 1);
		
		int bi = 0;
		int pi = 0;
		int[] ans = new int[Q];
		while(pi<Q) {
			if(bi==M || bridge[bi].y <= person[pi].y) {
				ans[person[pi].idx] = cnt[uf.getRoot(person[pi].v)];
				pi++;
			} else {
				int a = bridge[bi].a;
				int b = bridge[bi].b;
				if(!uf.same(a, b)) {
					int cluster1 = cnt[uf.getRoot(a)];
					int cluster2 = cnt[uf.getRoot(b)];
					uf.unite(a, b);
					cnt[uf.getRoot(a)] = cluster1 + cluster2;
				}
				bi++;
			}
		}
		
		for(int i=0; i<Q; i++)
			pw.println(ans[i]);
		
		sc.close();
		pw.close();
	}
}