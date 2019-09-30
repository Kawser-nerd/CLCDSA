import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
//	static void print(String title, long x[], long y[]) {
//		System.err.print(title + ":");
//		for (int i = 0; i < x.length; i++) {
//			System.err.print(" (" + x[i] + " " + y[i] + ")");
//		}
//		System.err.println();
//	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		long x[] = new long[n];
		long y[] = new long[n];
		int minp = 0;
		for (int i = 0; i < n; i++) {
			long cx = nextLong();
			long cy = nextLong();
			x[i] = cx - cy;
			y[i] = cy + cx;
			if (x[i] < x[minp] || x[i] == x[minp] && y[i] < x[minp]) {
				minp = i;
			}
		}
//		print("Shifts", x, y);
		{
			long t = x[minp];
			x[minp] = x[0];
			x[0] = t;
			t = y[minp];
			y[minp] = y[0];
			y[0] = t;
		}
		Integer idx[] = new Integer[n - 1];
		for (int i = 0; i < n - 1; i++) {
			idx[i] = i + 1;
		}
		{
			final long ox[] = x, oy[] = y;
			sort(idx, new Comparator<Integer>() {

				public int compare(Integer o1, Integer o2) {
					long dx1 = ox[o1] - ox[0];
					long dy1 = oy[o1] - oy[0];
					long dx2 = ox[o2] - ox[0];
					long dy2 = oy[o2] - oy[0];
					long vmul = dy1 * dx2 - dx1 * dy2;
					if (vmul != 0) {
						return Long.signum(vmul);
					}
					if (dx1 != dx2) {
						return Long.signum(dx1 - dx2);
					}
					return Long.signum(dy1 - dy2);
				}
			});
		}
		List<Integer> hull = new ArrayList<Integer>();
		hull.add(0);
		for (int i: idx) {
			hull.add(i);
			while (hull.size() > 2) {
				int last = hull.get(hull.size() - 1);
				int prev = hull.get(hull.size() - 2);
				int pp = hull.get(hull.size() - 3);
				long dx1 = x[last] - x[prev];
				long dy1 = y[last] - y[prev];
				long dx2 = x[prev] - x[pp];
				long dy2 = y[prev] - y[pp];
				if (dy1 * dx2 <= dx1 * dy2) {
					hull.remove(hull.size() - 2);
				} else {
					break;
				}
			}
		}
		{
			n = hull.size();
			long nx[] = new long[n];
			long ny[] = new long[n];
			for (int i = 0; i < n; i++) {
				int p = hull.get(i);
				nx[i] = x[p];
				ny[i] = y[p];
			}
			x = nx;
			y = ny;
		}
//		print("Hull", x, y);
		long xx[][] = new long[4][];
		long yy[][] = new long[4][];
		xx[0] = x;
		yy[0] = y;
		for (int i = 0; i < 3; i++) {
			xx[i + 1] = new long[n];
			yy[i + 1] = new long[n];
			for (int j = 0; j < n; j++) {
				xx[i + 1][j] = -yy[i][j];
				yy[i + 1][j] = xx[i][j];
			}
		}
		int p[] = new int[4];
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < n; j++) {
				if (xx[i][j] < xx[i][p[i]] || xx[i][j] == xx[i][p[i]] && yy[i][j] < yy[i][p[i]]) {
					p[i] = j;
				}
			}
		}
		double ans = 0;
		for (int cm = m; cm > 0 && cm > m - 4; cm--) {
			int mul[] = {(cm + 3) / 4, (cm + 2) / 4, (cm + 1) / 4, cm / 4};
//			System.err.println("Scanning with m = " + cm + ", muls " + Arrays.toString(mul));
			long posX = 0, posY = 0;
			for (int i = 0; i < 4; i++) {
				posX += xx[i][p[i]] * mul[i];
				posY += yy[i][p[i]] * mul[i];
			}
//			System.err.println("Start pos (" + posX + ", " + posY + ")");
			int cp[] = p.clone();
			while (true) {
				ans = max(ans, (double) posX * posX + (double) posY * posY);
				int cpp = -1;
				long cpX = 0, cpY = 0;
				for (int i = 0; i < 4; i++) {
					if (cp[i] < 0) {
						continue;
					}
					long npX = xx[i][(cp[i] + 1) % n] - xx[i][cp[i]];
					long npY = yy[i][(cp[i] + 1) % n] - yy[i][cp[i]];
					if (cpp >= 0 && compareVect(cpX, cpY, npX, npY) < 0) {
						continue;
					}
					cpp = i;
					cpX = npX;
					cpY = npY;
				}
				if (cpp < 0) {
					break;
				}
				posX += mul[cpp] * (xx[cpp][(cp[cpp] + 1) % n] - xx[cpp][cp[cpp]]);
				posY += mul[cpp] * (yy[cpp][(cp[cpp] + 1) % n] - yy[cpp][cp[cpp]]);
//				System.err.println("Go " + cpp + " vec (" + (xx[cpp][(cp[cpp] + 1) % n] - xx[cpp][cp[cpp]]) + ", " + (yy[cpp][(cp[cpp] + 1) % n] - yy[cpp][cp[cpp]]) + ") pos (" + posX + ", " + posY + ")");
				cp[cpp] = (cp[cpp] + 1) % n;
				if (cp[cpp] == p[cpp]) {
					cp[cpp] = -1;
				}
			}
		}
//		System.err.println("Squared ans: " + ans);
		printCase();
		out.println(sqrt(ans));
	}
	
	static int type(long x, long y) {
		if (x > 0) {
			if (y > 0) {
				return 2;
			} else if (y < 0) {
				return 0;
			} else {
				return 1;
			}
		} else if (x < 0) {
			if (y > 0) {
				return 4;
			} else if (y < 0) {
				return 6;
			} else {
				return 5;
			}
		} else {
			if (y > 0) {
				return 3;
			} else if (y < 0) {
				return 7;
			} else {
				return -1;
			}
		}
	}
	
	static int compareVect(long x1, long y1, long x2, long y2) {
		int t1 = type(x1, y1);
		int t2 = type(x2, y2);
		if (t1 != t2) {
			return t1 - t2;
		}
		return Long.signum(y1 * x2 - x1 * y2);
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}