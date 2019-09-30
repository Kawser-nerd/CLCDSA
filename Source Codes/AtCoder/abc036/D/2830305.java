import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static long mod = 1000*1000*1000 + 7;
	static ArrayList<Integer> tree[];
	static Integer dp[][];
	public static int solve(int u,int col,int p) {
		if (dp[col][u] != null) {
			return dp[col][u];
		}
		long ret = 1;
		if (col == 0) {
			long w1 = 1;
			long w2 = 1;
			for (Integer v : tree[u]) {
				if (p == v) {
					continue;
				}
				w1 *= 1L*(solve(v,1,u))%mod;
				w1 %= mod;
				w2 *= solve(v,0,u)%mod;
				w2 %= mod;
			}
			ret = w1 + w2;
		} else {
			for (Integer v : tree[u]) {
				if (p == v) {
					continue;
				}
				ret *= 1L*(solve(v,0,u))%mod;
				ret %= mod;
			}
		}
		return dp[col][u] = (int)(ret%mod);
	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		tree = new ArrayList[n];
		dp = new Integer[2][n];
		for (int i = 0 ; i < n ; ++i) {
			tree[i] = new ArrayList();
		}
		for (int i = 0 ; i < n - 1 ; ++i) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			tree[u].add(v);
			tree[v].add(u);
		}
		System.out.println(solve(0,0,-1));
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.