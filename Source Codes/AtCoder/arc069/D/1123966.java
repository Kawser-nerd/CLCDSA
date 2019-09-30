import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;

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
			int[] x = new int[n];
			int[] y = new int[n];
			int[][] pos = new int[n*2][];
			for (int i = 0; i < n; i++) {
				x[i] = io.nextInt();
				y[i] = io.nextInt();
//				x[i] = random.nextInt((int)1e9)+1;
//				y[i] = random.nextInt((int)1e9)+1;
				pos[2*i+0] = new int[]{x[i], 2*i+0};
				pos[2*i+1] = new int[]{y[i], 2*i+1};
			}
			
			Arrays.sort(pos, (a,b)->a[0]-b[0]);
			int[] idx = new int[2*n];
			int[] pos2 = new int[n*2];
			for (int i = 0; i < 2*n; i++) {
				idx[pos[i][1]] = i;
				pos2[i] = pos[i][0];
			}

			int times = 0;
			int m = Integer.highestOneBit(pos.length) << 1;
			sat = new Sat2(2*m-1);
			int low = 0, high = (int)1e9;
			while (high - low > 1) {
				int mid = (low + high) / 2;
				
				sat.clear();
				if (times++ == 16) System.gc();
				
				for (int i = 0; i < m - 1; i++) {
					for (int j = 1; j <= 2; j++) {
						final int c = 2*i+j;
						// ??? => ???
						// A => B, not(A) v B
						// not(p) => not(c)
						// p v not(c)
//						sat.Or(i, sat.Not(c));
//						sat.Or(sat.Not(c), i);
						sat.Implication(sat.Not(i), sat.Not(c));
					}
				}
				
				for (int i = 0; i < idx.length; i += 2) {
					// x[i], y[i]???????????????
					sat.Or(idx[i+0] + m - 1, idx[i+1] + m - 1);
					sat.Or(sat.Not(idx[i+0] + m - 1), sat.Not(idx[i+1] + m - 1));
				}
				
				for (int i = 0; i < pos.length; i++) {
					int j = lowerBound(pos2, pos2[i] - mid + 1);
					int k = upperBound(pos2, pos2[i] + mid - 1);
					addEdge(j, i, 0, m, 0, i+m-1);
					addEdge(i+1, k, 0, m, 0, i+m-1);
				}
				if (sat.satisfy()) low = mid;
				else high = mid;
			}
			io.out.println(low);
		}
	}
	
	Sat2 sat;
	void addEdge(int l, int r, int curL, int curR, int k, int i) {
		if (l >= curR || r <= curL) return;
		if (l <= curL && curR <= r) {
			// i => not(k)
//			sat.Or(sat.Not(i), sat.Not(k));
			sat.Implication(i, sat.Not(k));
			return;
		}
		final int curM = (curL + curR) / 2;
		addEdge(l, r, curL, curM, 2*k+1, i);
		addEdge(l, r, curM, curR, 2*k+2, i);
	}
	
	int lowerBound(int[] xs, int key) {
		int low = -1, high = xs.length;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (xs[mid] >= key) high = mid;
			else low = mid;
		}
		return low + 1;
	}
	
	int upperBound(int[] xs, int key) {
		return lowerBound(xs, key + 1);
	}
	
	static public class Sat2 {
		final int n;
		final boolean[] ans;
		final StronglyConnectedComponent scc;

		void clear() {
			scc.clear();
		}

		public void Implication(int a, int b) {
			scc.addEdge(a, b);
		}

		public Sat2(int n) {
			this.n = n;
			ans = new boolean[n];
			scc = new StronglyConnectedComponent(n * 2);
		}

		private int Not(int a) {
			if(a < 0 || a >= 2 * n) throw new RuntimeException();
			return a >= n ? a - n : a + n;
		}

		public void Or(int a, int b) {
			if(a < 0 || a >= 2 * n || b < 0 || b >= 2 * n) throw new RuntimeException();
			scc.addEdge(Not(a), b);
			scc.addEdge(Not(b), a);
		}

		public boolean satisfy() {
			scc.scc();
			for(int i = 0; i < n; i++) {
				// ??????????????????
				if(scc.cmp[i] == scc.cmp[i + n]) {
					return false;
				}
			}

			for(int i = 0; i < n; i++) {
				ans[i] = scc.cmp[i] > scc.cmp[i + n];
			}

			return true;
		}

		static public class StronglyConnectedComponent {
			int V;
			List<List<Integer>> G;
			List<List<Integer>> rG;
			List<Integer> vs;
			boolean[] used;
			public int[] cmp;

			void clear() {
				for (int i = 0; i < V; i++) {
					G.get(i).clear();
					rG.get(i).clear();
				}
			}

			public StronglyConnectedComponent(int n) {
				V = n;
				G = new ArrayList<List<Integer>>(n);
				rG = new ArrayList<List<Integer>>(n);
				vs = new ArrayList<Integer>();
				used = new boolean[n];
				cmp = new int[n];
				for (int i = 0; i < n; i++) {
					G.add(new ArrayList<Integer>());
					rG.add(new ArrayList<Integer>());
				}
			}

			public void addEdge(int from, int to) {
				G.get(from).add(to);
				rG.get(to).add(from);
			}

			private void dfs(int v) {
				used[v] = true;
				for (int i = 0; i < G.get(v).size(); i++)
					if (!used[G.get(v).get(i)])
						dfs(G.get(v).get(i));
				vs.add(v);
			}

			private void rdfs(int v, int k) {
				used[v] = true;
				cmp[v] = k;
				for (int i = 0; i < rG.get(v).size(); i++)
					if (!used[rG.get(v).get(i)])
						rdfs(rG.get(v).get(i), k);
			}

			public int scc() {
				for (int i = 0; i < V; i++)
					used[i] = false;
				vs.clear();
				for (int i = 0; i < V; i++)
					if (!used[i])
						dfs(i);
				for (int i = 0; i < V; i++)
					used[i] = false;
				int k = 0;
				for (int i = vs.size() - 1; i >= 0; i--)
					if (!used[vs.get(i)])
						rdfs(vs.get(i), k++);
				return k;
			}

		}
	}

	
	static public class Sat2_2 {
		final int n;
		final boolean[] ans;
		final StronglyConnectedComponent scc;

		void clear() {
			scc.clear();
		}

		public Sat2_2(int n) {
			this.n = n;
			ans = new boolean[n];
			scc = new StronglyConnectedComponent(n * 2);
		}

		private int Not(int a) {
			if(a < 0 || a >= 2 * n) throw new RuntimeException();
			return a >= n ? a - n : a + n;
		}

		public void Or(int a, int b) {
			if(a < 0 || a >= 2 * n || b < 0 || b >= 2 * n) throw new RuntimeException();
			scc.addEdge(Not(a), b);
			scc.addEdge(Not(b), a);
		}

		public boolean satisfy() {
			scc.scc();
			for(int i = 0; i < n; i++) {
				// ??????????????????
				if(scc.cmp[i] == scc.cmp[i + n]) {
					return false;
				}
			}

			for(int i = 0; i < n; i++) {
				ans[i] = scc.cmp[i] > scc.cmp[i + n];
			}

			return true;
		}

		static class SimpleAdjListGraph {
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
		}

		static public class StronglyConnectedComponent {
			int V;
			SimpleAdjListGraph G;
			SimpleAdjListGraph rG;
			int len;
			int[] vs;
			boolean[] used;
			public int[] cmp;

			void clear() {
				G.clear();
				rG.clear();
			}

			public StronglyConnectedComponent(int n) {
				V = n;
				G = new SimpleAdjListGraph(n, Math.min(10000*10000/5, n*n));
				rG = new SimpleAdjListGraph(n, Math.min(10000*10000/5, n*n));
				vs = new int[n*2];
				used = new boolean[n];
				cmp = new int[n];
			}

			public void addEdge(int from, int to) {
				G.addEdge(from, to);
				rG.addEdge(to, from);
			}

			private void dfs(int v) {
				used[v] = true;
				for (int e = G.head[v]; e != -1; e = G.next[e])
					if (!used[G.to[e]])
						dfs(G.to[e]);
				vs[len++] = v;
			}

			private void rdfs(int v, int k) {
				used[v] = true;
				cmp[v] = k;
				for (int e = rG.head[v]; e != -1; e = rG.next[e])
					if (!used[rG.to[e]])
						rdfs(rG.to[e], k);
			}

			public int scc() {
				for (int i = 0; i < V; i++)
					used[i] = false;
				len = 0;
				for (int i = 0; i < V; i++)
					if (!used[i])
						dfs(i);
				for (int i = 0; i < V; i++)
					used[i] = false;
				int k = 0;
				for (int i = len - 1; i >= 0; i--)
					if (!used[vs[i]])
						rdfs(vs[i], k++);
				return k;
			}

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