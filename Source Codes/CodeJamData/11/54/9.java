import java.io.*;
import java.util.*;

public class D {

	private void solve() throws IOException {
		String s = nextToken();
		s = new StringBuilder(s).reverse().toString();
		int qcnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '?')
				qcnt++;
		}
		int[] q = new int[qcnt];
		qcnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '?')
				q[qcnt++] = i;
		}
		long res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				res |= 1L << i;
			}
		}
		for (int mask = 0; mask < 1 << qcnt; mask++) {
			long cur = res;
			for (int i = 0; i < qcnt; i++) {
				if ((mask & (1 << i)) != 0) {
					cur |= 1L << q[i];
				}
			}
			if (isSquare(cur)) {
				out.println(Long.toBinaryString(cur));
				return;
			}
		}
		System.err.println("NOT GOOD");
	}

	boolean isSquare(long val) {
		double root = Math.sqrt(val);
		long r = Math.round(root);
		while (r * r < val)
			r++;
		while (r * r > val)
			r--;
		return r * r == val;
	}

	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = false;

	public void run() {
		try {
			String fileName = "D-" + (large ? "large" : "small");
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