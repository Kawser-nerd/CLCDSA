import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	int[] goNoEmpty(int n, int k) {
		int[] ret = new int[n + 1];
		int[] dp = { 1 };
		int p2 = 1;
		for (int i = 1; i <= n; i++) {
			int[] nxt = new int[i + 1];
			for (int j = 1; j <= i; j++) {
				nxt[j] = (dp[j - 1] + (j + 1 < i ? dp[j + 1] : 0)) % P;
			}
			dp = nxt;
			if (i >= k && (i - k) % 2 == 0) {
				ret[i] = (int) ((long) dp[k] * p2 % P);
				p2 = 2 * p2 % P;
			}
		}
		return ret;
	}
	
	int[] goEmpty(int n) {
		int[] ret = new int[n + 1];
		ret[0] = 1;
		int[] dp = { 1 };
		for (int i = 1; i <= n; i++) {
			int[] nxt = new int[i + 1];
			nxt[0] = i == 1 ? 1 : (dp[0] + dp[1]) % P;
			for (int j = 1; j <= i; j++) {
				nxt[j] = (2 * dp[j - 1] % P + (j + 1 < i ? dp[j + 1] : 0)) % P;
			}
			dp = nxt;
			ret[i] = dp[0];
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextToken().length();

		int[] noEmpty = goNoEmpty(n, k);
		int[] empty = goEmpty(n);
		
		int ret = 0;
		for (int i = 0; i <= n; i++) {
			ret += (int)((long)noEmpty[i] * empty[n - i] % P);
			ret %= P;
		}
		
		out.println(ret);
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