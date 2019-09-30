import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		INF = Integer.MAX_VALUE;

		n = sc.nextInt();

		p = new int[n];
		c = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = sc.nextInt() - 1;
			c[p[i]] = i;
		}

		rmqe = new RMQSegmentTree(n);
		rmqo = new RMQSegmentTree(n);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				rmqe.update(i, p[i]);
			} else {
				rmqo.update(i, p[i]);
			}
		}

		PriorityQueue<Tuple> pq = new PriorityQueue<>();
		pq.add(new Tuple(0, n));

		List<Integer> ans = new ArrayList<>(n);
		while (!pq.isEmpty()) {
			Tuple e = pq.remove();

			int oe = e.a;
			if (oe % 2 == 0) {
				int e2 = rmqo.query(c[e.min], e.b);
				if (e2 < n) {
					ans.add(e.min);
					ans.add(e2);
					rmqe.update(c[e.min], INF);
					rmqo.update(c[e2], INF);
					if (c[e.min] > e.a + 1) {
						pq.add(new Tuple(e.a, c[e.min]));
					}
					if (c[e2] > c[e.min] + 2) {
						pq.add(new Tuple(c[e.min] + 1, c[e2]));
					}
					if (e.b > c[e2] + 2) {
						pq.add(new Tuple(c[e2] + 1, e.b));
					}
				} else {
					pr.println("error even");
				}
			} else {
				int e2 = rmqe.query(c[e.min], e.b);
				if (e2 < n) {
					ans.add(e.min);
					ans.add(e2);
					rmqo.update(c[e.min], INF);
					rmqe.update(c[e2], INF);
					if (c[e.min] > e.a + 1) {
						pq.add(new Tuple(e.a, c[e.min]));
					}
					if (c[e2] > c[e.min] + 2) {
						pq.add(new Tuple(c[e.min] + 1, c[e2]));
					}
					if (e.b > c[e2] + 2) {
						pq.add(new Tuple(c[e2] + 1, e.b));
					}
				} else {
					pr.println("error even");
				}
			}
		}

		for (int i = 0, size = ans.size(); i < size; i++) {
			if (i > 0) {
				pr.print(' ');
			}
			pr.print(ans.get(i) + 1);
		}
		pr.println();
	}

	private static int n;
	private static int INF;
	private static int[] p;
	private static int[] c;
	private static RMQSegmentTree rmqe;
	private static RMQSegmentTree rmqo;

	private static class Tuple implements Comparable<Tuple> {
		int a;
		int b;
		int min;

		Tuple(int a, int b) {
			this.a = a;
			this.b = b;
			if (a % 2 == 0) {
				min = rmqe.query(a, b);
			} else {
				min = rmqo.query(a, b);
			}
		}

		@Override
		public int compareTo(Tuple o) {
			return Integer.compare(min, o.min);
		}

		@Override
		public int hashCode() {
			return Integer.hashCode(a);
		}

		@Override
		public String toString() {
			// [xxx, xxxx]
			StringBuilder stmp = new StringBuilder(32);
			stmp.append('[');
			stmp.append(a);
			stmp.append(',');
			stmp.append(' ');
			stmp.append(b);
			stmp.append(',');
			stmp.append(' ');
			stmp.append(min);
			stmp.append(']');

			return stmp.toString();
		}
	}

	private static class RMQSegmentTree {
		int[] st;
		int n;
		final int INF = Integer.MAX_VALUE;

		RMQSegmentTree(int n) {
			this.n = 1;
			while (this.n < n) {
				this.n *= 2;
			}
			st = new int[2 * this.n - 1];
			Arrays.fill(st, INF);
		}

		// i:0-indexed
		void update(int i, int x) {
			i = n - 1 + i;
			st[i] = x;
			while (i > 0) {
				i = (i - 1) / 2;
				st[i] = Math.min(st[2 * i + 1], st[2 * i + 2]);
			}
		}

		// a, b:0-indexed
		// [a, b)
		int query(int a, int b) {
			return query(a, b, 0, 0, n);
		}

		private int query(int a, int b, int i, int l, int r) {
			if (a >= r || b <= l) {
				return INF;
			}
			if (a <= l && b >= r) {
				return st[i];
			}

			return Math.min(query(a, b, i * 2 + 1, l, (l + r) / 2),
					query(a, b, i * 2 + 2, (l + r) / 2, r));
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