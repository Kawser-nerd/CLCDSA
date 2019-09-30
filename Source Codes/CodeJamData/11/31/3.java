import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(125475452);

	private void run() {
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

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "A-large";

	private void solve() throws IOException {
		int T = nextInt();
		for (int test = 1; test <= T; ++test) {
			int n = nextInt();
			int m = nextInt();
			char[][] c = new char[n][];
			for (int i = 0; i < n; ++i) {
				c[i] = nextToken().toCharArray();
			}
			boolean good = true;
			loop:
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (c[i][j] == '#') {
						if (i + 1 >= n || j + 1 >= m || c[i + 1][j] != '#' || c[i][j + 1] != '#' || c[i + 1][j + 1] != '#') {
							good = false;
							break loop;
						} else {
							c[i][j] = '/';
							c[i + 1][j] = '\\';
							c[i][j + 1] = '\\';
							c[i + 1][j + 1] = '/';
						}
					}
				}
			}
			out.println("Case #" + test + ":");
			if (!good) {
				out.println("Impossible");
			} else {
				for (char[] s : c) {
					out.println(new String(s));
				}
			}
		}
	}
}