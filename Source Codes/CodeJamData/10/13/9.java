package q1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "c";

	private int[][] dp;

	private int getDp(int a, int b) {
		if (dp[a][b] != -1) {
			return dp[a][b];
		}

		// System.err.println(a + " " + b);
		int res = 0;
		for (int i = 1; a - i * b > 0; ++i) {
			res |= 1 - getDp(a - b * i, b);
		}
		for (int i = 1; b - i * a > 0; ++i) {
			res |= 1 - getDp(a, b - i * a);
		}

		return dp[a][b] = res;
	}
	
	private static final double PHI = (1+Math.sqrt(5))/2.0;

	private void solve() throws Exception {
//		test();
		 final int testN = nextInt();
		 for (int test = 1; test <= testN; ++test) {
			 int a1 = nextInt();
			 int a2 = nextInt();
			 int b1 = nextInt();
			 int b2 = nextInt();
			 long answer = 0;
			 for (int i = a1; i <= a2; ++i) {
				 final int intersection = intersection(getFirst(i), getLast(i) + 1, b1, b2 + 1);
//				 System.err.println(i + ": " + intersection);
				answer += b2 - b1 + 1 - intersection;
			 }
			 printf("Case #%d: %d\n", test, answer);
		 }
	}

	private void test() {
		dp = new int[200][200];
		for (int[] a : dp) {
			Arrays.fill(a, -1);
		}
		for (int i = 1; i < 50; ++i) {
			System.err.print(i + ": ");
			for (int j = 1; j < 50; ++j) {
				System.err.print(getDp(i, j) + " ");
				System.err.flush();
			}
			System.err.println();
		}
		for (int i = 1; i <= 100; ++i) {
			int last = -1;
			int first = -1;
			for (int j = 1; j <= 100; ++j) {
				if (dp[i][j] == 0) {
					last = j;
					if (first == -1) {
						first = j;
					}
				}
			}
			System.err.print((last == getLast(i) && first == getFirst(i)) + ", ");
//			System.err.println(i + ": " + first + " " + last + "      " + (last - first + 1) + " " + (i - first) + " " + (last + first));
		}
	}
	
	private int intersection(int a, int b, int c, int d) {
//		System.err.println(a + " " + b + " " + c + " "  + d);
		return Math.max(0, Math.min(b, d) - Math.max(a, c));
	}
	
	private int getFirst(int i) {
		return getLast(i) - i + 1;
	}

	private int getLast(int i) {
		return (int)Math.floor(PHI * i + 1e-9);
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(TASKNAME
					+ ".out")));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			throw new AssertionError(e);
		}
	}

	private void print(final Object o) {
		writer.print(o);
	}

	private void println(final Object o) {
		writer.println(o);
	}

	private void printf(final String format, final Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws InterruptedException {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		final Thread thread = new Thread(null, new Main(), "", 1 << 23);
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}
}
