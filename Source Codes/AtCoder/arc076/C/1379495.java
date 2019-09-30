import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int r = sc.nextInt();
		int c = sc.nextInt();
		int n = sc.nextInt();

		int[] x1 = new int[n];
		int[] y1 = new int[n];
		int[] x2 = new int[n];
		int[] y2 = new int[n];
		List<Pair> xy = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			x1[i] = sc.nextInt();
			y1[i] = sc.nextInt();
			x2[i] = sc.nextInt();
			y2[i] = sc.nextInt();

			if ((x1[i] == 0 || x1[i] == r || y1[i] == 0 || y1[i] == c)
					&& (x2[i] == 0 || x2[i] == r || y2[i] == 0 || y2[i] == c)) {
				int tmp1 = conv(x1[i], y1[i], r, c);
				int tmp2 = conv(x2[i], y2[i], r, c);
				if (tmp1 < tmp2) {
					xy.add(new Pair(tmp1, tmp2));
				} else {
					xy.add(new Pair(tmp2, tmp1));
				}
			}
		}
		Collections.sort(xy);

		Deque<Pair> st = new ArrayDeque<>();
		for (Pair e : xy) {
			while (!st.isEmpty() && st.peek().b < e.a) {
				st.pop();
			}

			if (!st.isEmpty() && st.peek().b < e.b) {
				pr.println("NO");
				return;
			}
			st.push(e);
		}

		pr.println("YES");
	}

	private static int conv(int x, int y, int r, int c) {
		if (y == 0) {
			return x;
		} else if (y == c) {
			return r + c + r - x;
		} else if (x == r) {
			return r + y;
		} else {
			return 2 * r + 2 * c - y;
		}
	}

	private static class Pair implements Comparable<Pair> {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Pair o) {
			if (a == o.a) {
				return Integer.compare(b, o.b);
			}

			return Integer.compare(a, o.a);
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
			stmp.append(']');

			return stmp.toString();
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