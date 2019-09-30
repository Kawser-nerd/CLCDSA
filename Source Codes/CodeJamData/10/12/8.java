import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	String fn = "B-large";

	class State {
		int f, last;
		ArrayList<Edge> es;
		int dist;

		public State(int f, int last) {
			this.f = f;
			this.last = last;
			es = new ArrayList<Edge>();
			dist = Integer.MAX_VALUE;
		}

	}

	class Edge {
		int w;
		State to;

		public Edge(int w, State to) {
			this.w = w;
			this.to = to;
		}

	}

	void solve2() throws IOException {
		int d = nextInt();
		int L = nextInt();
		int m = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		State[][] st = new State[n + 1][256];
		for (int i = 0; i < st.length; i++) {
			for (int j = 0; j < st[i].length; j++) {
				st[i][j] = new State(i, j);
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 255; j++) {
				if (i > 0) {
					st[i - 1][j].es.add(new Edge(d, st[i][j]));
				}
				for (int k = 0; k <= 255; k++) {
					if (Math.abs(j - k) <= m) {
						st[i][k].es.add(new Edge(L, st[i][j]));
					}
				}
				if (i > 0) {
					for (int k = 0; k <= 255; k++) {
						if (Math.abs(j - k) <= m) {
							st[i - 1][k].es.add(new Edge(Math.abs(a[i - 1] - j), st[i][j]));
						}
					}
				}
			}
			if (i > 0) {
				for (int k = 0; k <= 255; k++) {
					if (Math.abs(a[i - 1] - k) <= m) {
						st[i - 1][k].es.add(new Edge(0, st[i][a[i - 1]]));
					}
				}
			}
		}
		for (int i = 0; i < st[0].length; i++) {
			st[0][0].es.add(new Edge(0, st[0][i]));
			st[st.length - 1][i].es.add(new Edge(0, st[st.length - 1][0]));
		}
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		pq.add(new Pair(st[0][0], 0));
		st[0][0].dist = 0;
		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			State s = p.st;
			// System.err.println(s.f + " " + s.last + "  = " + s.dist);
			if (p.dist != s.dist) {
				continue;
			}
			for (Edge e : s.es) {
				if (e.to.dist > s.dist + e.w) {
					e.to.dist = s.dist + e.w;
					pq.add(new Pair(e.to, e.to.dist));
				}
			}
		}
		out.println(st[st.length - 1][0].dist);
	}

	class Pair implements Comparable<Pair> {
		State st;
		int dist;

		public Pair(State st, int dist) {
			super();
			this.st = st;
			this.dist = dist;
		}

		@Override
		public int compareTo(Pair p) {
			return dist - p.dist;
		}

	}

	void solve() throws IOException {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			System.err.println(i);
			out.print("Case #" + (i + 1) + ": ");
			solve2();
		}

	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			br = new BufferedReader(new FileReader(fn + ".in"));
			out = new PrintWriter(fn + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(123);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
			throw new AssertionError();
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) {
		new B().run();
	}
}
