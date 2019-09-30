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
			n = io.nextInt();
			A = io.nextLong();
			B = io.nextLong();
			S = io.nextLongArray(n);
//			n = 100000;
//			A = 10000;
//			B = 1;
//			S = new long[n];
//			for (int i = 0; i < n; i++) S[i] = (random.nextLong() >>> 1) % 1000;
//			for (int i = 0; i < n; i++) S[i] = i + 1;
//			Arrays.sort(S);

			AB = new long[]{A,B};
			nxt = new int[2][n];
			for (int i = 0; i < 2; i++) {
				for (int l = n-1, r = n-1; l >= 0; l--) {
					while (r >= 0 && S[l]-S[r] < AB[i]) r--;
					nxt[i][l] = r;
				}
			}
			
//			dump(nxt);
			
			for (int i = 1; i < n; i++) {
				if (S[i]-S[i-1] < A) badA.add(i-1);
				if (S[i]-S[i-1] < B) badB.add(i-1);
			}
			
			memo = new int[n][2];
			memo2 = new long[n][2];
			for (int[] d : memo) Arrays.fill(d, -1);
			for (long[] d : memo2) Arrays.fill(d, -1L);
			
//			next(4, 1);
//			if (true) throw new RuntimeException();
			
			long ans = f(n-1, 0) + f(n-1, 1);
			io.out.println(ans % mod);
		}
	}
	int n;
	long A, B;
	long[] AB;
	long[] S;

	TreeSet<Integer> badA = new TreeSet<>();
	TreeSet<Integer> badB = new TreeSet<>();

	int[][] nxt;
	int[][] memo;
	long[][] memo2;
	int next(int i, int j) {
		/*
		if (memo[i][j] != -1) return memo[i][j];
		int[] cur = new int[2];
		cur[j] = i;
		cur[j^1] = -1;
		for (int k = i - 1; k >= 0; k--) {
			int to = 0;
			for (int l = 0; l < 2; l++) {
				if (cur[l] == -1 || S[cur[l]] - S[k] >= AB[l]) {
					to |= 1 << l;
				}
			}
			if (to == 3) return memo[i][j] = k;
			if (to == 0) return memo[i][j] = -3;
			cur[to == 1 ? 0 : 1] = k;
		}
		
		return memo[i][j] = -2;
		*/
//		next3(j == 0 ? i : -1, j == 1 ? i : -1);
		return next2(j == 0 ? i : -1, j == 1 ? i : -1);
	}
	TreeMap<Long, Integer> mp = new TreeMap<>();
	int next2(int i, int j) {
		int k = (i == -1 ? j : j == -1 ? i : Math.min(i, j)) - 1;
//		dump("next2", i, j, k);
		if (k == -1) return -2;

		if (i != -1 && S[i] - S[k] >= A) i = -1;
		if (j != -1 && S[j] - S[k] >= B) j = -1;

		if (i == -1 && j == -1) return k;
		if (i != -1 && j != -1) return -3;
		
		long key = (i+1L)<<32|(j+1);
		if (mp.containsKey(key)) return mp.get(key);
//		dump(i, j, k);
		int ans;
		if (i == -1) {
			int to = nxt[1][j];
			Integer l = badA.lower(j-1);
			if (l != null && l >= to+1) {
				return -3;
			}
//			dump(i, j, k, to);
			if (to == -1) return -2;
			ans = next2(to+1, j);
		}
		else {
			int to = nxt[0][i];
			Integer l = badB.lower(i-1);
			if (l != null && l >= to+1) {
				return -3;
			}
			if (to == -1) return -2;
			ans = next2(i, to+1);
		}
		mp.put(key, ans);
//		dump("next2", i, j, k, ans);
		return ans;
	}
	
	long f(int i, int j) {
		if (i == -1) return 1;
		if (memo2[i][j] != -1) return memo2[i][j];
		int t = next(i, j);
//		dump("f", i, j, t);
		if (t == -2) return 1;
		if (t == -3) return 0;
		long ans = f(t, 0) + f(t, 1);
		if (ans >= mod) ans -= mod;
		return memo2[i][j] = ans;
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