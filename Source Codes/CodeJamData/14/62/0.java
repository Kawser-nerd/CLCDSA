import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Key {
		final int a[];
		final int haveCnt;
		public Key(int[] a, int haveCnt) {
			super();
			this.a = a;
			this.haveCnt = haveCnt;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(a);
			result = prime * result + haveCnt;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Key other = (Key) obj;
			if (!Arrays.equals(a, other.a))
				return false;
			if (haveCnt != other.haveCnt)
				return false;
			return true;
		}
	}
	
	static long fact[] = new long[100];
	static {
		fact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = fact[i - 1] * i;
		}
	}
	
	static Map<Key, Long> cache = new HashMap<>();
	
	static long getAns(Key key) {
		Long res = cache.get(key);
		if (res == null) {
			int a[] = key.a;
			if (a.length == 1) {
				res = fact[key.haveCnt];
			} else {
				fix: {
					int badPos[] = new int[2];
					int badCnt = 0;
					for (int i = 0; i < a.length; i += 2) {
						if ((a[i] & 1) != 0 || a[i + 1] != a[i] + 1) {
							if (badCnt == 2) {
								res = 0L;
								break fix;
							}
							badPos[badCnt++] = i;
						}
					}
					int na[] = new int[a.length >> 1];
					for (int i = 0; i < na.length; i++) {
						na[i] = a[i << 1] >> 1;
					}
					if (badCnt == 0) {
						res = getAns(new Key(na, key.haveCnt));
					} else if (badCnt == 1) {
						int bp0 = badPos[0];
						na[bp0 >> 1] = a[bp0 + 1] >> 1;
						res = getAns(new Key(na, key.haveCnt + 1));
					} else {
						int bp0 = badPos[0];
						int bp1 = badPos[1];
						if ((a[bp0] & 1) == 0) {
							if ((a[bp1] & 1) == 0) {
								int nna[] = na.clone();
								nna[bp0 >> 1] = a[bp1] >> 1;
								nna[bp1 >> 1] = a[bp0] >> 1;
								res = getAns(new Key(na, key.haveCnt + 1)) + getAns(new Key(nna, key.haveCnt + 1));
							} else {
								if (a[bp1] == a[bp0] + 1 && a[bp0 + 1] + 1 == a[bp1 + 1]) {
									na[bp1 >> 1] = a[bp0 + 1] >> 1;
									res = getAns(new Key(na, key.haveCnt + 1));
								} else {
									res = 0L;
								}
							}
						} else {
							if ((a[bp1] & 1) == 0) {
								if (a[bp0] == a[bp1] + 1 && a[bp1 + 1] + 1 == a[bp0 + 1]) {
									na[bp0 >> 1] = a[bp1 + 1] >> 1;
									res = getAns(new Key(na, key.haveCnt + 1));
								} else {
									res = 0L;
								}
							} else {
								res = 0L;
							}
						}
					}
				}
			}
//			System.err.println(Arrays.toString(key.a) + " " + key.haveCnt + " " + res);
			cache.put(key, res);
		}
		return res;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int a[] = new int[1 << n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt() - 1;
		}
		long ans = getAns(new Key(a, 0));
		printCase();
		out.println(ans);
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}