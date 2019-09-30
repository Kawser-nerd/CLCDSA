import java.io.*;
import java.util.*;
import java.math.*;

public class Road implements Runnable {

	public static void main(String[] args) {
		new Thread(new Road()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
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

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "road";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			s = new long[n][m];
			w = new long[n][m];
			t = new long[n][m];
			for (int i = 0; i < s.length; i++) {
				for (int j = 0; j < s[i].length; j++) {
					s[i][j] = nextInt();
					w[i][j] = nextInt();
					t[i][j] = nextInt() % (s[i][j] + w[i][j]);
				}
			}
			a = new long[2 * n][2 * m];
			for (int i = 0; i < a.length; i++) {
				Arrays.fill(a[i], Long.MAX_VALUE / 2);
			}
			dfs(2 * n - 1, 0, 0);
			out.println(a[0][2 * m - 1]);
		}
	}

	long[][] a;

	private void dfs(int x, int y, long time) {
		if (x < 0 || x >= a.length || y < 0 || y >= a[x].length) {
			return;
		}
		if (a[x][y] > time) {
			a[x][y] = time;
		} else {
			return;
		}
		long ph = (time - t[x / 2][y / 2] + s[x / 2][y / 2] + w[x / 2][y / 2])
				% (s[x / 2][y / 2] + w[x / 2][y / 2]);
		if (x % 2 == 0) {
			if (y % 2 == 0) {
				dfs(x - 1, y, time + 2);
				dfs(x, y - 1, time + 2);
				if (ph < s[x / 2][y / 2]) {
					dfs(x + 1, y, time + 1);
					dfs(x, y + 1, time + s[x / 2][y / 2] - ph + 1);
				} else {
					dfs(x, y + 1, time + 1);
					dfs(x + 1, y, time + s[x / 2][y / 2] + w[x / 2][y / 2] - ph
							+ 1);
				}
			} else {
				dfs(x - 1, y, time + 2);
				dfs(x, y + 1, time + 2);
				if (ph < s[x / 2][y / 2]) {
					dfs(x + 1, y, time + 1);
					dfs(x, y - 1, time + s[x / 2][y / 2] - ph + 1);
				} else {
					dfs(x, y - 1, time + 1);
					dfs(x + 1, y, time + s[x / 2][y / 2] + w[x / 2][y / 2] - ph
							+ 1);
				}
			}
		} else {
			if (y % 2 == 0) {
				dfs(x + 1, y, time + 2);
				dfs(x, y - 1, time + 2);
				if (ph < s[x / 2][y / 2]) {
					dfs(x - 1, y, time + 1);
					dfs(x, y + 1, time + s[x / 2][y / 2] - ph + 1);
				} else {
					dfs(x, y + 1, time + 1);
					dfs(x - 1, y, time + s[x / 2][y / 2] + w[x / 2][y / 2] - ph
							+ 1);
				}

			} else {
				dfs(x + 1, y, time + 2);
				dfs(x, y + 1, time + 2);
				if (ph < s[x / 2][y / 2]) {
					dfs(x - 1, y, time + 1);
					dfs(x, y - 1, time + s[x / 2][y / 2] - ph + 1);
				} else {
					dfs(x, y - 1, time + 1);
					dfs(x - 1, y, time + s[x / 2][y / 2] + w[x / 2][y / 2] - ph
							+ 1);
				}

			}

		}
	}

	long[][] s;
	long[][] w;
	long[][] t;

}
