import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

import java.io.*;

public class Main {
	
	int H, W;
	char[][] s;
	void solve() {
		H = sc.nextInt();
		W = sc.nextInt();
		s = new char[H][];
		for (int i = 0; i < H; i++) s[i] = sc.next().toCharArray();

		int rS = -1, cS = -1;
		int rT = -1, cT = -1;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (s[i][j] == 'S') { rS = i; cS = j; }
				if (s[i][j] == 'T') { rT = i; cT = j; }
			}
		if (rS == rT || cS == cT) {
			out.println(-1);
			return ;
		}
		
		{ char[] t = s[rS]; s[rS] = s[0]; s[0] = t; }
		{ char[] t = s[rT]; s[rT] = s[H-1]; s[H-1] = t; }
		for (int i = 0; i < H; i++) {
			char t = s[i][cS]; s[i][cS] = s[i][0]; s[i][0] = t; 
		}
		for (int i = 0; i < H; i++) {
			char t = s[i][cT]; s[i][cT] = s[i][W-1]; s[i][W-1] = t; 
		}
//		for (int i = 0; i < H; i++) {
//			tr(new String(s[i]));
//		}
		
		boolean[][] vis1 = new boolean[H][W];
		boolean[][] vis2 = new boolean[H][W];
		dfs(0, 0, vis1);
		dfs(H-1, W-1, vis2);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (s[i][j] == 'o') {
					if (!vis2[i][j] || !vis2[i][j]) s[i][j] = '.';
				}
			}
		}
//		for (int i = 0; i < H; i++) {
//			tr(new String(s[i]));
//		}
		
		V[][][] vs = new V[H][W][2];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				V from = new V();
				V to = new V();
				vs[i][j][0] = from;
				vs[i][j][1] = to;
				from.add(to, 1);
			}
		}
		make_graph(vs);
		
		int ans = dinic(vs[0][0][1], vs[H-1][W-1][0]);
		out.println(ans);
	}
	
	void make_graph(V[][][] vs) {
		int[] q = new int[H * W * 2];
		boolean[][] vis = new boolean[H][W];
		
		int a = 0, b = 0;
		q[b++] = 0;
		q[b++] = 0;
		vis[0][0] = true;
		while (a < b) {
			int r = q[a++];
			int c = q[a++];
			if (s[r][c] == 'T') continue;
			for (int i = 0; i < H; i++) if (s[i][c] == 'o' || s[i][c] == 'T') {
				vs[r][c][1].add(vs[i][c][0], INF);
				if (!vis[i][c]) {
					vis[i][c] = true;
					q[b++] = i; q[b++] = c;
				}
			}
			for (int j = 0; j < W; j++) if (s[r][j] == 'o' || s[r][j] == 'T') {
				vs[r][c][1].add(vs[r][j][0], INF);
				if (!vis[r][j]) {
					vis[r][j] = true;
					q[b++] = r; q[b++] = j;
				}
				dfs(r, j, vis);
			}
		}
	}
	
	void dfs(int r, int c, boolean[][] vis) {
		if (vis[r][c]) return;
		vis[r][c] = true;
		for (int i = 0; i < H; i++) if (s[i][c] == 'o') {
			dfs(i, c, vis);
		}
		for (int j = 0; j < W; j++) if (s[r][j] == 'o') {
			dfs(r, j, vis);
		}
	}

	static final int INF = 1001001001;
	
	
	int dinic(V s, V t) {
		int flow = 0;
		for (int p = 1;; p++) {
			Queue<V> que = new LinkedList<V>();
			s.level = 0;
			s.p = p;
			que.offer(s);
			while (!que.isEmpty()) {
				V v = que.poll();
				v.iter = v.es.size() - 1;
				for (E e : v.es)
					if (e.to.p < p && e.cap > 0) {
						e.to.level = v.level + 1;
						e.to.p = p;
						que.offer(e.to);
					}
			}
			if (t.p < p) return flow;
			for (int f; (f = dfs(s, t, INF)) > 0;) flow += f;
		}
	}

	int dfs(V v, V t, int f) {
		if (v == t) return f;
		for (; v.iter >= 0; v.iter--) {
			E e = v.es.get(v.iter);
			if (v.level < e.to.level && e.cap > 0) {
				int d = dfs(e.to, t, Math.min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					e.rev.cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	class V {
		ArrayList<E> es = new ArrayList<E>();
		int level, p, iter;
		
		void add(V to, int cap) {
			E e = new E(to, cap);
			E rev = new E(this, 0);
			e.rev = rev;
			rev.rev = e;
			es.add(e);
			to.es.add(rev);
		}
	}

	class E {
		V to;
		E rev;
		int cap;

		E(V to, int cap) {
			this.to = to;
			this.cap = cap;
		}
	}
	static void tr(Object... os) { System.err.println(deepToString(os)); }
	static void tr(int[][] as) { for (int[] a : as) tr(a); }

	void print(int[] a) {
		out.print(a[0]);
		for (int i = 1; i < a.length; i++) out.print(" " + a[i]);
		out.println();
	}

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	MyScanner sc = null;
	PrintWriter out = null;
	public void run() throws Exception {
		sc = new MyScanner(System.in);
		out = new PrintWriter(System.out);
		for (;sc.hasNext();) {
			solve();
			out.flush();
		}
		out.close();
	}

	class MyScanner {
		String line;
		BufferedReader reader;
		StringTokenizer tokenizer;

		public MyScanner(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
		public void eat() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					line = reader.readLine();
					if (line == null) {
						tokenizer = null;
						return;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		public String next() {
			eat();
			return tokenizer.nextToken();
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		public boolean hasNext() {
			eat();
			return (tokenizer != null && tokenizer.hasMoreElements());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
	}
}