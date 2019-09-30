import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		ProblemD solver = new ProblemD();
		solver.solve(1, in, out);
		out.close();
	}

	static class ProblemD {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();

			final int N = 10000;
			boolean[] isPrime = new boolean[N];
			List<Integer> primes = new ArrayList<>();
			Arrays.fill(isPrime, true);
			for (int i = 2; i < N; i++) {
				if (isPrime[i]) {
					primes.add(i);
					for (int j = i + i; j < N; j += i) {
						isPrime[j] = false;
					}
				}
			}

//		for (int i = 2; i <= 500; i++) {
//			solve(primes, i);
//			if (i % 10 == 0) {
//				System.out.println(i);
//			}
//		}

			long[][] a = solve(primes, n);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j > 0) {
						out.print(" ");
					}
					out.print(a[i][j]);
				}
				out.println();
			}
		}

		private long[][] solve(List<Integer> primes, int n) {
			long[][] a = new long[n][n];

			Set<Long> set = new HashSet<>();
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if ((r + c) % 2 == 0) {
						a[r][c] = primes.get((r + c) / 2) * primes.get((r - c) / 2 + n);
						set.add(a[r][c]);
					}
				}
			}

			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if ((r + c) % 2 == 1) {
						long cur = 1;
						for (int dr = -1; dr <= 1; dr++) {
							for (int dc = -1; dc <= 1; dc++) {
								if (dr == 0 ^ dc == 0) {
									int nr = r + dr;
									int nc = c + dc;
									if (nr >= 0 && nr < n && nc >= 0 && nc < n && a[nr][nc] != 0) {
										cur = lcm(cur, a[nr][nc]);
									}
								}
							}
						}
						long x = cur + 1;
						while (set.contains(x)) {
							x += cur;
						}
						a[r][c] = x;
						set.add(a[r][c]);
					}
				}
			}

			if (!check(a)) {
				throw new AssertionError();
			}

			return a;
		}

		private boolean check(long[][] a) {
			int n = a.length;
			Set<Long> set = new HashSet<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (set.contains(a[i][j])) {
						System.out.println("bad elem " + a[i][j]);
						return false;
					}
					set.add(a[i][j]);
					if (i + 1 < n) {
						long u = a[i][j];
						long v = a[i + 1][j];
						if (Math.max(u, v) % Math.min(u, v) != 1) {
							System.out.println("! " + u + " " + v);
							return false;
						}
					}
					if (j + 1 < n) {
						long u = a[i][j];
						long v = a[i][j + 1];
						if (Math.max(u, v) % Math.min(u, v) != 1) {
							System.out.println("! " + u + " " + v);
							return false;
						}
					}
				}
			}
			return set.size() == n * n;
		}

		private long lcm(long a, long b) {
			return a / gcd(a, b) * b;
		}

		private long gcd(long a, long b) {
			return b == 0 ? a : gcd(b, a % b);
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}