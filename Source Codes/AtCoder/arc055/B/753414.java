import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		N = sc.nextInt();
		K = sc.nextInt();
		dp = new double[N+1][K+1][2];
		vis = new boolean[N+1][K+1][2];
		out.printf("%.8f%n", dp(0,0,0));
	}
	
	int N, K;
	double[][][] dp;
	boolean[][][] vis;
	
	double dp(int n, int k, int f) {
		if (k > K) return 0.0;
		if (n == N) {
			return f == 1 ? 1.0 : 0.0;
		}
		if (vis[n][k][f]) return dp[n][k][f];
		vis[n][k][f] = true;
		double res = 0;
		double p = 1.0 / (n + 1);
		if (f == 0) {
			res += (1-p) * dp(n+1, k, 0);
			res += p * max(dp(n+1,k,0), dp(n+1,k+1,1));
		} else {
			res += (1-p) * dp(n+1, k, 1);
			res += p * max(dp(n+1,k,0), dp(n+1,k+1,1));
		}
		return dp[n][k][f] = res;
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