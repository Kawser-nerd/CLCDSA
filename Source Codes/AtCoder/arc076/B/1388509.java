import java.util.*;

public class Main {
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

	public static class Point {
		int idx;
		int x, y;

		public Point(int idx, int x, int y) {
			this.idx = idx;
			this.x = x;
			this.y = y;
		}
	}
	public static class Road {
		int cost;
		int a, b;
		
		public Road(int cost, int a, int b) {
			this.cost = cost;
			this.a = a;
			this.b = b;
		}

	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		Point[] p = new Point[N];
		for(int i=0; i<N; i++)
			p[i] = new Point(i, sc.nextInt(), sc.nextInt());
		
		ArrayList<Road> roads = new ArrayList<>();
		
		Arrays.sort(p, new Comparator<Point>() {
			public int compare(Point p1, Point p2) {
				return p1.x - p2.x;
			}
		});
		for(int i=0; i<N-1; i++)
			roads.add(new Road(p[i+1].x - p[i].x, p[i].idx, p[i+1].idx));
		
		Arrays.sort(p, new Comparator<Point>() {
			public int compare(Point p1, Point p2) {
				return p1.y - p2.y;
			}
		});
		for(int i=0; i<N-1; i++)
			roads.add(new Road(p[i+1].y - p[i].y, p[i].idx, p[i+1].idx));
		
		Collections.sort(roads, new Comparator<Road>() {
			public int compare(Road r1, Road r2) {
				return r1.cost - r2.cost;
			}
		});
		
		long ans = 0;
		
		UnionFind uf = new UnionFind(N);
		for(Road r : roads) {
			if(!uf.same(r.a, r.b)) {
				uf.unite(r.a, r.b);
				ans += r.cost;
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
}