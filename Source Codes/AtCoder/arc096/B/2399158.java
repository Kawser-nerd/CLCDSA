import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		final long INF = Long.MAX_VALUE / 2;

		int n = sc.nextInt();
		long c = sc.nextLong();

		long[] x = new long[n];
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextLong();
			v[i] = sc.nextInt();
		}

		long[] csum = new long[n + 1];
		long[] csummax = new long[n + 1];
		Arrays.fill(csummax, -INF);
		{
			long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += v[i];
				csum[i + 1] = sum - x[i];
				csummax[i + 1] = Math.max(csummax[i], csum[i + 1]);
			}
		}
		long[] rcsum = new long[n + 1];
		long[] rcsummax = new long[n + 1];
		Arrays.fill(rcsummax, -INF);
		{
			long sum = 0;
			for (int i = n - 1; i >= 0; i--) {
				sum += v[i];
				rcsum[i] = sum - (c - x[i]);
				rcsummax[i] = Math.max(rcsummax[i + 1], rcsum[i]);
			}
		}

		long max = 0;
		max = Math.max(max, csum[n]);
		max = Math.max(max, rcsum[0]);
		for (int i = 0; i < n - 1; i++) {
			long tmp = csum[i + 1] + Math.max(0, rcsummax[i + 1] - x[i]);
			max = Math.max(max, tmp);
		}
		for (int i = n - 1; i > 0; i--) {
			long tmp = rcsum[i] + Math.max(0, csummax[i] - (c - x[i]));
			max = Math.max(max, tmp);
		}

		pr.println(max);
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(INPUT == null ? System.in : new ByteArrayInputStream(INPUT.getBytes()));
		pr = new Printer(System.out);

		solve();

//		pr.close();
		pr.flush();
//		sc.close();
	}

	static String INPUT = null;

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
		Printer(OutputStream out) {
			super(out);
		}
	}
}