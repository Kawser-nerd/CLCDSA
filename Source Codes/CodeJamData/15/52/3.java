import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	static final long INF = 1_000_000_000_000_000L;

	static class Bounds {
		long low, high;

		public Bounds(long low, long high) {
			this.low = low;
			this.high = high;
		}

		@Override
		public String toString() {
			return "[low=" + low + ", high=" + high + "]";
		}
	}

	boolean can(Bounds[] a, long bound, long needRem) {

		// [0..bound]

		long lowSum = 0;
		long highSum = 0;

		for (int i = 0; i < a.length; i++) {
			long low = -a[i].low;
			long high = bound - a[i].high;
			if (low > high) {
				return false;
			}
			lowSum += low;
			highSum += high;
		}

		// System.err.println(lowSum + " " + highSum + " " + needRem);

		long tmp = Math.floorDiv(highSum - needRem, a.length) * a.length
				+ needRem;
		return tmp >= lowSum;

	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		long[] sum = new long[n - k + 1];
		for (int i = 0; i < sum.length; i++) {
			sum[i] = nextLong();
		}
		long[] diff = new long[n];
		for (int i = k; i < n; i++) {
			diff[i] = diff[i - k] + (sum[i - k + 1] - sum[i - k]);
		}

		Bounds[] a = new Bounds[k];

		for (int rem = 0; rem < k; rem++) {
			long low = 0;
			long high = 0;
			for (int i = rem; i < n; i += k) {
				low = Math.min(low, diff[i]);
				high = Math.max(high, diff[i]);
			}
			a[rem] = new Bounds(low, high);
		}

		long low = -1;
		long high = INF;

		while (high - low > 1) {
			long mid = (low + high) >> 1;
			if (can(a, mid, Math.floorMod(sum[0], k))) {
				high = mid;
			} else {
				low = mid;
			}
		}

		// System.err.println(can(a, 4, Math.floorMod(sum[0], k)));

		out.println(high);

	}

	B() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("B-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("B-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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