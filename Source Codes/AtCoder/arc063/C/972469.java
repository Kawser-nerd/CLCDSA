import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class Main {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	/// MAIN CODE
	public void run() throws IOException {
//		int TEST_CASE = Integer.parseInt(new String(io.nextLine()).trim());
		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			g = new SimpleAdjListGraph(n, 2*n);
			for (int i = 0; i < n - 1; i++) {
				int a = io.nextInt() - 1;
				int b = io.nextInt() - 1;
				g.addEdge(a, b);
				g.addEdge(b, a);
			}
			int r = -1;
			val = new int[n];
			Arrays.fill(val, -INF);
			int K = io.nextInt();
			for (int i = 0; i < K; i++) {
				int v = io.nextInt() - 1;
				val[v] = io.nextInt();
				r = v;
			}
			int[][] dp = g.bfs(r);
//			for (int i = 0; i < n; i++) if (val[i] != -1) {
//				if (Math.abs(val[i] - val[r]) > dp[0][i]) {
//					io.out.println("No");
//					return;
//				}
//				if (Math.abs(val[i] - val[r]) % 2 != dp[0][i] % 2) {
//					io.out.println("No");
//					return;
//				}
//			}
			range = new int[n][];
			prev = dp[1];
			dfs2(r);
			if(!dfs(r)) {
				io.out.println("No");
				return;
			}
			io.out.println("Yes");
			for(int v : val) io.out.println(v);
		}
	}
	
	final int INF = 1<<29;
	
	int[] val;
	int[][] range;
	SimpleAdjListGraph g;
	int[] prev;
	boolean dfs(int v) {
		if(val[v] == -INF) {
			range[v][0] = Math.max(range[v][0], val[prev[v]] - 1);
			range[v][1] = Math.min(range[v][1], val[prev[v]] + 1);
			boolean ok = false;
			for (int i = -1; i <= 1; i += 2) {
				val[v] = val[prev[v]] + i;
				if (val[v] >= range[v][0] && val[v] <= range[v][1]) {
					ok = true;
					break;
				}
			}
			if (!ok) {
//				dump(v + 1, val[v], range);
				return false;
			}
		}
		if (!(val[v] >= range[v][0] && val[v] <= range[v][1])) {
			return false;
		}
		for(int e = g.head[v]; e != -1; e = g.next[e]) {
			int t = g.to[e];
			if (t == prev[v]) continue;
			if (!dfs(t)) {
				return false;
			}
			if (Math.abs(val[v] - val[t]) != 1) {
				return false;
			}
		}
		return true;
	}
	int[] dfs2(int v) {
		if (val[v] != -INF) range[v] = new int[]{val[v], val[v]};
		else range[v] = new int[]{-INF, INF};
		for(int e = g.head[v]; e != -1; e = g.next[e]) {
			int t = g.to[e];
			if (t == prev[v]) continue;
			int[] rr = dfs2(t);
			range[v][0] = Math.max(range[v][0], rr[0] - 1);
			range[v][1] = Math.min(range[v][1], rr[1] + 1);
		}
		return range[v];
	}

	static
	class SimpleAdjListGraph {
		int m, V, E;
		int[] head, next, to;
	
		public SimpleAdjListGraph(int V, int E) {
			head = new int[V];
			next = new int[E];
			to = new int[E];
			this.V = V;
			this.E = E;
			clear();
		}
	
		public void clear() {
			m = 0;
			Arrays.fill(head, -1);
		}
	
		public void addEdge(int s, int t) {
			next[m] = head[s];
			head[s] = m;
			to[m++] = t;
		}
		

		public int[][] bfs(final int src) {
			final int[] dist = new int[head.length];
			final int[] prev = new int[head.length];
			final int[] q = new int[2 * head.length + 10];
			int s = 0, t = 0;
			
			Arrays.fill(dist, -1);
			Arrays.fill(prev, -1);
			dist[src] = 0;
			q[t++] = src;
			while(s != t) {
				final int v = q[s++];
				for(int e = head[v]; e != -1; e = next[e]) {
					final int u = to[e];
					if(dist[u] == -1) {
						dist[u] = dist[v] + 1;
						prev[u] = v;
						q[t++] = u;
					}
				}
			}
			return new int[][] { dist, prev };
		}
	}


	/// TEMPLATE
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }

	void printArrayLn(int[] xs) { for(int i = 0; i < xs.length; i++) io.out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	void printArrayLn(long[] xs) { for(int i = 0; i < xs.length; i++) io.out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	
	static void dump(Object... o) { System.err.println(Arrays.deepToString(o)); } 
	
	void main() throws IOException {
		//		IOFast.setFileIO("rle-size.in", "rle-size.out");
		try { run(); }
		catch (EndOfFileRuntimeException e) { }
		io.out.flush();
	}
	public static void main(String[] args) throws IOException { new Main().main(); }
	
	static class EndOfFileRuntimeException extends RuntimeException {
		private static final long serialVersionUID = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void setFileIn(String ins) throws IOException { in.close(); in = new BufferedReader(new FileReader(ins)); }
		void setFileOut(String outs) throws IOException { out.flush(); out.close(); out = new PrintWriter(new FileWriter(outs)); }
		void setFileIO(String ins, String outs) throws IOException { setFileIn(ins); setFileOut(outs); }

		private static int pos, readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static char[] str = new char[500*8*2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static { for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; } isDigit['-'] = true; isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true; isLineSep['\r'] = isLineSep['\n'] = true; }
		public int read() throws IOException { if(pos >= readLen) { pos = 0; readLen = in.read(buffer); if(readLen <= 0) { throw new EndOfFileRuntimeException(); } } return buffer[pos++]; }
		public int nextInt() throws IOException { int len = 0; str[len++] = nextChar(); len = reads(len, isSpace); int i = 0; int ret = 0; if(str[0] == '-') { i = 1; } for(; i < len; i++) ret = ret * 10 + str[i] - '0'; if(str[0] == '-') { ret = -ret; } return ret; }
		public long nextLong() throws IOException { int len = 0; str[len++] = nextChar(); len = reads(len, isSpace); int i = 0; long ret = 0; if(str[0] == '-') { i = 1; } for(; i < len; i++) ret = ret * 10 + str[i] - '0'; if(str[0] == '-') { ret = -ret; } return ret; }
		public char nextChar() throws IOException { while(true) { final int c = read(); if(!isSpace[c]) { return (char)c; } } }
		int reads(int len, boolean[] accept) throws IOException { try { while(true) { final int c = read(); if(accept[c]) { break; } if(str.length == len) { char[] rep = new char[str.length * 3 / 2]; System.arraycopy(str, 0, rep, 0, str.length); str = rep; } str[len++] = (char)c; } } catch(EndOfFileRuntimeException e) { ; } return len; }
		int reads(char[] cs, int len, boolean[] accept) throws IOException { try { while(true) { final int c = read(); if(accept[c]) { break; } cs[len++] = (char)c; } } catch(EndOfFileRuntimeException e) { ; } return len; }
		public char[] nextLine() throws IOException { int len = 0; str[len++] = nextChar(); len = reads(len, isLineSep); try { if(str[len-1] == '\r') { len--; read(); } } catch(EndOfFileRuntimeException e) { ; } return Arrays.copyOf(str, len); }
		public String nextString() throws IOException { return new String(next()); }
		public char[] next() throws IOException { int len = 0; str[len++] = nextChar(); len = reads(len, isSpace); return Arrays.copyOf(str, len); }
//		public int next(char[] cs) throws IOException { int len = 0; cs[len++] = nextChar(); len = reads(cs, len, isSpace); return len; }
		public double nextDouble() throws IOException { return Double.parseDouble(nextString()); }
		public long[] nextLongArray(final int n) throws IOException { final long[] res = new long[n]; for(int i = 0; i < n; i++) { res[i] = nextLong(); } return res; }
		public int[] nextIntArray(final int n) throws IOException { final int[] res = new int[n]; for(int i = 0; i < n; i++) { res[i] = nextInt(); } return res; }
		public int[][] nextIntArray2D(final int n, final int k) throws IOException { final int[][] res = new int[n][]; for(int i = 0; i < n; i++) { res[i] = nextIntArray(k); } return res; }
		public int[][] nextIntArray2DWithIndex(final int n, final int k) throws IOException { final int[][] res = new int[n][k+1]; for(int i = 0; i < n; i++) { for(int j = 0; j < k; j++) { res[i][j] = nextInt(); } res[i][k] = i; } return res; }
		public double[] nextDoubleArray(final int n) throws IOException { final double[] res = new double[n]; for(int i = 0; i < n; i++) { res[i] = nextDouble(); } return res; }
	}
}