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
			int m = io.nextInt();
			int[] a = io.nextIntArray(n);
			
			for (int i = 0; i < n; i++) a[i]--;
			SegArithmeticProgression seg = new SegArithmeticProgression(m, 1);

			long ans = 0;
			for (int i = 1; i < n; i++) {
				if (a[i-1] <= a[i]) {
					ans += a[i] - a[i-1];
					seg.addSeries(a[i-1]+2, a[i]+1, 1);
				} else {
					ans += m + a[i] - a[i-1];
					seg.addSeries(a[i-1]+2, m, 1);
					seg.addSeries(0, a[i]+1, m-1-a[i-1]);
				}
			}
			
			long max = 0;
			for (int i = 0; i < m; i++) {
				max = Math.max(max, seg.get(i, i+1));
			}
			io.out.println(ans - max);
		}
	}
	
	static class SegArithmeticProgression {
		final int n;
		final int d;
		final long[] seg;
		final long[] add1;
		final long[] add2;
		
		public SegArithmeticProgression(final int n, final int d) {
			this.d = d;
			this.n = Integer.highestOneBit(n) << 1;
			seg = new long[this.n << 1];
			add1 = new long[this.n << 1];
			add2 = new long[this.n << 1];
		}
		
		void propagate(int curL, int curR, int k) {
			if(add1[k] != 0) {
				final int curM = (curL + curR) / 2;
				addSeries(curL, curR, 2 * k + 1, add1[k], curL, curM);
				addSeries(curL, curR, 2 * k + 2, add1[k], curM, curR);
				add(curL, curR, 2 * k + 2, add1[k] * (curM - curL), curM, curR);
				add1[k] = 0;
			}
			if(add2[k] != 0) {
				final int curM = (curL + curR) / 2;
				add(curL, curR, 2 * k + 1, add2[k], curL, curM);
				add(curL, curR, 2 * k + 2, add2[k], curM, curR);
				add2[k] = 0;
			}
		}

		long get(int l, int r) { return get(l, r, 0, 0, n); }
		long get(int l, int r, int k, int curL, int curR) {
			if(curR <= l || curL >= r) return 0;
			if(l <= curL && curR <= r) { return seg[k]; }
			propagate(curL, curR, k);
			final int curM = (curL + curR) / 2;
			long ans = 0;
			ans += get(l, r, 2 * k + 1, curL, curM);
			ans += get(l, r, 2 * k + 2, curM, curR);
			return ans;
		}

		// ???????
		void addSeries(int l, int r, long v) {
			addSeries(l + 1, r, 0, d, 0, n);
			add(l, r, v);
		}
		void addSeries(int l, int r, int k, long v, int curL, int curR) {
			if(curR <= l || curL >= r) return;
			if(l <= curL && curR <= r) {
				final int m = curR - curL;
				add1[k] += v;
				seg[k] += v * m * (m + 1) / 2;
				return;
			}
			final int curM = (curL + curR) / 2;
			propagate(curL, curR, k);
			addSeries(l, r, 2 * k + 1, v, curL, curM);
			addSeries(l, r, 2 * k + 2, v, curM, curR);
			add(l, r, 2 * k + 2, v * Math.max(0, curM - Math.max(curL, l)), curM, curR);
			seg[k] = seg[2*k+1] + seg[2*k+2];
		}

		// ?????????
		void add(int l, int r, long v) { add(l, r, 0, v, 0, n); }
		void add(int l, int r, int k, long v, int curL, int curR) {
			if(curR <= l || curL >= r || v == 0) return;
			if(l <= curL && curR <= r) {
				final int m = curR - curL;
				add2[k] += v;
				seg[k] += v * m;
				return;
			}
			final int curM = (curL + curR) / 2;
			propagate(curL, curR, k);
			add(l, r, 2 * k + 1, v, curL, curM);
			add(l, r, 2 * k + 2, v, curM, curR);
			seg[k] = seg[2*k+1] + seg[2*k+2];
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