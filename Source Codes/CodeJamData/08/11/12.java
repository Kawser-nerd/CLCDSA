import java.io.*;
import java.util.*;

public class SolutionA implements Runnable {

	public static void main(String[] args) {
		new Thread(new SolutionA()).run();
	}

	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FILENAME + ".in"));
			out = new PrintWriter(FILENAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;

	PrintWriter out;

	StringTokenizer st;

	boolean eof;

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

	private static final String FILENAME = "A-large";

	public void solve() throws IOException {
		int testsn = nextInt();
		for (int test = 0; test < testsn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			long[] a = new long[n];
			long[] b = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextLong();
			}
			for (int i = 0; i < n; i++) {
				b[i] = nextLong();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += a[i] * b[n - 1 - i];
			}
			out.println(ans);
		}
	}
}
