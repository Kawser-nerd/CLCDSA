import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

        List<Pair> xy = new ArrayList<>();
        for (int i = 0; i < n; i++) {
        	xy.add(new Pair(sc.nextInt(), sc.nextInt(), i));
        }
        Collections.sort(xy);

        List<Pair> ch = new ArrayList<>();

        for (int i = 0; i < xy.size(); i++) {
        	while (ch.size() > 1
        			&& (Geom.cross(ch.get(ch.size() - 1).a - ch.get(ch.size() - 2).a, ch.get(ch.size() - 1).b - ch.get(ch.size() - 2).b, xy.get(i).a - ch.get(ch.size() - 1).a, xy.get(i).b - ch.get(ch.size() - 1).b)) <= 0) {
        		ch.remove(ch.size() - 1);
        	}
        	ch.add(xy.get(i));
        }
        int t = ch.size();
        for (int i = xy.size() - 1; i >= 0; i--) {
        	while (ch.size() > t
        			&& (Geom.cross(ch.get(ch.size() - 1).a - ch.get(ch.size() - 2).a, ch.get(ch.size() - 1).b - ch.get(ch.size() - 2).b, xy.get(i).a - ch.get(ch.size() - 1).a, xy.get(i).b - ch.get(ch.size() - 1).b)) <= 0) {
        		ch.remove(ch.size() - 1);
        	}
        	ch.add(xy.get(i));
        }

        ch.remove(ch.size() - 1);

        List<Double> the = new ArrayList<>();
        for (int i = 0, size = ch.size(); i < size; i++) {
        	double x1 = ch.get(i).a;
        	double y1 = ch.get(i).b;
        	double x2 = ch.get((i + 1) % size).a;
        	double y2 = ch.get((i + 1) % size).b;

        	double tmp = Math.atan2(y2 - y1, x2 - x1);
//        	tmp -= Math.PI / 2;
//        	if (tmp < -Math.PI) {
//        		tmp += 2 * Math.PI;
//        	}

        	the.add(tmp);
        }

        /*
        double sum = 0;
        for (int i = 0, size = ch.size(); i < size; i++) {
        	double tmp = the.get((i + 1) % size) - the.get(i);
        	if (tmp < 0) {
        		tmp += 2 * Math.PI;
        	}

        	sum += tmp;
        }

        pr.println(sum);
        pr.println(sum / 2 / Math.PI);
        */

        double[] ans = new double[n];
        for (int i = 0, size = ch.size(); i < size; i++) {
        	double tmp = the.get((i + 1) % size) - the.get(i);
        	tmp += 2 * Math.PI;
        	tmp %= 2 * Math.PI;

        	ans[ch.get((i + 1) % size).c] = tmp;
        }

        for (int i = 0; i < n; i++) {
        	pr.printf("%.6f\n", ans[i] / 2 / Math.PI);
        }
    }

    private static class Pair implements Comparable<Pair> {
    	int a;
    	int b;
    	int c;

    	Pair(int a, int b, int c) {
    		this.a = a;
    		this.b = b;
    		this.c = c;
    	}

		@Override
		public int compareTo(Pair o) {
			if (this.a == o.a) {
				return Integer.compare(this.b, o.b);
			}

			return Integer.compare(this.a, o.a);
		}

		@Override
		public String toString() {
			return "[" + Integer.toString(a) + " " + Integer.toString(b) + "]";
		}
    }

	private static class Geom {
		static long cross(int xa, int ya, int xb, int yb) {
			return (long)xa * yb - (long)xb * ya;
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