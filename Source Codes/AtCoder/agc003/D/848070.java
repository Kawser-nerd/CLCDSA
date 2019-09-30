import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;

import static java.util.Arrays.*;

public class Main {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	static final int[] ps = primesByEratosthenes(2500+10);
//	static final int[] ps = primesByEratosthenes(100000+100);
	
	/// MAIN CODE
	public void run() throws IOException {
//		int TEST_CASE = Integer.parseInt(new String(io.nextLine()).trim());
		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			long[] ss = io.nextLongArray(n);
//			int n = 100000;
//			long[] ss = new long[n];
//			for(int i = 0; i < n; i++) {
//				do {
//					ss[i] = random.nextLong();
//				} while(ss[i] < 0);
////				ss[i] = ss[i] % 10000000000L + 1;
//				ss[i] = ss[i] % 1000L + 1;
////				ss[i] = 9999999967L;
//			}
			TreeMap<long[], Integer> mp = new TreeMap<>((a,b)->{
				if(a.length != b.length) return a.length - b.length;
				for(int i = 0; i < a.length; i++) {
					if(a[i] != b[i]) return Long.compare(a[i], b[i]);
				}
				return 0;
			});
			for(long s : ss) {
				final long[] ps = primeFactor(s);
//				System.err.println(Arrays.toString(ps));
				mp.put(ps, mp.getOrDefault(ps, 0) + 1);
			}
			List<Entry<long[], Integer>> es = new ArrayList<>(mp.size());
			for(Entry<long[], Integer> e : mp.entrySet()) {
				es.add(e);
			}
			int ans = 0;
			for(Entry<long[], Integer> e : es) if(mp.containsKey(e.getKey())) {
				long[] e2 = e.getKey().clone();
				int val = 0;
				if(e2.length == 0) {
					val++;
				} else {
					for(int i = 0; i < e2.length; i++) {
						e2[i] += 3 - e2[i] % 100 - e2[i] % 100;
					}
					final int cnt = mp.getOrDefault(e2, 0);
					val += Math.max(cnt, e.getValue());
					mp.remove(e2);
//					System.err.println(Arrays.toString(e2));
				}
				mp.remove(e.getKey());
				ans += val;
//				System.err.println(Arrays.toString(e.getKey()) + " " + e.getValue() + " " + val);
			}
			io.out.println(ans);
		}
	}

	private static long[] primeFactor(long t) {
		int j = 0;
		long[] res = new long[30];
//		for(int i = 0; i < ps.length && (long)ps[i]*ps[i]*ps[i] <= t; i++) {
		for(int i = 0; i < ps.length && (long)ps[i]*ps[i] <= t; i++) {
			if(t % ps[i] == 0) {
				res[j++] = ps[i] * 100;
				int c = 0;
				do {
					c++;
					t /= ps[i];
				} while(t % ps[i] == 0);
				if(c % 3 == 0) j--;
				else res[j-1] += c % 3;
			}
		}
		
		if(t != 1) {
			long low = 1, high = 100001;
			while(high - low > 1) {
				long mid = (low + high) / 2;
				if(mid*mid <= t) low = mid;
				else high = mid;
			}
//			System.err.println(t - (low + 0) * (low + 0));
			if(low * low == t) res[j++] = low * 100 + 2;
			else res[j++] = t * 100 + 1;
//			res[j++] = t * 100 + 1;
		}
		
		return Arrays.copyOf(res, j);
	}

	private static int[] primesByEratosthenes(int n) {
		final boolean[] p = eratosthenes(n);
		
		int cnt = 0;
		for(int i = 2; i <= n; i++) {
			if(p[i]) {
				cnt++;
			}
		}
		
		int[] res = new int[cnt];
		for(int i = 2, j = 0; i <= n; i++) {
			if(p[i]) {
				res[j++] = i;
			}
		}
		
		return res;
	}

	private static boolean[] eratosthenes(int n) {
		final boolean[] p = new boolean[n + 1];
		Arrays.fill(p, true);
		p[0] = p[1] = false;
		for(int i = 2; i*i <= n; i++) {
			if(p[i]) {
				for(int j = i*i; j <= n; j += i) {
					p[j] = false;
				}
			}
		}
		return p;
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