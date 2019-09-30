import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import static java.lang.Math.*;

public class B implements Runnable {
	private void solution() throws IOException {
		int numberOfTests = in.nextInt();
		long globalStartTime = System.currentTimeMillis();
		for (int testCase = 1; testCase <= numberOfTests; ++testCase) {
			// long localStartTime = System.currentTimeMillis();
			//
			Object res = solve();
			out.printf("Case #%d: %s\n", testCase, res);
			//
			// System.err.println("Test " + testCase + " is done. Time = " +
			// (System.currentTimeMillis() - localStartTime) / 1000.0);
		}
		System.err.println("Total time = " + (System.currentTimeMillis() - globalStartTime) / 1000.0);
	}

	private Object solve() throws IOException {
		int n = in.nextInt();
		int[] one = new int[n];
		int[] two = new int[n];
		for (int i = 0; i < n; ++i) {
			one[i] = in.nextInt();
			two[i] = in.nextInt();
		}
		int has = 0;
		for (int step = 0;; ++step) {
			int index = -1;
			boolean all = true;
			for (int i = 0; i < n; ++i) {
				if (two[i] != -1) {
					all = false;
					if (one[i] == -1 && two[i] != -1 && has >= two[i]) {
						index = i;
						break;
					}
					if (one[i] != -1) {
						if (has >= two[i]) {
							index = i;
							break;
						} else if (has >= one[i]) {
							if (index == -1) {
								index = i;
							} else if (two[i] > two[index]) {
								index = i;
							}
						}
					}
				}
			}
			if (all) {
				return ("" + step);
			}
			if (index == -1) {
				return "Too Bad";
			}
			if (one[index] != -1) {
				if (has >= two[index]) {
					one[index] = two[index] = -1;
					has += 2;
				} else {
					one[index] = -1;
					has += 1;
				}
			} else {
				two[index] = -1;
				has += 1;
			}
		}
	}

	public void run() {
		try {
			try {
				String fileName = "B-large";
				in = new Scanner(new FileReader(fileName + ".in"));
				out = new PrintWriter(fileName + ".out");
			} catch (Exception e) {
			}
			solution();
			in.reader.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private void output(Object o) {
		try {
			int length = Array.getLength(o);
			for (int i = 0; i < length; ++i) {
				if (i != 0) {
					out.print(' ');
				}
				Object cur = Array.get(o, i);
				if (cur instanceof Double) {
					out.printf(Locale.US, "%.9f", cur);
				} else {
					out.print(cur);
				}
			}
			out.println();
		} catch (Exception e) {
			if (o instanceof Double) {
				out.printf(Locale.US, "%.9f\n", o);
			} else {
				out.println(o);
			}
		}
	}

	private static class Scanner {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader reader) {
			this.reader = new BufferedReader(reader);
			this.tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				String line = reader.readLine();
				if (line == null) {
					return false;
				}
				tokenizer = new StringTokenizer(line);
			}
			return true;
		}

		public String next() throws IOException {
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		private long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}

		public int[] nextInts(int n) throws IOException {
			int[] res = new int[n];
			for (int i = 0; i < n; ++i) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongs(int n) throws IOException {
			long[] res = new long[n];
			for (int i = 0; i < n; ++i) {
				res[i] = nextLong();
			}
			return res;
		}

		public double[] nextDoubles(int n) throws IOException {
			double[] res = new double[n];
			for (int i = 0; i < n; ++i) {
				res[i] = nextDouble();
			}
			return res;
		}

		public String[] nextStrings(int n) throws IOException {
			String[] res = new String[n];
			for (int i = 0; i < n; ++i) {
				res[i] = next();
			}
			return res;
		}
	}

	public static void main(String[] args) {
		new Thread(null, new B(), "Main", 1 << 28).start();
	}

	private Scanner in = new Scanner(new InputStreamReader(System.in));
	private PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}
