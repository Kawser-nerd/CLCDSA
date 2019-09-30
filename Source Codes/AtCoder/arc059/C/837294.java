import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	int[] getSums(int from, int to, int c) {
		int[] a = new int[to - from + 1];
		Arrays.fill(a, 1);

		int[] ret = new int[c + 1];
		for (int i = 0; i <= c; i++) {
			if (i != 0) {
				for (int j = from; j <= to; j++) {
					a[j - from] = (int) ((long) a[j - from] * j % P);
				}
			}

			for (int j = 0; j <= to - from; j++) {
				ret[i] = (ret[i] + a[j]) % P;
			}
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int c = nextInt();

		int[] dp = new int[c + 1];
		dp[0] = 1;

		int[] low = new int[n];
		int[] high = new int[n];

		for (int i = 0; i < n; i++) {
			low[i] = nextInt();
		}

		for (int i = 0; i < n; i++) {
			high[i] = nextInt();
		}

		for (int i = 0; i < n; i++) {
			int[] sums = getSums(low[i], high[i], c);
			
			int[] nxt = new int[c + 1];
			for (int from = 0; from <= c; from++) {
				for (int to = from; to <= c; to++) {
					nxt[to] += (int)((long)dp[from] * sums[to - from] % P);
					nxt[to] %= P;
				}
			}
			
			dp = nxt;
		}
		
		out.println(dp[c]);
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