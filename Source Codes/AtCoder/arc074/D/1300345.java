import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/D4";

	FastScanner in;
	PrintWriter out;
	
	int N, M;
	int toNode(int y, int x) {
		return y * M + x;
	}
	
	/*------------Dinic(Max Flow)------------*/
	class Dinic {
		class Edge {
			int to, cap;
			int flow = 0;
			Edge rev;
			
			Edge(int to, int cap) {
				this.to = to;
				this.cap = cap;
			}
			
			void setRevEdge(Edge rev) {
				this.rev = rev;
			}
		}
		
		int N;
		int tank;
		int[] ptr, Q, dist;
		
		ArrayList<Edge>[] g;

		public Dinic(int N) {
			this.N = N;
			g = new ArrayList[N + 2];
			for (int i = 0; i < N + 2; i++)
				g[i] = new ArrayList<Edge>();
			
			ptr = new int[N + 2];
			Q = new int[N + 2];
			dist = new int[N + 2];
		}
		
		public void addEdge(int from, int to, int cap) {
			Edge e1 = new Edge(to, cap);
			Edge e2 = new Edge(from, 0);
			e1.setRevEdge(e2);
			e2.setRevEdge(e1);
			g[from].add(e1);
			g[to].add(e2);
		}
		
		boolean dinic_bfs(int src)	{
			Arrays.fill(dist, -1);
			dist[src] = 0;
			int sizeQ = 0;
			Q[sizeQ++] = src;
			for (int i = 0; i < sizeQ; i++) {
				int u = Q[i];
				for (Edge e : g[u]) {
					if (dist[e.to] < 0 && e.flow < e.cap) {
						dist[e.to] = dist[u] + 1;
						Q[sizeQ++] = e.to;
					}
				}
			}
			return dist[tank] >= 0;
		}
		
		int dinic_dfs(int u, int f) {
			if (u == tank) return f;
			for ( ; ptr[u] < g[u].size(); ptr[u]++) {
				Edge e = g[u].get(ptr[u]);
				if (dist[e.to] == dist[u] + 1 && e.flow < e.cap) {
					int df = dinic_dfs(e.to, Math.min(f, e.cap - e.flow));
					if (df > 0) {
						e.flow += df;
						e.rev.flow -= df;
						return df;
					}
				}
			}
			
			return 0;
		}
		
		public int getMaxFlow(int src, int tank) {
			this.tank = tank;
			
			int res = 0;
			while (dinic_bfs(src)) {
				Arrays.fill(ptr, 0);
				while (true) {
					int df = dinic_dfs(src, Integer.MAX_VALUE);
					if (df == 0) break;
					res += df;
				}
			}
			
			return res;
		}

		public void addBiEdge(int from, int to, int cap) {
			Edge e1 = new Edge(to, cap);
			Edge e2 = new Edge(from, cap);
			e1.setRevEdge(e2);
			e2.setRevEdge(e1);
			g[from].add(e1);
			g[to].add(e2);
		}
	}
	/*-----------------end---------------------*/
		
	final int INF = 100000;
	public void solve() {
		N = in.nextInt();
		M = in.nextInt();
		String[] map = in.nextStringArray(N);
		
		Dinic dinic = new Dinic(N + M);
		
		int s = N + M, t = N + M + 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i].charAt(j) == '.') continue; 
				
				if (map[i].charAt(j) == 'S') {
					dinic.addEdge(s, i, INF);
					dinic.addEdge(s, j + N, INF);
				} else if (map[i].charAt(j) == 'T') {
					dinic.addEdge(i, t, INF);
					dinic.addEdge(j + N, t, INF);
				} else {
					dinic.addBiEdge(i, j + N, 1);
				}
			}
		}
		long res = dinic.getMaxFlow(s, t);
		System.out.println(res >= INF ? -1 : res);
	}
	
	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				// TODO ??????? catch ????
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
			//stream = new FileInputStream(new File("dec.in"));

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