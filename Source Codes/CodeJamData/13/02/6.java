import java.util.*;
import java.math.*;
import java.io.*;

public class B {
	
	static final int INFINITY = 100;
	
	private void solve() throws Exception {
		int n = nextInt(), m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
			}
		}
		boolean[][] changed = new boolean[n][m];
		while (true) {
			int minValue = INFINITY, minValueX = -1, minValueY = -1;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (!changed[x][y] && a[x][y] < minValue) {
						minValue = a[x][y];
						minValueX = x;
						minValueY = y;
					}
				}
			}
			if (minValue == INFINITY) {
				break;
			}
			boolean canChange = true;
			for (int x = 0; x < n; ++x) {
				if (!changed[x][minValueY] && a[x][minValueY] != minValue) {
					canChange = false;
				}
			}
			if (canChange) {
				for (int x = 0; x < n; ++x) {
					changed[x][minValueY] = true;
				}
				continue;
			}
			canChange = true;
			for (int y = 0; y < m; ++y) {
				if (!changed[minValueX][y] && a[minValueX][y] != minValue) {
					canChange = false;
				}
			}
			if (canChange) {
				for (int y = 0; y < m; ++y) {
					changed[minValueX][y] = true;
				}
				continue;
			}
			out.println("NO");
			return;
		}
		out.println("YES");
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private B(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		new B("B").run();
	}
}
