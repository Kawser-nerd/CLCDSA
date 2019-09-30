import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}

		int l = sc.nextInt();

		int[][] db = new int[31][n];
		int[][] dbr = new int[31][n];
		for (int i = 0; i < n; i++) {
			int ll = i;
			int rr = n;
			while (rr - ll > 1) {
				int mid = ll + (rr - ll) / 2;
				if (x[mid] - x[i] <= l) {
					ll = mid;
				} else {
					rr = mid;
				}
			}

			db[0][i] = ll;
		}
		for (int i = 0; i < n; i++) {
			int ll = -1;
			int rr = i;
			while (rr - ll > 1) {
				int mid = ll + (rr - ll) / 2;
				if (x[i] - x[mid] <= l) {
					rr = mid;
				} else {
					ll = mid;
				}
			}

			dbr[0][i] = rr;
		}
		for (int j = 1; j < 31; j++) {
			for (int i = 0; i < n; i++) {
				db[j][i] = db[j - 1][db[j - 1][i]];
			}
			for (int i = n - 1; i >= 0; i--) {
				dbr[j][i] = dbr[j - 1][dbr[j - 1][i]];
			}
		}

		int q = sc.nextInt();

		int[] a = new int[q];
		int[] b = new int[q];
		for (int i = 0; i < q; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;

			if (a[i] > b[i]) {
				int tmp = a[i];
				a[i] = b[i];
				b[i] = tmp;
			}

			int cnt = 0;

			if (b[i] > a[i]) {
				int now = a[i];
				while (now < b[i]) {
					for (int j = 1; j < 31; j++) {
						if (db[j][now] >= b[i]) {
							cnt += 0x1 << (j - 1);
							now = db[j - 1][now];
							break;
						}
					}
				}
			} else {
				int now = a[i];
				while (now > b[i]) {
					for (int j = 1; j < 31; j++) {
						if (dbr[j][now] <= b[i]) {
							cnt += 0x1 << (j - 1);
							now = dbr[j - 1][now];
							break;
						}
					}
				}
			}

			pr.println(cnt);
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