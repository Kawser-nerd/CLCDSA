import java.io.*;
import java.util.*;
import java.math.*;

public class BBig {
	public static void main(String[] args) throws Throwable {
		new BBig().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(1897450987159L);

	private void run() throws Throwable {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	String FNAME = "b";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			m = new int[1 << n];
			for (int i = 0; i < m.length; i++) {
				m[i] = nextInt();
			}
			a = new int[1 << n];
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < 1 << i; j++) {
					a[(1 << i) + j] = nextInt();
				}
			}
			d = new long[a.length][11];
			dfs(1);
			long max = 0;
			for (int i = 0; i < d[1].length; i++) {
				max = Math.max(d[1][i], max);
			}
			max = -max;
			for (int i = 0; i < a.length; i++) {
				max += a[i];
			}
			out.println(max);
			// System.out.println(Arrays.toString(a));
			// System.out.println(Arrays.toString(m));
		}
	}

	private void dfs(int x) {
		if (2 * x >= a.length) {
			int i = x - (a.length / 2);
			int q = Math.min(m[2 * i], m[2 * i + 1]);
			d[x][q] = 0;
			for (int j = 0; j < q; j++) {
				d[x][j] = a[x];
			}
			for (int j = q + 1; j < d[x].length; j++) {
				d[x][j] = -1;
			}
			return;
		}
		dfs(2 * x);
		dfs(2 * x + 1);
		for (int i = 0; i < d[x].length; i++) {
			d[x][i] = -1;
			if (i + 1 < d[x].length && d[2 * x][i + 1] >= 0
					&& d[2 * x + 1][i + 1] >= 0) {
				d[x][i] = Math.max(d[x][i], a[x] + d[2 * x][i + 1]
						+ d[2 * x + 1][i + 1]);
			}
			if (d[2 * x][i] >= 0 && d[2 * x + 1][i] >= 0) {
				d[x][i] = Math.max(d[x][i], d[2 * x][i] + d[2 * x + 1][i]);
			}
		}
	}

	long[][] d;
	int[] a, m;
}
