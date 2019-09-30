import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;
import java.io.*;

public class Main {
	
	final long MOD = 1000000007;

	void solve() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] F = sc.nextIntArray(N);
		long[] dp = new long[N+1];
		dp[0] = 1;
		int mark[] = new int[M+1];
		int tail = 0;
		long acc = 0;
		for (int i = 0; i < N; i++) {
			acc += dp[i];
			acc %= MOD;
			++mark[F[i]];
			while (mark[F[i]] >= 2) {
				mark[F[tail]]--;
				acc -= dp[tail];
				acc = (acc + MOD) % MOD;
				tail++;
			}
			dp[i+1] = acc;
		}
		long ans = dp[N];
		out.println(ans);
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