import java.io.*;
import java.util.*;
import java.math.*;

public class SolD implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolD()).start();
	}

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;
	Random random = new Random(43965743875L);

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

	String FNAME = "D-small-attempt0";
	
	int ans;
	
	boolean can(int[] x, int b, int y) {
		String sy = Integer.toString(y, b);
		for (int i = 0; i < x.length; i++) {
			String sx = Integer.toString(x[i], b);
			for (int j = 0; j < sy.length() && j < sx.length(); j++) {
				if (sx.charAt(sx.length() - j - 1) == sy.charAt(sy.length() - j - 1)) {
					return false;
				}
			}
		}
		return true;
	}
	
	void bt(int sum, int b, int[] x, int max) {
		if (sum == 0) {
			ans++;
			ans %= 1000000007;
			return;
		}
		int[] y = new int[x.length + 1];
		for (int i = 0; i < x.length; i++) {
			y[i] = x[i];
		}
		max = Math.min(max, sum);
		for (int i = max; i > 0; i--) {
			if (can(x, b, i)) {
				y[x.length] = i;
				bt(sum - i, b, y, i - 1);
			}
		}
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			System.out.println(test);
			out.print("Case #" + test + ": ");

			int n = nextInt();
			int b = nextInt();
			ans = 0;
			bt(n, b, new int[0], n);
			out.println(ans);
		}
	}
}
