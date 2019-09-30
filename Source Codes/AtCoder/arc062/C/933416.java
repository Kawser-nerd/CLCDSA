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
		long[][] comb = new long[401][401];
		long[] fact = new long[401];
		fact[0] = 1;
		for(int i = 0; i < comb.length; i++) {
			if(i > 0) fact[i] = fact[i-1] * i;
			comb[i][0] = comb[i][i] = 1;
			for(int j = 1; j < i; j++) {
				comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			}
		}
		
//		dump(comb[400][6]);
		
//		int TEST_CASE = Integer.parseInt(new String(io.nextLine()).trim());
		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			int[][] C = io.nextIntArray2D(n, 4);
			long ans = 0;
			
//			int[] p1 = new int[]{0, 1, 2, 3,};
			int[] p2 = new int[]{1, 0, 3, 2,};
			
			RollingHashMod[] rh = new RollingHashMod[n];
			for(int i = 0; i < n; i++) rh[i] = new RollingHashMod(C[i]);
			
			final TreeMap<Long, Integer> mp = new TreeMap<>();

//			dump(3, rh[3].str, rh[3].minRotateIndex());
//			if(true) throw new RuntimeException();
			
			for(int i = 0; i < n; i++) {
				long h = rh[i].minRotateHash();
				mp.put(h, mp.getOrDefault(h, 0) + 1);
//				dump(i, rh[i].str, rh[i].minRotateIndex(), h);
			}
//			if(true) throw new RuntimeException();
			
			int[] dup = new int[4];
			
			/*
			 * 1 2
			 * 3 4
			 * 
			 * 1 2
			 * 3 4
			 */
			for(int i = 0; i < n; i++) {
				mp.put(rh[i].minRotateHash(), mp.get(rh[i].minRotateHash()) - 1);
				for(int j = i + 1; j < n; j++) for(int d = 0; d < 4; d++) {
					Arrays.fill(dup, 1);
					RollingHashMod[] hs = new RollingHashMod[4];
					for(int s = 0; s < 4; s++) {
						hs[s] = new RollingHashMod(C[i][(s+1)&3], C[i][(s+0)&3], C[j][p2[(s+d+0)&3]], C[j][p2[(s+d+1)&3]]);
					}
					long val = 1;
					for(int s = 0; s < 4; s++) if(dup[s] == 1) {
						for(int k = s + 1; k < 4; k++) {
							if(hs[s].minRotateHash() == hs[k].minRotateHash()) {
								dup[k] = -1;
								dup[s]++;
							}
						}
						// 
						int cnt = mp.getOrDefault(hs[s].minRotateHash(), 0);
						if(rh[j].minRotateHash() == hs[s].minRotateHash()) {
							cnt--;
						}
						
						int hi = hs[s].minRotateIndex();
						int sym = 1;
						if(hs[s].minRotateHash() == hs[s].hash((hi + 1) % 4, (hi + 1) % 4)) {
							sym = 4;
						} else if(hs[s].minRotateHash() == hs[s].hash((hi + 2) % 4, (hi + 2) % 4)) {
							sym = 2;
						}
						
						long pow = 1;
						long comb_fact = 1;
						for(int k = 0; k < dup[s]; k++) {
							pow *= sym;
							comb_fact *= cnt - k;
						}
						val *= pow * comb_fact;
//						if(i == 1 && j == 3 && d == 3) {
//							dump(i, j, s, dup[s], sym, cnt, hs[s].str, hs[s].minRotateHash(), hs[s].minRotateIndex(), val);
//						}
					}
//					dump(i, j, d, dup, val);
					ans += val;
				}
			}
			io.out.println(ans);
		}
	}
	
	static
	class RollingHashMod {
		private static final int[] LARGE_PRIMES = new int[]{
			1000000007, 1000000009, 1000000021, 1000000033,
			1000000087, 1000000093, 1000000097, 1000000103,
			1000000123, 1000000181, 1000000207, 1000000223,
			1000000241, 1000000271, 1000000289, 1000000297,
			1000000321, 1000000349, 1000000363, 1000000403,
		};

		private static final Random random = new Random(0);
		private static final int HASH_NUM = 2;
//		private static final long RADIX = 1000000409;
		private static final long RADIX = 1000000003;
		private static final long XOR = random.nextLong();
		
		private int n;
		private static int[] primes;
		private int[] str;
		private int[][] pow;
		private int[][] table;
		
		public RollingHashMod(int... str) {
			if(primes == null) {
//				final Random random = new Random(System.currentTimeMillis());
				primes = new int[HASH_NUM];
				for(int i = 0; i < HASH_NUM; i++) {
					final int idx = random.nextInt(LARGE_PRIMES.length - i);
					primes[i] = LARGE_PRIMES[idx];
					LARGE_PRIMES[idx] = LARGE_PRIMES[LARGE_PRIMES.length - i - 1];
					LARGE_PRIMES[LARGE_PRIMES.length - i - 1] = primes[i];
				}
			}
			
			n = str.length;

			this.str = str.clone();
			table = new int[HASH_NUM][n + 1];
			pow = new int[HASH_NUM][n + 1];
			
			for(int j = 0; j < HASH_NUM; j++) {
				final int p = primes[j];
				pow[j][0] = 1;
				for (int i = 0; i < n; i++) {
					table[j][i + 1] = (int)(((long)table[j][i] * RADIX + (this.str[i]^XOR)%p + p) % p);
					pow[j][i + 1] = (int)((long)pow[j][i] * RADIX % p);
				}
			}
		}
		
		public long hash(int i, int j) {
			if(j >= n) {
				j -= n;
			}
			if(i >= j) {
				return hashRotate(i, j);
			} else {
				return hash(0, i, j) << 32 | hash(1, i, j);
			}
		}
		
		public long hashRotate(int i, int j) {
			assert(i >= j);
			long h0 = hash(0, i, n) * pow[0][j] % primes[0] + table[0][j];
			long h1 = hash(1, i, n) * pow[1][j] % primes[1] + table[1][j];
			if(h0 >= primes[0]) h0 -= primes[0];
			if(h1 >= primes[1]) h1 -= primes[1];
//			dump(str, i, j, h0, h1, hash(0, i, n), table[0]);
			return h0 << 32 | h1;
		}
		
		private long hash(int idx, int i, int j) {
			assert(i <= j);
			long h0 = table[idx][j] - (long)table[idx][i] * pow[idx][j - i] % primes[idx];
			if(h0 < 0) h0 += primes[idx];
			return h0;
		}
		
		public long minRotateHash() {
			int s = minRotateIndex();
			return hash(s, s);
		}
		
		private int minRotateCache = -1;
		public int minRotateIndex() {
			if(minRotateCache != -1) return minRotateCache;
			
			int s = n - 1;
			for(int i = n - 2; i >= 0; i--) {
				int low = 0, high = n;
				while(high - low > 1) {
					int mid = (low + high) / 2;
					if(hash(i, i + mid) == hash(s, s + mid)) {
						low = mid;
					} else {
						high = mid;
					}
				}
//				dump(i, s, str, low, high);
				if(str[(i + high - 1) % n] <= str[(s + high - 1) % n]) {
					s = i;
				}
			}
			return minRotateCache = s;
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