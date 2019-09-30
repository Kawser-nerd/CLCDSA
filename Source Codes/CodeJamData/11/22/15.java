package gcj20011r1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	private static final String TASKNAME = "b";

	private void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			printf("Case #%d: ", test);
			int n = nextInt();
			int d = nextInt();
			final int[] xs = new int[n];
			int[] vs = new int[n];
			Integer[] indices = new Integer[n];
			for (int i = 0; i< n; ++i) {
				xs[i] = nextInt();
				vs[i] = nextInt();
				indices[i] = i;
			}
			Arrays.sort(indices, new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					return xs[o1] - xs[o2];
				}
			});
			
			double l = 0;
			double r = 1e13;
			for (int it =0; it < 100; ++it) {
				double mid = (r + l) / 2;
				
				double x = -1e20;
				boolean fail = false;
				i: for (int i : indices) {
					for (int j = 0; j < vs[i]; ++j) {
						if (x + d <= xs[i]) {
							x = Math.max(x + d, xs[i] - mid);
						} else {
							x += d;
						}
						if (Math.abs(x - xs[i]) > mid + 1e-9) {
							fail = true;
							break i;
						}
					}
				}
				if (fail) {
					l = mid;
				} else {
					r = mid;
				}
			}
			
			if (Math.abs((long)(l * 2 + 0.5) - l * 2) > 1e-2) {
				throw new AssertionError();
			}
			l =0.5 * (long)(l * 2 + 0.5);
			
			printf("%.20f\n", l);
			System.err.println(test);
			writer.flush();
		}
	}

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(new OutputStreamWriter(System.out));
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new File(TASKNAME + ".out"));

			solve();

			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", (System.currentTimeMillis() - time) * 1e-3);
	}

	private StringTokenizer tokenizer;
	private PrintWriter writer;
	private BufferedReader reader;

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... args) {
		writer.printf(format, args);
	}
}
