package gcj20011r1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	private static final String TASKNAME = "a";

	private void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
			char[][] grid = new char[n][];
			for (int i = 0; i < n; ++i) {
				grid[i] = nextToken().toCharArray();
			}
			
			double[] wp = new double[n];
			double[] owp = new double[n];
			for (int i = 0; i < n; ++i) {
				int win = 0;
				int play = 0;
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] != '.') {
						++play;
					}
					if (grid[i][j] == '1') {
						++win;
					}
				}
				wp[i] = 1. * win / play;
				double sum = 0;
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] != '.') {
						win = 0;
						int cplay = 0;
						for (int k = 0; k < n; ++k) {
							if (k != i && grid[j][k] != '.') {
								++cplay;
							}
							if (k != i && grid[j][k] == '1') {
								++win;
							}
						}
						sum += 1. * win / cplay;
					}
				}
				owp[i] = sum / play;
			}
			printf("Case #%d:\n", test);
			System.err.println("test "+ test);
			for (int i = 0; i < n; ++i) {
				double oowp = 0;
				int play = 0;
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] !='.') {
						oowp += owp[j];
						++play;
					}
				}
				oowp /= play;
				double ans = wp[i] * 0.25 + 0.5 * owp[i] + 0.25 * oowp;
				printf("%.20f\n", ans);
			}
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
