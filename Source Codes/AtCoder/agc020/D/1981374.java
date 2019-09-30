import java.io.*;
import java.util.*;

public class Main {

	void preCalc() {

	}

	void stress() {
	}

	int fastVal(int a, int b) {
		if (a < b) {
			int tmp = a;
			a = b;
			b = tmp;
		}

		return ceilDiv(a, b + 1);
	}

	String f(int a, int b) {
		int[] p = new int[a];
		for (int i = 0; i < a; i++) {
			p[i] = i;
		}
		char[] buf = new char[a + b];

		int lookVal = fastVal(a, b);

		outer: do {
			Arrays.fill(buf, 'B');
			for (int i : p) {
				buf[i] = 'A';
			}

			// String tmp = new String(tmp);

			int cur = 1;
			for (int i = 1; i < a + b; i++) {
				if (buf[i] != buf[i - 1]) {
					cur = 1;
				} else {
					cur++;
				}
				if (cur > lookVal) {
					continue outer;
				}
			}

			return new String(buf);

		} while (nextCombination(p, a + b));

		throw new AssertionError();
	}

	static boolean nextCombination(int[] a, int n) {
		int k = a.length;
		int ptr = k - 1;
		while (ptr >= 0 && a[ptr] == ptr - k + n) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}
		a[ptr]++;
		for (int i = ptr + 1; i < k; i++) {
			a[i] = a[ptr] + i - ptr;
		}
		return true;
	}

	void test() {

		// System.err.println(f(17, 7));
		// System.err.println(solve(7, 17, 0, 2));

		int C = 14;

//		for (int a = 1; a <= C; a++) {
//			for (int b = 1; b <= C; b++) {
//				System.err.println(a + " " + b + " " + f(a, b));
//			}
//		}

		for (int a = 1; a <= C; a++) {
			for (int b = 1; b <= C; b++) {
				String s = f(a, b);

				for (int j = 0; j < s.length(); j++) {
					for (int k = j; k < s.length(); k++) {
						 String fast = solve(a, b, j, k);
//						String fast = "";
						String slow = s.substring(j, k + 1);
						if (!fast.equals(slow)) {
							// System.err.println(f(a, b));
							// System.err.println(fastF(a, b));
							throw new AssertionError(a + " " + b + " " + j
									+ " " + k);
						}
					}
				}

			}
		}

	}

	String solve(int a, int b, int c, int d) {
		int k = fastVal(a, b);
		int low = 0; // >=
		int high = a + 1;

		while (high - low > 1) {
			int mid = (low + high) >> 1;

			int bs = Math.floorDiv(mid - 1, k);

			int leftA = a - mid;
			int leftB = b - bs;

			if (leftB <= (leftA + 1) * (long) k) {
				low = mid;
			} else {
				high = mid;
			}
		}

		int lenFirst = low + Math.floorDiv(low - 1, k);

		char[] buf = new char[d - c + 1];
		for (int i = c; i <= d; i++) {
			if (i < lenFirst) {
				buf[i - c] = i % (k + 1) == k ? 'B' : 'A';
			} else {
				int j = a + b - 1 - i;
				buf[i - c] = j % (k + 1) == k ? 'A' : 'B';
			}
		}
		return new String(buf);
	}

	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
	}

	void submit() {
		int q = nextInt();
		while (q-- > 0) {
			int a = nextInt();
			int b = nextInt();
			int c = nextInt() - 1;
			int d = nextInt() - 1;
			out.println(solve(a, b, c, d));
		}
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		preCalc();
		 submit();
		// stress();
//		System.err.println(solve(1, 1, 0, 0));
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
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
}