import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		List<List<Integer>> edges = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			edges.add(new ArrayList<>());
		}

		for (int i = 0; i < n - 1; i++) {
			int aa = sc.nextInt() - 1;
			int bb = sc.nextInt() - 1;

			edges.get(aa).add(bb);
			edges.get(bb).add(aa);
		}

		boolean[] used = new boolean[n];
		int[] p = new int[n];

		int root = 0;
		for (int i = 0; i < n; i++) {
			if (edges.get(i).size() > 1) {
				root = i;
				break;
			}
		}

		List<Integer> vl = new ArrayList<>();
		Deque<Integer> st = new ArrayDeque<>();
		st.push(root);
		p[root] = root;
		while (!st.isEmpty()) {
			int e = st.peek();

			if (used[e]) {
				vl.add(e);
				st.pop();
			} else {
				for (int next : edges.get(e)) {
					if (used[next]) {
						continue;
					}

					st.push(next);
					p[next] = e;
				}
				used[e] = true;
			}
		}

		for (int v : vl) {
			long sum = 0;
			long max = 0;
			for (int e : edges.get(v)) {
				if (e == p[v]) {
					continue;
				}

				sum += a[e];
				max = Math.max(max, a[e]);
			}

			long pair = Math.min(sum / 2, sum - max);
			long tmp = sum - pair * 2;

			if (p[v] == v) {
				if (edges.get(v).size() == 1 && sum == a[v]) {
					pr.println("YES");
				} else if (tmp != 0 || pair != a[v]) {
					pr.println("NO");
				} else {
					pr.println("YES");
				}
			} else if (edges.get(v).size() == 1){
			} else {
				if (a[v] > sum || a[v] < tmp + pair) {
					pr.println("NO");
					return;
				}

				a[v] -= sum - a[v];
			}
		}
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