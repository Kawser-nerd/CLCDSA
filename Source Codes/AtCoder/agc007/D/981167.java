import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class Main {
	private static final int mod = (int)924844033;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	/// MAIN CODE
	public void run() throws IOException {
//		int TEST_CASE = Integer.parseInt(new String(io.nextLine()).trim());
		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			long e = io.nextInt();
			long T = io.nextInt();
			long[] x = io.nextLongArray(n);
			long[] d = new long[n];
			for (int i = 0; i < n; i++) {
				d[i] = x[i] - (i > 0 ? x[i-1] : 0);
			}
			
			SegRMQLong seg = new SegRMQLong(n+1);
			long[] ans = new long[n+1];
			for (int i = 0, l = 0; i < n; i++) {
				seg.add(0, l, 3 * d[i]);
				seg.add(l, i, d[i]);
				for (; (x[i] - x[l]) * 2 > T; l++) {
					seg.set(l, ans[l] + d[l] + (x[i] - x[l]) * 3);
				}
				// T - 2*d(j)
				ans[i+1] = ans[i] + d[i] + T;
				ans[i+1] = Math.min(ans[i+1], seg.get(0, i));
//				dump(i, ans[i] + d[i] + T, seg.get(0, 1), seg.get(1, 2));
				seg.set(i, ans[i] + T + d[i]);
			}
//			dump(ans);
			io.out.println(ans[n] + e - x[n-1]);
		}
	}
	
	static
	class SegRMQLong {
		final long INF = 1L<<60;
		
		final int n;
		final long[] seg;
		final long[] add;
		
		public SegRMQLong(final int n) {
			this.n = Integer.highestOneBit(n) << 1;
			seg = new long[this.n << 1];
			add = new long[this.n << 1];
			Arrays.fill(seg, INF);
		}
		
		void propagate(int curL, int curR, int k) {
			if(add[k] != 0) {
				final int curM = (curL + curR) / 2;
				add(curL, curR, 2 * k + 1, add[k], curL, curM);
				add(curL, curR, 2 * k + 2, add[k], curM, curR);
				add[k] = 0;
			}
		}

		long get(int l, int r) { return get(l, r, 0, 0, n); }
		long get(int l, int r, int k, int curL, int curR) {
			if(curR <= l || curL >= r) return INF;
			if(l <= curL && curR <= r) { return seg[k]; }
			propagate(curL, curR, k);
			final int curM = (curL + curR) / 2;
			return Math.min(
					get(l, r, 2 * k + 1, curL, curM),
					get(l, r, 2 * k + 2, curM, curR));
		}

		void add(int l, int r, long v) { add(l, r, 0, v, 0, n); }
		void add(int l, int r, int k, long v, int curL, int curR) {
			if(curR <= l || curL >= r) return;
			if(l <= curL && curR <= r) { seg[k] += v; add[k] += v; return; }
			final int curM = (curL + curR) / 2;
			propagate(curL, curR, k);
			add(l, r, 2 * k + 1, v, curL, curM);
			add(l, r, 2 * k + 2, v, curM, curR);
			seg[k] = Math.min(seg[2*k+1], seg[2*k+2]);
		}
		
		void set(int i, long v) {
			add(i, i + 1, 0);
			
			i += n - 1;
			seg[i] = v;
			add[i] = 0;
			while(i != 0) {
				i = (i - 1) / 2;
				seg[i] = Math.min(seg[2*i+1], seg[2*i+2]) + add[i];
			}
		}
	}
	
	void shuffle(int[] p) {
		for (int i = 1; i < p.length; i++) {
			int idx = random.nextInt(i + 1);
			swap(p, i, idx);
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