import java.io.*;
import java.util.*;

/**
 * 
 * @author kuppu Centroid decomposition
 */
public class Main{
	static int mod = 1_000_000_007;
	static long fact[] = new long[5003];;
	static long dp[][] = new long[2][10000];
	static LinkedList<Integer> g[] = new LinkedList[5003];
	static long c[][] = new long[5003][5003];
	static int centroid = 0;
	static int sz[] = new int[5003];
	static int a[] = new int[5003];
	static int m;

	static void dfs(int v, int par) {
		sz[v] = 1;
		for (int u : g[v]) {
			if (u == par)
				continue;
			dfs(u, v);
			sz[v] += sz[u];
		}
	}

	static long add(long x, long y) {
		x += y;
		if (x >= mod)
			return x - mod;
		return x;
	}

	static long sub(long x, long y) {
		x -= y;
		if (x < 0)
			return x + mod;
		return x;
	}

	static long mul(long x, long y) {
		x *= y;
		return x % mod;
	}

	public static void Solve(int n) {
		dp[0][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int x = 0; x <= n; x++)
				dp[1][x] = 0;
			for (int x = 0; x <= n; x++) {
				if (dp[0][x] == 0) continue;
				for (int y = 0; y <= a[i]; y++)
					dp[1][x + y] = add(dp[1][x + y], mul(mul(dp[0][x], fact[y]), mul(c[a[i]][y], c[a[i]][y])));
			}
			for (int x = 0; x <= n; x++)
				dp[0][x] = dp[1][x];
		}
		long ans = 0;
		for (int x = 0; x <= n; x++) {
			long val = mul(dp[0][x], fact[n - x]);
			if ((x & 1)!=0)
				ans = sub(ans, val);
			else
				ans = add(ans, val);
		}
		System.out.println(ans);

	}

	public static void main(String args[]) throws Exception {

		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		fact[0] = 1;
		for (int i = 1; i <= 5000; i++) {
			fact[i] = mul(fact[i - 1], i);
		}
		c[0][0] = 1;
		for (int i = 0; i < 5000; i++)
			c[i][0] = c[i][i] = 1;
		for (int i = 1; i < 5003; i++) {
			for (int j = 1; j < i; j++) {
				c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
			}
		}
		for (int i = 0; i < 5001; i++) {
			g[i] = new LinkedList<>();
		}
		int n = sc.nextInt();
		for (int i = 1; i < n; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);

		}
		dfs(0, -1);
		int v = 0;
		while (true) {
			int w = -1;
			for (int u : g[v]) {
				if (sz[v] < sz[u]) {
					continue;
				}
				if (2 * sz[u] >= n) {
					w = u;
				}
			}
			if (w == -1)
				break;
			v = w;
		}
		dfs(v, -1);
		for (int u : g[v]) {
			a[m] = sz[u];
			if (n == 2 * a[m]) {
				System.out.println(mul(fact[a[m]], fact[a[m]]));
				return;
			}
			m++;
		}
		
		Solve(n);
		out.close();

	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.