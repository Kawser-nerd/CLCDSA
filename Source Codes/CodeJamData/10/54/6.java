import java.io.*;
import java.util.*;

public class D implements Runnable {

	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public final boolean large = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			String FN = "D-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
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

	int n, b;
	int ans;

	int[] numbers;
	int cnt;
	boolean[][] digits;
	ArrayList<Integer> result;

	void go(int sum, int max) {
		if (sum == 0) {
			ans++;
//			System.err.println(result);
			return;
		}
		for (int i = Math.min(max - 1, sum); i > 0; i--) {
			int j = i;
			int bad = -1;
			String s = new StringBuilder(Integer.toString(i, b)).reverse()
					.toString();

			for (int it = s.length() - 1; it >= 0; it--) {
				if (digits[it][s.charAt(it) - '0']) {
					bad = it;
					break;
				}
				digits[it][s.charAt(it) - '0'] = true;
			}
			if (bad == -1) {
//				result.add(i);
				go(sum - i, i);
//				result.remove(result.size() - 1);
			}
			for (int it = s.length() - 1; it >= 0 && it != bad; it--) {
				digits[it][s.charAt(it) - '0'] = false;
			}

		}
	}

	private void solve() throws IOException {
		n = nextInt();
		b = nextInt();
		digits = new boolean[20][b];
		cnt = 0;
		result = new ArrayList<Integer>();
		ans = 0;
		go(n, n + 1);
		out.println(ans);
	}
}