import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	String fn = "A-large";

	void out(char[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				System.err.print(a[i][j]);
			}
			System.err.println();
		}
		System.err.println();
	}

	void solve2() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[][] a = new char[n][n];
		for (int i = 0; i < a.length; i++) {
			String s = br.readLine();
			for (int j = 0; j < a.length; j++) {
				a[j][i] = s.charAt(j);
			}
		}
		out(a);
		for (int it = 0; it < n; it++) {
			for (int i = n - 2; i >= 0; i--) {
				for (int j = 0; j < a.length; j++) {
					if (a[i + 1][j] == '.' && a[i][j] != '.') {
						a[i + 1][j] = a[i][j];
						a[i][j] = '.';
					}
				}
			}
		}
		out(a);
		boolean R = false;
		boolean B = false;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				R |= check(a, i, j, 'R', k);
				B |= check(a, i, j, 'B', k);
			}
		}
		if (R && B) {
			out.println("Both");
		} else if (R) {
			out.println("Red");
		} else if (B) {
			out.println("Blue");
		} else {
			out.println("Neither");
		}
	}

	private boolean check(char[][] a, int x, int y, char c, int k) {
		ford: for (int d = 0; d < DX.length; d++) {
			for (int i = 0; i < k; i++) {
				if (x + DX[d] * i >= 0 && x + DX[d] * i < a.length && y + DY[d] * i >= 0 && y + DY[d] * i < a.length
						&& a[x + DX[d] * i][y + DY[d] * i] == c) {
				} else {
					continue ford;
				}
			}

			return true;
		}
		return false;
	}

	int DX[] = { 1, 0, 1, 1 };
	int DY[] = { 0, 1, 1, -1 };

	void solve() throws IOException {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve2();
		}

	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			br = new BufferedReader(new FileReader(fn + ".in"));
			out = new PrintWriter(fn + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(123);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
			throw new AssertionError();
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) {
		new A().run();
	}
}
