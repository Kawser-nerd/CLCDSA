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
			int a = io.nextInt() - 1;
			int b = io.nextInt() - 1;
			x = new int[n];
			y = new int[n];
			TreeSet<Integer> sx = new TreeSet<>();
			TreeSet<Integer> sy = new TreeSet<>();
			for (int i = 0; i < n; i++) {
				x[i] = io.nextInt();
				y[i] = io.nextInt();
				
				// 45
				int yy = x[i];
				int xx = y[i];
				x[i] = xx - yy;
				y[i] = xx + yy;

				sx.add(x[i]);
				sy.add(y[i]);
			}
			
			for (int xx : sx) {
				xy.put(xx, new TreeMap<Integer, Integer>());
				xys.put(xx, new ArrayList<Integer>());
			}
			
			for (int yy : sy) {
				yx.put(yy, new TreeMap<Integer, Integer>());
				yxs.put(yy, new ArrayList<Integer>());
			}
			
			for (int i = 0; i < n; i++) {
				xy.get(x[i]).put(y[i], i);
				yx.get(y[i]).put(x[i], i);
				xys.get(x[i]).add(y[i]);
				yxs.get(y[i]).add(x[i]);
			}

			for (List<Integer> l : xys.values()) Collections.sort(l);
			for (List<Integer> l : yxs.values()) Collections.sort(l);
			
			// max(|dx|, |dy|)
			d = Math.max(Math.abs(x[a]-x[b]), Math.abs(y[a]-y[b]));
			io.out.println(dfs(a) / 2);
		}
	}

	int d;
	int[] x, y;
	TreeSet<Integer> vis = new TreeSet<>();
	TreeMap<Integer, TreeMap<Integer, Integer>> xy = new TreeMap<>();
	TreeMap<Integer, TreeMap<Integer, Integer>> yx = new TreeMap<>();
	TreeMap<Integer, List<Integer>> xys = new TreeMap<>();
	TreeMap<Integer, List<Integer>> yxs = new TreeMap<>();
	
	long dfs(int p) {
		if (!vis.add(p)) return 0;
		
		long ans = 0;

		{
			for (int s = -1; s <= 1; s += 2) {
				TreeMap<Integer, Integer> t = xy.get(x[p]+s*d);
				if (t == null) continue;
				
				List<Integer> li = xys.get(x[p]+s*d);
				int l = Collections.binarySearch(li, y[p]-d);
				int r = Collections.binarySearch(li, y[p]+d+1);
				if (l < 0) l = -l - 1;
				if (r < 0) r = -r - 1;
//				dump(x[p], y[p], d, li.get(l), li.get(r-1));
				ans += r - l;
				
				for (int cur = y[p]-d; cur <= y[p]+d; cur++) {
					Entry<Integer, Integer> e = t.ceilingEntry(cur);
					if (e == null || e.getKey() > y[p]+d) break;
					t.remove(e.getKey());
					cur = e.getKey();
//					dump(p, idx);
					ans += dfs(e.getValue());
				}
			}
			for (int s = -1; s <= 1; s += 2) {
				TreeMap<Integer, Integer> t = yx.get(y[p]+s*d);
				if (t == null) continue;
				
				List<Integer> li = yxs.get(y[p]+s*d);
				int l = Collections.binarySearch(li, x[p]-d+1);
				int r = Collections.binarySearch(li, x[p]+d);
				if (l < 0) l = -l - 1;
				if (r < 0) r = -r - 1;
				ans += r - l;
				
				for (int cur = x[p]-d; cur <= x[p]+d; cur++) {
					Entry<Integer, Integer> e = t.ceilingEntry(cur);
					if (e == null || e.getKey() > x[p]+d) break;
					t.remove(e.getKey());
					cur = e.getKey();
//					dump(p, idx);
					ans += dfs(e.getValue());
				}
			}
		}
		
//		for (int j = 0; j < 1; j++) {
//			final int pq = p;
//			
//			for (int cur = x[pq]-d-1; cur <= x[pq]+d-1; ) {
//				Entry<Integer, TreeMap<Integer, Integer>> e = xy.higherEntry(cur);
//				if (e == null || e.getKey() > x[pq]+d) break;
//				cur = e.getKey();
//				
//				{
//					TreeMap<Integer, Integer> s = e.getValue();
//					Integer idx = s.get(y[pq]-d);
//					if (idx != null) {
////						dump(p, idx);
//						add(pq, idx);
//						ans += 1 + dfs(idx);
//					}
//				}
//				
//				{
//					TreeMap<Integer, Integer> s = e.getValue();
//					Integer idx = s.get(y[pq]+d);
//					if (idx != null) {
////						dump(p, idx);
//						add(pq, idx);
//						ans += 1 + dfs(idx);
//					}
//				}
//			}
//			
//			for (int cur = y[pq]-d-1; cur <= y[pq]+d-1; ) {
//				Entry<Integer, TreeMap<Integer, Integer>> e = yx.higherEntry(cur);
//				if (e == null || e.getKey() > y[pq]+d) break;
//				cur = e.getKey();
//				
//				{
//					TreeMap<Integer, Integer> s = e.getValue();
//					Integer idx = s.get(x[pq]-d);
//					if (idx != null) {
////						dump(p, idx);
//						add(pq, idx);
//						ans += 1 + dfs(idx);
//					}
//				}
//				
//				{
//					TreeMap<Integer, Integer> s = e.getValue();
//					Integer idx = s.get(x[pq]+d);
//					if (idx != null) {
////						dump(p, idx);
//						add(pq, idx);
//						ans += 1 + dfs(idx);
//					}
//				}
//			}
//		}
		
		return ans;
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