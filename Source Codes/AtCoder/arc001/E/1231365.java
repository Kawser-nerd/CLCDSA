import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

		int start = sc.nextInt();
		int goal = sc.nextInt();

		Deque<Pair> str = new ArrayDeque<>();
		Deque<Pair> stl = new ArrayDeque<>();
		Pair cur = null;
		double ret = 0;
		for (int i = 0; i <= n; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();

			if (i == 0) {
				cur = new Pair(i, start);
				continue;
			} else if (i == n) {
				l = goal;
				r = goal;
			}

			Pair rr = new Pair(i, r);
			Pair ll = new Pair(i, l);

			while (stl.size() > 0) {
				Pair pl = stl.pop();
				Pair ppl;
				if (stl.size() > 0) {
					ppl = stl.peek();
				} else {
					ppl = cur;
				}

				if (cross(pl.b - ppl.b, pl.a - ppl.a, ll.b - pl.b, ll.a - pl.a) > 0) {
					stl.push(pl);
					break;
				}
			}
			stl.push(ll);

			while (str.size() > 0) {
				Pair pr = str.pop();
				Pair ppr;
				if (str.size() > 0) {
					ppr = str.peek();
				} else {
					ppr = cur;
				}

				if (cross(pr.b - ppr.b, pr.a - ppr.a, rr.b - pr.b, rr.a - pr.a) < 0) {
					str.push(pr);
					break;
				}
			}
			str.push(rr);

			while (str.size() > 0 && stl.size() > 0) {
				rr = str.peekLast();
				ll = stl.peekLast();

				if (cross(rr.b - cur.b, rr.a - cur.a, ll.b - cur.b, ll.a - cur.a) > 0) {
					break;
				}

				if (rr.a < ll.a) {
					ret += Math.hypot(rr.b - cur.b, rr.a - cur.a);
					cur = str.removeLast();
				} else {
					ret += Math.hypot(ll.b - cur.b, ll.a - cur.a);
					cur = stl.removeLast();
				}
			}

//			pr.println(i);
//			pr.println(str.toString());
//			pr.println(stl.toString());
//			pr.println(cur);
		}

		pr.printf("%.10f\n", ret);
	}

	private static long cross(long xa, long ya, long xb, long yb) {
		return xa * yb - xb * ya;
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
				Integer.compare(b, o.b);
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