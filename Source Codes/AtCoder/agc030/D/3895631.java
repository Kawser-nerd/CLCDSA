import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static final int MOD = 1000000007;
	static final int HALF = (MOD + 1) / 2;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		int n = scanInt();
		int q = scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		int v[][] = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = a[i] < a[j] ? 1 : 0;
			}
		}
		for (int qq = 0; qq < q; qq++) {
			int x = scanInt() - 1;
			int y = scanInt() - 1;
			for (int i = 0; i < n; i++) {
				if (i != x && i != y) {
					v[i][x] = v[i][y] = mul(v[i][x] + v[i][y], HALF);
					v[x][i] = v[y][i] = mul(v[x][i] + v[y][i], HALF);
				}
			}
			v[x][y] = v[y][x] = mul(v[x][y] + v[y][x], HALF);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				ans = add(ans, v[i][j]);
			}
		}
		for (int i = 0; i < q; i++) {
			ans = add(ans, ans);
		}
		out.print(ans);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}