import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 924844033;

	int[] go(int a, int b) {
		// 0 - can't take prev
		// 1 - can
		int[][] dp = new int[1][2];
		dp[0][1] = 1;
		for (int i = 1; i <= a; i++) {
			int[][] nxt = new int[i + 1][2];
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < 2; k++) {

					// skip
					int delta = dp[j][k];
					nxt[j][1] += delta;
					if (nxt[j][1] >= P) {
						nxt[j][1] -= P;
					}

					// take prev
					if (k == 1 && (a < b || i != 1)) {
						nxt[j + 1][1] += delta;
						if (nxt[j + 1][1] >= P) {
							nxt[j + 1][1] -= P;
						}
					}

					// take next
					nxt[j + 1][0] += delta;
					if (nxt[j + 1][0] >= P) {
						nxt[j + 1][0] -= P;
					}
				}
			}
			dp = nxt;
		}
		int[] ret = new int[a + 1];
		for (int i = 0; i <= a; i++) {
			ret[i] = (dp[i][0] + dp[i][1]) % P;
		}
		// System.err.println(a + " " + b + " " + Arrays.toString(ret));
		return ret;
	}

	int[] go(int n) {
		int[] tmp = go(n / 2, (n + 1) / 2);
		return mult(tmp, tmp);
	}

	int[] mult(int[] a, int[] b) {
		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				c[i + j] += (int) ((long) a[i] * b[j] % P);
				if (c[i + j] >= P) {
					c[i + j] -= P;
				}
			}
		}
		return c;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] dp = { 1 };

		for (int rem = 0; rem < k; rem++) {
			int cnt = (n - rem + k - 1) / k;
			dp = mult(dp, go(cnt));
		}

//		System.err.println(Arrays.toString(dp));

		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % P);
		}

		int ans = fact[n];
		for (int i = 1; i <= n && i < dp.length; i++) {
			int delta = (int) ((long) dp[i] * fact[n - i] % P);
			if ((i & 1) == 1 && delta != 0) {
				delta = P - delta;
			}
			ans += delta;
			if (ans >= P) {
				ans -= P;
			}
		}

		out.println(ans);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}