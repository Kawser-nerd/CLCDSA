import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

		List<List<Integer>> edges = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			edges.add(new ArrayList<>());
		}
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;

			edges.get(a).add(b);
			edges.get(b).add(a);
		}

		int k = sc.nextInt();

		int[] minv = new int[n];
		int[] maxv = new int[n];
		Arrays.fill(minv, -INF);
		Arrays.fill(maxv, INF);
		int v1 = 0;
		for (int i = 0; i < k; i++) {
			int v = sc.nextInt() - 1;
			int p = sc.nextInt();

			minv[v] = p;
			maxv[v] = p;
			if (i == 0) {
				v1 = v;
			}
		}

		for (int i = 0; i < 2; i++) {
			Deque<Integer> q = new ArrayDeque<>();
			boolean[] used = new boolean[n];
			int[] pa = new int[n];
			Arrays.fill(pa, -1);
			q.add(v1);
			pa[v1] = v1;

			while (!q.isEmpty()) {
				int e = q.peek();

				if (used[e]) {
					for (int next : edges.get(e)) {
						if (next != pa[e]) {
							if (!isOK(next, e, minv, maxv)) {
								pr.println("No");
								return;
							}
						}
					}

					q.pop();
				} else {
					for (int next : edges.get(e)) {
						if (next != pa[e]) {
							if (!isOK(e, next, minv, maxv)) {
								pr.println("No");
								return;
							}

							q.push(next);
							pa[next] = e;
						}
					}
					used[e] = true;
				}
			}
		}

		pr.println("Yes");
		for (int i = 0; i < n; i++) {
			pr.println(minv[i]);
		}
	}

	private static final int INF = Integer.MAX_VALUE / 2;

	private static boolean isOK(int e, int next, int[] minv, int[] maxv) {
		if (minv[e] % 2 == 0 && minv[next] > -INF && minv[next] % 2 == 0) {
			return false;
		} else if (minv[e] % 2 != 0 && minv[next] > -INF && minv[next] % 2 != 0) {
			return false;
		}

		if (minv[e] > maxv[next] + 1 || maxv[e] < minv[next] - 1) {
			return false;
		}

		minv[next] = Math.max(minv[next], minv[e] - 1);
		maxv[next] = Math.min(maxv[next], maxv[e] + 1);

		return true;
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		private boolean isPrintable(int ch) {
			return ch >= '!' && ch <= '~';
		}

		private boolean isCRLF(int ch) {
			return ch == '\n' || ch == '\r' || ch == -1;
		}

		private int nextPrintable() {
			try {
				int ch;
				while (!isPrintable(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}

				return ch;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		String next() {
			try {
				int ch = nextPrintable();
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (isPrintable(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		int nextInt() {
			try {
				// parseInt from Integer.parseInt()
				boolean negative = false;
				int res = 0;
				int limit = -Integer.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Integer.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				int multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		long nextLong() {
			try {
				// parseLong from Long.parseLong()
				boolean negative = false;
				long res = 0;
				long limit = -Long.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Long.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				long multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				int ch;
				while (isCRLF(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (!isCRLF(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new NoSuchElementException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}