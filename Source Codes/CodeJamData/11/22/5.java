import java.io.*;
import java.util.*;

public class B {

	static class Pair {
		final int a, b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}

	private void solve() throws IOException {
		int c = nextInt();
		int d = nextInt() * 2;
		Pair[] p = new Pair[c];
		int vendors = 0;
		for (int i = 0; i < c; i++) {
			p[i] = new Pair(2 * nextInt(), nextInt());
			vendors += p[i].b;
		}
		long l = -1, r = Long.MAX_VALUE / 2;
		while (r - l > 1) {
			long m = (r + l) >>> 1;
			if (check(p, d, m)) {
				r = m;
			} else {
				l = m;
			}
		}
		String res = (r / 2) + "." + (r % 2 == 0 ? "0" : "5");
		out.println(res);
	}

	static boolean check(Pair[] p, int d, long time) {
		int n = p.length;
		long last = Long.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			long pos = p[i].a - time;
			pos = Math.max(pos, last + d);
			long right = pos + (long) (p[i].b - 1) * d;
			if (right - p[i].a > time)
				return false;
			last = right;
		}
		return true;
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "B-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
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

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
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