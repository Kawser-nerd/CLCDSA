import java.io.*;
import java.util.*;
import java.math.*;

public class ABig {
	public static void main(String[] args) throws Throwable {
		new ABig().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(1897450987159L);

	private void run() throws Throwable {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
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

	String FNAME = "a";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int[][] a = new int[2 * n - 1][2 * n - 1];
			for (int i = 0; i < a.length; i++) {
				Arrays.fill(a[i], -1);
			}
			for (int i = 0; i < a.length; i++) {
				int k = i + 1;
				if (i >= n) {
					k = 2 * n - i - 1;
				}
				for (int j = 0; j < k; j++) {
					if (i < n) {
						a[i][2 * j + n - i - 1] = nextInt();
					} else {
						a[i][2 * j + i - n + 1] = nextInt();
					}
				}
			}
			int ans = Integer.MAX_VALUE;
			for (int x = 0; x < a.length; x++) {
				for (int y = 0; y < a[x].length; y++) {
					boolean good = true;
					for (int i = 0; i < a.length; i++) {
						for (int j = 0; j < a[i].length; j++) {
							if (a[i][j] >= 0) {
								int ii = 2 * x - i;
								int jj = 2 * y - j;
								if (ii < 0 || ii >= a.length) {
								} else {
									good &= a[i][j] == a[ii][j] || a[ii][j] < 0;
								}
								if (jj < 0 || jj >= a[i].length) {
								} else {
									good &= a[i][j] == a[i][jj] || a[i][jj] < 0;
								}

							}
						}
					}
					if (good) {
						int f = 0;
						for (int i = 0; i < a.length; i++) {
							for (int j = 0; j < a[i].length; j++) {
								if (a[i][j] >= 0) {
									f = Math.max(f, Math.abs(i - x)
											+ Math.abs(j - y) + 1);
								}
							}
						}
						f = 2 * f - 1;
						int ff = (f / 2 + 1) * (f / 2 + 1) - ((2 * n + 1) / 2)
								* ((2 * n + 1) / 2);
						ans = Math.min(ans, ff);
					}
				}
			}
			out.println(ans);
			// System.out.println();
			// for (int x = 0; x < a.length; x++) {
			// for (int y = 0; y < a[x].length; y++) {
			// System.out.print(a[x][y] >= 0 ? "" + a[x][y] : " ");
			// }
			// System.out.println();
			// }
			// System.out.println(((2 * n + 1) / 2) * ((2 * n + 1) / 2));
		}
	}
}
