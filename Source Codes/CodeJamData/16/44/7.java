import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread();
		int[][] g = new int[2 * N][2 * N];
		for (int i = 0; i < N; i++) {
			String s = readword();
			for (int j = 0; j < N; j++) {
				g[i][j + N] = s.charAt(j) - '0';
				g[j + N][i] = g[i][j + N];
			}
		}

		int[] groups = new int[N], gcost = new int[N];
		int gn = 0;

		int type01 = 0, type10 = 0, type11 = 0;

		int[] was = new int[2 * N];

		int[] q = new int[2 * N];
		for (int i = 0; i < 2 * N; i++) {
			int qlen = 0;
			if (was[i] != 0)
				continue;
			int edges = 0;
			q[qlen++] = i;
			was[i] = 1;
			int t0 = 0, t1 = 0;
			if (i < N)
				t0++;
			else
				t1++;
			for (int qcur = 0; qcur < qlen; qcur++) {
				int t = q[qcur];
				for (int u = 0; u < 2 * N; u++) {
					if (g[t][u] > 0) {
						edges++;
						if (was[u] == 0) {
							q[qlen++] = u;
							was[u] = 1;
							if (u < N) {
								t0++;
							} else
								t1++;
						}
					}
				}
			}
			if (t0 == 0 && t1 == 1) {
				type01++;
			} else if (t0 == 1 && t1 == 0) {
				type10++;
			} else if (t0 == 1 && t1 == 1) {
				type11++;
			} else {
				gcost[gn] = t0 * t1 - edges / 2;
				groups[gn++] = t0 * 100 + t1;
			}
		}
		int MAXCOST = 10000;
		int[][][][] cost = new int[type01 + 1][type10 + 1][type11 + 1][1 << gn];
		for (int a = 0; a <= type01; a++) {
			for (int b = 0; b <= type10; b++) {
				for (int c = 0; c <= type11; c++) {
					for (int mask = 0; mask < 1 << gn; mask++) {
						int t0 = b + c;
						int t1 = a + c;
						int edges = c;
						int cc = 0;

						for (int i = 0; i < gn; i++) {
							if (((1 << i) & mask) != 0) {
								int u = groups[i] / 100;
								int v = groups[i] % 100;
								t0 += u;
								t1 += v;
								edges += u * v;
								cc += gcost[i];
							}
						}
						cost[a][b][c][mask] = MAXCOST;
						if (t0 != t1) {
							continue;
						}
						int res = t0 * t1 - edges + cc;

						for (int a1 = 0; a1 <= a; a1++) {
							for (int b1 = 0; b1 <= b; b1++) {
								for (int c1 = 0; c1 <= c; c1++) {
									int m1 = cost[a1][b1][c1][0];
									int m2 = cost[a - a1][b - b1][c - c1][mask];
									res = Math.min(res, m1 + m2);

									for (int mask2 = mask; mask2 > 0; mask2 = (mask2 - 1)
											& mask) {
										m1 = cost[a1][b1][c1][mask2];
										m2 = cost[a - a1][b - b1][c - c1][mask
												^ mask2];
										res = Math.min(res, m1 + m2);
									}
								}
							}
						}
						cost[a][b][c][mask] = res;
					}
				}
			}
		}
		int ans = cost[type01][type10][type11][(1 << gn) - 1];
		out.write(ans + "");
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}