import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

	void solve() {
		char[] s = sc.next().toCharArray();
		
		long ans = 0;
		int n = s.length;
		
		RollingHash h1 = new RollingHash(s);
		RollingHash h2 = new RollingHash(s);
		
		for (int i = (n+2)/2; i < n; i++) {
			int lenA = 0;
			{
				int lo = 0;
				int hi = n - i + 1;
				while (hi - lo > 1) {
					int mid = (lo + hi) / 2;
					if (h1.get(0, mid) == h1.get(i, i + mid) 
					&& h2.get(0, mid) == h2.get(i, i + mid)
						) {
						lo = mid;
					} else {
						hi = mid;
					}
				}
				lenA = lo;
			}
			int lenC = 0;
			{
				int lo = 0;
				int hi = n - i + 1;
				while (hi - lo > 1) {
					int mid = (lo + hi) / 2;
					if (h1.get(i-mid, i) == h1.get(n-mid, n) 
					&& h2.get(i-mid, i) == h2.get(n-mid, n)
						) {
						lo = mid;
					} else {
						hi = mid;
					}
				}
				lenC = lo;
			}
			if (lenA == n - i) lenA--;
			if (lenC == n - i) lenC--;
			ans += max(0, (lenA + lenC + 1) - (n - i));
		}
		out.println(ans);
	}
	
	static class RollingHash {
		private int MOD;
		private int P;
		
		int[] pw;
		int[] hash;
		
		public RollingHash(char[] s) {
			Random rnd = new Random(System.nanoTime());
			MOD = BigInteger.probablePrime(29, rnd).intValue();
			P = BigInteger.probablePrime(19, rnd).intValue();
			
			pw = new int[s.length + 1];
			hash = new int[s.length + 1];
			pw[0] = 1;
			for (int i = 1; i < pw.length; i++)
				pw[i] = (int)((pw[i-1] * (long)P) % MOD);
			hash[0] = 0;
			for (int i = 0; i < s.length; i++)
				hash[i+1] = (int)((hash[i] * (long)P + s[i]) % MOD);
		}
		public int get(int a, int b) {
			long res = hash[b] - (long)hash[a] * (pw[b-a]);
			res %= MOD;
			if (res < 0) res += MOD;
			return (int)res;
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