import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "d";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			int[] ansn = new int[10];
			boolean[] ansc = new boolean[10];
			boolean[] was = new boolean[10];
			char[][] a = new char[n][];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextToken().toCharArray();
			}
			int[][] num = new int[n][m];
			int cnt = 0;
			for (int i = 0; i < num.length; i++) {
				Arrays.fill(num[i], -1);
			}
			for (int i = 0; i < num.length; i++) {
				for (int j = 0; j < num[i].length; j++) {
					if (a[i][j] != '#') {
						num[i][j] = cnt++;
					}
				}
			}
			int[] x = new int[cnt];
			int[] y = new int[cnt];
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] != '#') {
						x[num[i][j]] = i;
						y[num[i][j]] = j;
					}
				}
			}
			for (int px = 0; px < a.length; px++) {
				for (int py = 0; py < a[px].length; py++) {
					if ('0' <= a[px][py] && a[px][py] <= '9') {
						int c = a[px][py] - '0';
						if (c == 2) {
							c += 0;
						}
						was[c] = true;
						u = new boolean[n][m];
						long prof = reachable(a, px, py, num);
						ansn[c] = Long.bitCount(prof);
						set = new HashSet<Long>();
						ansc[c] = lucky(a, prof, num, prof, x, y);
					}
				}
			}
			out.println();
			for (int i = 0; i < was.length; i++) {
				if (was[i]) {
					out.println(i + ": " + ansn[i] + " "
							+ (ansc[i] ? "L" : "Unl") + "ucky");
				}
			}
		}
	}

	HashSet<Long> set;

	private boolean lucky(char[][] a, long prof, int[][] num, long good,
			int[] x, int[] y) {
		if ((good | prof) != good || set.contains(prof)) {
			return false;
		}
		set.add(prof);
		if (Long.bitCount(prof) == 1) {
			return true;
		}
		boolean res = false;
		if (!res) {
			long np = 0;
			for (int i = 0; i < 64; i++) {
				if (((1L << i) & prof) != 0) {
					int x0 = x[i];
					int y0 = y[i];
					if (x0 + 1 < a.length && a[x0 + 1][y0] != '#') {
						x0++;
					}
					np |= 1L << num[x0][y0];
				}
			}
			res |= lucky(a, np, num, good, x, y);
		}
		if (!res) {
			long np = 0;
			for (int i = 0; i < 64; i++) {
				if (((1L << i) & prof) != 0) {
					int x0 = x[i];
					int y0 = y[i];
					if (y0 + 1 < a[x0].length && a[x0][y0 + 1] != '#') {
						y0++;
					}
					np |= 1L << num[x0][y0];
				}
			}
			res |= lucky(a, np, num, good, x, y);
		}
		if (!res) {
			long np = 0;
			for (int i = 0; i < 64; i++) {
				if (((1L << i) & prof) != 0) {
					int x0 = x[i];
					int y0 = y[i];
					if (y0 > 0 && a[x0][y0 - 1] != '#') {
						y0--;
					}
					np |= 1L << num[x0][y0];
				}
			}
			res |= lucky(a, np, num, good, x, y);
		}
		return res;
	}

	boolean[][] u;

	private long reachable(char[][] a, int x, int y, int[][] num) {
		if (x < 0 || x > a.length || y < 0 || y >= a[x].length
				|| a[x][y] == '#' || u[x][y]) {
			return 0;
		}
		long res = 1L << num[x][y];
		u[x][y] = true;
		res |= reachable(a, x - 1, y, num);
		res |= reachable(a, x, y - 1, num);
		res |= reachable(a, x, y + 1, num);
		return res;
	}
}
