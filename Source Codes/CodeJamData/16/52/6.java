import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;

	int n;
	ArrayList<Integer>[] g;
	char[] let;
	Random rng = new Random(19);
	double[] dp;
	double[][] c;
	int[] size;

	String genRandom() {
		int[] q = new int[n];
		double[] prob = new double[n];
		int st = 0, en = 0;
		q[en++] = 0;
		StringBuffer sb = new StringBuffer();
		while (st != en) {
			double sum = 0;
			double allProb = 1;
			int allSize = 0;
			for (int j = st; j < en; j++) {
				int v = q[j];
				allProb = c[allSize + size[v]][allSize] * allProb * dp[v];
				allSize += size[v];
			}
			for (int i = st; i < en; i++) {
				prob[i] = allProb / (c[allSize][size[q[i]]] * dp[q[i]]);
				int sz = allSize - size[q[i]];

				for (int v : g[q[i]]) {
					prob[i] = c[sz + size[v]][sz] * prob[i] * dp[v];
					sz += size[v];
				}

				sum += prob[i];
			}
			double dice = rng.nextDouble();
			double curProb = 0;
			for (int i = st; i < en; i++) {
				prob[i] /= sum;
				curProb += prob[i];
				if (curProb >= dice || i + 1 == en) {
					int tmp = q[i];
					q[i] = q[st];
					q[st] = tmp;
					break;
				}
			}
			int x = q[st++];
			sb.append(let[x]);
			for (int v : g[x]) {
				q[en++] = v;
			}
		}
		return sb.toString();

	}

	void dfs(int v) {
		dp[v] = 1;
		for (int u : g[v]) {
			dfs(u);
			dp[v] = c[size[v] + size[u]][size[u]] * dp[v] * dp[u];
			size[v] += size[u];
		}
		size[v]++;
	}

	public void solve() throws IOException {
		n = in.nextInt() + 1;
		c = new double[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			c[i][0] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
		let = new char[n];
		let[0] = '!';
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			int par = in.nextInt();
			g[par].add(i);
		}
		dp = new double[n];
		size = new int[n];
		dfs(0);
		for (int i = 0; i < n; i++) {
			// System.out.println(dp[i]);
		}
		char[] cc = in.next().toCharArray();
		for (int i = 1; i < n; i++) {
			let[i] = cc[i - 1];
		}
		int m = in.nextInt();
		int[] good = new int[m];
		String[] words = new String[m];
		for (int i = 0; i < m; i++) {
			words[i] = in.next();
		}
		int countIterations = 10000;
		for (int it = 0; it < countIterations; it++) {
			String s = genRandom();
			// System.out.println(s);
			for (int i = 0; i < m; i++) {
				if (s.contains(words[i])) {
					good[i]++;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			out.print((good[i] * 1.0 / countIterations) + " ");
		}
		out.println();
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
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
	}

	public static void main(String[] arg) {
		new B().run();
	}
}