package cj2016.r3;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc;
	PrintWriter pw;
	int N,S;
	Asteroid[] a;
	
	class Asteroid {
		double x,y,z;
		double vx,vy,vz;
		public Asteroid(double x, double y, double z, double vx, double vy, double vz) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.vx = vx;
			this.vy = vy;
			this.vz = vz;
		}
		
	}
	class UnionFind {
		int[] param;
		int[] rank;
		int N;
		int xlen;
		
		public UnionFind(int n) {
			N=n;
			param = new int[N];
			rank = new int[N];
			for(int i=0; i<N; i++) {
				param[i] = i;
				rank[i] = 0;
			}
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
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"C-small-attempt0";

		try {
			new C().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		N = sc.nextInt();
		S = sc.nextInt();
		a = new Asteroid[N];
		for(int i=0; i<N; i++)
			a[i] = new Asteroid(sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	
	public void solve() {
		double min = 0;
		double max = 10000;
		for(int i=0; i<60; i++) {
			double mid = (min+max)/2;
			if(ok(mid))
				max = mid;
			else
				min = mid;
		}
		
		println(min);
	}
	
	class Event {
		double time;
		int a,b;
		boolean isIn;
		public Event(double time, int a, int b, boolean isIn) {
			this.time = time;
			this.a = a;
			this.b = b;
			this.isIn = isIn;
		}
	}
	
	boolean ok(double d) {
		UnionFind uf = new UnionFind(N);
		
//		double[][] in = new double[N][N];
//		double[][] out = new double[N][N];
		
		ArrayList<Event> events = new ArrayList<>();
		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				double dx = a[j].x-a[i].x;
				double dy = a[j].y-a[i].y;
				double dz = a[j].z-a[i].z;
				double dvx = a[j].vx-a[i].vx;
				double dvy = a[j].vy-a[i].vy;
				double dvz = a[j].vz-a[i].vz;
				
				if(dx*dx+dy*dy+dz*dz<=d*d)
					uf.unite(i, j);
			}
		}
		
		Collections.sort(events, new Comparator<Event>() {
			public int compare(Event e1, Event e2) {
				return Double.compare(e1.time, e2.time);
			}
		});
		
		return uf.same(0, 1);
	}
}
