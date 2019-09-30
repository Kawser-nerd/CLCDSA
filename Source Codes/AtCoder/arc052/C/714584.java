import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/C1";

	FastScanner in;
	PrintWriter out;
	
	final int INF = 1 << 25;
	class Edge implements Comparable<Edge> {
		int to;
		int type;

		Edge(int to, int type) {
			this.to = to;
			this.type = type;
		}

		public int compareTo(Edge s) {
			return type - s.type;
		}

		public String dump(String symbol) {
			return symbol + " : " + to + " " + type;
		}
	}
	
	class State {
		int u;
		int mcnt;
		int dist;
		
		State(int u, int mcnt, int dist) {
			this.u = u;
			this.mcnt = mcnt;
			this.dist = dist;
		}
	}
	
	int[] bfs(ArrayList<Edge>[] g, int from) {
		int n = g.length;
		int[] dist = new int[n];
		Arrays.fill(dist, INF);
		
		PriorityQueue<State> pq = new PriorityQueue<>(new Comparator<State>() {
			@Override
			public int compare(State o1, State o2) {
				if (o1.mcnt != o2.mcnt) return o1.mcnt - o2.mcnt;
				return o1.dist - o2.dist; 
			}			
		});
		pq.add(new State(from, 0, 0));
		
		while (!pq.isEmpty()) {
			State p = pq.poll();	
			if (dist[p.u] <= p.dist) continue;
			dist[p.u] = p.dist;
			for (Edge e : g[p.u]) {
				int ncost = dist[p.u];
				if (e.type == 0) {
					ncost += 1;
					if (ncost < dist[e.to]) 
						pq.add(new State(e.to, p.mcnt, ncost));
				} else {
					ncost += p.mcnt + 1;
					if (ncost < dist[e.to]) 
						pq.add(new State(e.to, p.mcnt + 1, ncost));
				}
			}
		}
		return dist;
	}
	
	void solve() {
		int N = in.nextInt();
		int M = in.nextInt();
		ArrayList<Edge>[] g = new ArrayList[N];
		for (int i = 0; i < N; i++)
			g[i] = new ArrayList<Edge>();
		for (int i = 0; i < M; i++) {
			int type = in.nextInt();
			int u = in.nextInt(), v = in.nextInt();
			g[u].add(new Edge(v, type));
			g[v].add(new Edge(u, type));
		}
		
		int[] res = bfs(g, 0);
		for (int i = 0; i < N; i++) {
			System.out.println(res[i]);
		}
	}

	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);

		solve();
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			// stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.