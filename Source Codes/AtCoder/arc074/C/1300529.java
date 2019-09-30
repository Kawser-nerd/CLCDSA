import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {
	
	final long MOD = (long)1e9+7;

	int[][][] dp = new int[301][301][301];
	boolean[][][] invalid = new boolean[301][301][301];

	void solve() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] L = new int[M];
		int[] R = new int[M];
		int[] X = new int[M];
		for (int i = 0; i < M; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			X[i] = sc.nextInt();
		}

		for (int m = 0; m < M; m++) {
			if (X[m] == 1) {
				for (int i = 0; i < R[m]; i++)
					for (int j = 0; j < R[m]; j++) {
						if (i >= L[m] || j >= L[m]) {
							invalid[R[m]][i][j] = true;
							invalid[i][R[m]][j] = true;
							invalid[i][j][R[m]] = true;
						}
					}
			}
			if (X[m] == 2) {
				for (int i = 0; i < L[m]; i++) {
					for (int j = 0; j < L[m]; j++) {
						invalid[R[m]][i][j] = true;
						invalid[i][R[m]][j] = true;
						invalid[i][j][R[m]] = true;
					}
				}
				for (int i = L[m]; i < R[m]; i++) {
					for (int j = L[m]; j < R[m]; j++) {
						invalid[R[m]][i][j] = true;
						invalid[i][R[m]][j] = true;
						invalid[i][j][R[m]] = true;
					}
				}
			}
			if (X[m] == 3) {
				for (int i = 0; i < R[m]; i++)
					for (int j = 0; j < R[m]; j++) {
						if (i < L[m] || j < L[m]) {
							invalid[R[m]][i][j] = true;
							invalid[i][R[m]][j] = true;
							invalid[i][j][R[m]] = true;
						}
					}
			}
		}
		
		dp[0][0][0] = 1;
		
		for (int r = 0; r <= N; r++) {
			for (int g = 0; g <= N; g++) {
				for (int b = 0; b <= N; b++) {
					if (invalid[r][g][b]) dp[r][g][b] = 0;
					dp[r][g][b] %= MOD;
					int n = max(max(r, g), b) + 1;
					if (n > N) continue;
					dp[n][g][b] += dp[r][g][b];
					dp[r][n][b] += dp[r][g][b];
					dp[r][g][n] += dp[r][g][b];
					if (dp[n][g][b] >= MOD) dp[n][g][b] -= MOD;
					if (dp[r][n][b] >= MOD) dp[r][n][b] -= MOD;
					if (dp[r][g][n] >= MOD) dp[r][g][n] -= MOD;
				}
			}
		}
		
		
		long ans = 0;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) {
				ans += dp[N][i][j];
				ans += dp[i][N][j];
				ans += dp[i][j][N];
				ans %= MOD;
			}
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