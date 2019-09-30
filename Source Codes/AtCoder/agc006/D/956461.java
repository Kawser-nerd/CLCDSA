import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int goFast(int[] a) {
		int len = a.length;
		int mid = len / 2;

		int ans = -1;
		int bestDist = Integer.MAX_VALUE;

		for (int i = 0; i < a.length;) {
			int j = i;
			while (j < a.length && a[i] == a[j]) {
				j++;
			}

			if (j - i > 1) {
				if (i <= mid && mid < j) {
					return a[i];
				}
				int dist = Math.min(Math.abs(mid - (j - 1)), Math.abs(mid - i));
				if (dist < bestDist) {
					bestDist = dist;
					ans = a[i];
				}
			}

			i = j;
		}

		if (ans != -1) {
			return ans;
		}

		return a[0];
	}

	int go(int[] a) {
		while (a.length > 1) {
			int[] b = new int[a.length - 2];
			for (int i = 0; i < b.length; i++) {
				b[i] = a[i] + a[i + 1] + a[i + 2];
				if (b[i] <= 1) {
					b[i] = 0;
				} else {
					b[i] = 1;
				}
			}
			a = b;
		}
		return a[0];
	}

	int solve(int[] perm) {
		int n = perm.length / 2 + 1;

		int high = 2 * n - 1; // ans <= high
		int low = 0; // ans > 0

		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int[] tmp = new int[perm.length];
			for (int i = 0; i < perm.length; i++) {
				tmp[i] = perm[i] <= mid ? 0 : 1;
			}
			// if (go(tmp) == 0) {
			if (goFast(tmp) == 0) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return high;
	}

	static int get(int mask, int i) {
		return (mask >> i) & 1;
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		// int[] wtf = { 0, 1, 1, 0, 1, 0, 0 };

		// System.err.println(goFast(wtf));

		// for (int n = 3; n <= 15; n += 2) {
		// for (int mask = 0; mask < (1 << n); mask++) {
		// int[] tst = new int[n];
		// for (int i = 0; i < n; i++) {
		// tst[i] = get(mask, i);
		// }
		//
		// if (go(tst) != goFast(tst)) {
		// throw new AssertionError(Arrays.toString(tst));
		// }
		// }
		// }

		int n = nextInt();
		int[] a = new int[2 * n - 1];
		for (int i = 0; i < 2 * n - 1; i++) {
			a[i] = nextInt();
		}
		out.println(solve(a));
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