import java.io.*;
import java.util.*;
import java.math.*;

public class DShit {
	public static void main(String[] args) throws Throwable {
		new DShit().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

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

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	String FNAME = "d";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			System.out.println(test);
			out.print("Case #" + test + ": ");
			n = nextLong();
			b = nextInt();
			ans = 0;
			for (int cnt = 0; cnt <= 10; cnt++) {
				bf(n, new int[cnt], cnt, n + 1);
			}
			out.println(ans);
		}
	}

	int ans = 0;
	int b;
	long n;

	private void bf(long n, int[] is, int cnt, long m) {
		if (cnt == 0) {
			if (n == 0) {
				check(is);
			}
			return;
		}
		cnt--;
		for (is[cnt] = 1; is[cnt] <= Math.min(m - 1, n); is[cnt]++) {
			bf(n - is[cnt], is, cnt, is[cnt]);
		}
	}

	private void check(int[] c) {
		int sum = 0;
		for (int i = 0; i < c.length; i++) {
			if (c[i] <= 0) {
				return;
			}
			sum += c[i];
		}
		if (sum != n) {
			return;
		}
		// System.out.println(Arrays.toString(c));
		boolean[][] u = new boolean[20][11];
		for (int i = 0; i < c.length; i++) {
			long[] s = toInt(c[i], b);
			for (int j = 0; j < s.length; j++) {
				int x = (int) s[s.length - 1 - j];
				if (u[j][x]) {
					return;
				}
				u[j][x] = true;
			}
		}
		ans++;
	}

	private long[] toInt(long n, int b) {
		long x = 1;
		int len = 0;
		while (x <= n) {
			x *= b;
			len++;
		}
		long[] a = new long[len];
		x /= b;
		for (int i = 0; i < a.length; i++) {
			a[i] = (int) (n / x);
			n %= x;
			x /= b;
		}
		return a;
	}

}