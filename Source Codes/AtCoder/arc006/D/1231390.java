import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int h = sc.nextInt();
		int w = sc.nextInt();

		char[][] c = new char[h][];
		for (int i = 0; i < h; i++) {
			c[i] = sc.next().toCharArray();
		}

		int cnt = 0;
		int[][] abc = new int[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (c[i][j] == 'o' && abc[i][j] == 0) {
					bfs(i, j, c, abc, ++cnt);
				}
			}
		}

		int[] num = new int[cnt + 1];
		int[] min = new int[cnt + 1];
		Arrays.fill(min, Integer.MAX_VALUE);
		int[] max = new int[cnt + 1];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				num[abc[i][j]]++;
				min[abc[i][j]] = Math.min(min[abc[i][j]], i);
				max[abc[i][j]] = Math.max(max[abc[i][j]], i);
			}
		}

		int[] ret = new int[3];
		for (int i = 1; i <= cnt; i++) {
			int scale = (max[i] - min[i] + 1) / 5;
//			Assert.assertTrue(num[i] % (scale * scale) == 0);
			int tmp = num[i] / (scale * scale);

			if (tmp == 12) {
				ret[0]++;
			} else if (tmp == 16) {
				ret[1]++;
			} else if (tmp == 11) {
				ret[2]++;
			} else {
//				Assert.fail();
			}
		}

		pr.printf("%d %d %d\n", ret[0], ret[1], ret[2]);
	}

	private static void bfs(int i, int j, char[][] c, int[][] abc, int cnt) {
		int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
		int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

		int h = c.length;
		int w = c[0].length;

		Queue<Pair> q = new ArrayDeque<>();
		q.add(new Pair(i, j));
		abc[i][j] = cnt;
		while (!q.isEmpty()) {
			Pair e = q.remove();

			for (int k = 0, size = dx.length; k < size; k++) {
				int nx = e.b + dx[k];
				int ny = e.a + dy[k];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					continue;
				}

				if (c[ny][nx] == 'o' && abc[ny][nx] == 0) {
					q.add(new Pair(ny, nx));
					abc[ny][nx] = cnt;
				}
			}
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