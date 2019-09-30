import java.io.*;
import java.util.*;

public class Main {

	int solve(char[] a, char[] b) {
		if (Arrays.equals(a, b)) {
			return 0;
		}

		boolean bZero = true;
		for (char c : b) {
			bZero &= c == '0';
		}

		if (bZero) {
			return -1;
		}

		int n = a.length;

		int[] diff = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (b[(j + i) % n] != a[j]) {
					diff[i]++;
				}
			}
		}

		boolean[][] bad = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			if (a[i] == '1') {

				if (b[i] == '1') {
					continue;
				}

				int pos = 0;
				while (b[(i + pos) % n] == '0') {
					pos++;
				}

				int neg = 0;
				while (b[(i + n - neg) % n] == '0') {
					neg++;
				}

				// x >= pos or y >= neg
				bad[pos - 1][neg - 1] = true;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (bad[i][j]) {
					if (i > 0) {
						bad[i - 1][j] = true;
					}
					if (j > 0) {
						bad[i][j - 1] = true;
					}
				}
			}
		}

		int ret = Integer.MAX_VALUE;

		for (int pos = 0; pos < n; pos++) {

			boolean isFirst = true;

			for (int neg = 0; pos + neg < n; neg++) {

				if (bad[pos][neg]) {
					continue;
				}

				if (isFirst) {

					for (int end = -neg; end <= pos; end++) {

						int path = getPath(0, -neg, pos, end);
						ret = Math.min(ret, path + diff[(end + n) % n]);

					}
					isFirst = false;

				} else {
					int end = -neg;
					{

						int path = getPath(0, -neg, pos, end);
						ret = Math.min(ret, path + diff[(end + n) % n]);

					}
				}

			}

		}
		
		return ret;

	}
	
	void submit() {
		char[] a = nextToken().toCharArray();
		char[] b = nextToken().toCharArray();
		
		out.println(solve(a, b));
	}

	int getPath(int from, int c1, int c2, int to) {
		return Math.min(getOrderedPath(from, c1, c2, to),
				getOrderedPath(from, c2, c1, to));
	}

	int getOrderedPath(int a, int b, int c, int d) {
		return Math.abs(b - a) + Math.abs(c - b) + Math.abs(d - c);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
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