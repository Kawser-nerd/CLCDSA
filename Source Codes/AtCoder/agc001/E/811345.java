import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	static final long MOD = (long)(1e9 + 7);
	int[][] cnt = new int[2001][2001];
	long[][] dp = new long[4010][4010];
	static final int O = 2005;
	
	void solve() {
		int N = sc.nextInt();
		long ans = 0;
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			cnt[a][b]++;
			dp[-a + O][-b + O]++;
			ans = (ans + MOD - f(a + a, b + b)) % MOD;
		}
		
		for (int a = -2000; a <= 2000; a++) {
			for (int b = -2000; b <= 2000; b++) {
				long x = dp[a+O][b+O] + dp[a-1+O][b+O] + dp[a+O][b-1+O];
				if (x >= MOD) x %= MOD;
				dp[a+O][b+O] = x;
				if (a >= 0 && b >= 0 && cnt[a][b] > 0) {
					ans += cnt[a][b] * x % MOD;
					if (ans >= MOD) ans %= MOD;
				}
			}
		}
		ans = (ans * fact_inv[2]) % MOD;
		
		out.println(ans);
	}
	
	static long f(int A, int B) {
		long res = fact[A+B];
		res = (res * fact_inv[A]) % MOD;
		res = (res * fact_inv[B]) % MOD;
		return res;
	}
	
	static final long[] fact = new long[8000 + 10];
	static final long[] fact_inv = new long[8000 + 10];
	static {
	    long[] inv = new long[8000 + 10];
	    inv[1] = fact[0] = fact_inv[0] = 1;
	    for (int i = 2; i < inv.length; i++) inv[i] = inv[(int)(MOD % i)] * (MOD - MOD / i) % MOD;
	    for (int i = 1; i < fact.length; i++) fact[i] = (fact[i-1] * i) % MOD;
	    for (int i = 1; i < fact_inv.length; i++) fact_inv[i] = (fact_inv[i-1] * inv[i]) % MOD;
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