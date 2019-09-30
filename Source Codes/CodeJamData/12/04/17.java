import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "D-large";

	public void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int m = nextInt();
			int d = nextInt();
			char[][] f = new char[n][m];
			int x0 = -1, y0 = -1;
			for (int i = 0; i < n; ++i) {
				f[i] = next().toCharArray();
				for (int j = 0; j < m; ++j) {
					if (f[i][j] == 'X') {
						x0 = i;
						y0 = j;
					}
				}
			}
			int ans = 0;
			for (int dx = -d; dx <= d; ++dx) {
				for (int dy = -d; dy <= d; ++dy) {
					if ((dx != 0 || dy != 0) && dx * dx + dy * dy <= d * d && raytrace(x0, y0, x0 + dx, y0 + dy, f, 0.)) {
//						System.err.println(dx + " " + dy);
						ans++;
					}
				}
			}
			System.err.printf("Case #%d: %d%n", test + 1, ans);
			out.printf("Case #%d: %d%n", test + 1, ans);
		}
	}
	
	final double EPS = 1e-8;

	private boolean raytrace(int x0, int y0, int x1, int y1, char[][] f, double t) {
		double firstt = Double.POSITIVE_INFINITY;
		int dx = x1 - x0;
		int dy = y1 - y0;
		double tx = Double.POSITIVE_INFINITY;
		for (int i = Math.max(0, Math.min(x0, x1)); i < f.length && i <= Math.max(x0, x1); ++i) {
			for (int j = Math.max(0, Math.min(y0, y1)); j < f[0].length && j <= Math.max(y0, y1); ++j) {
				if (f[i][j] == 'X') {
					double tt = dx != 0 ? (double)(i - x0) / dx : (double)(j - y0) / dy;
					if (Math.abs(x0 + dx * tt - i) < EPS && Math.abs(y0 + dy * tt - j) < EPS) {
						tx = tt;
					}
				}
				if (f[i][j] != '#') {
					continue;
				}
				double minx = dx == 0 ? Double.NEGATIVE_INFINITY : Math.min((i - 0.5 - x0) / dx, (i + 0.5 - x0) / dx);
				double maxx = dx == 0 ? Double.POSITIVE_INFINITY : Math.max((i - 0.5 - x0) / dx, (i + 0.5 - x0) / dx);
				double miny = dy == 0 ? Double.NEGATIVE_INFINITY : Math.min((j - 0.5 - y0) / dy, (j + 0.5 - y0) / dy);
				double maxy = dy == 0 ? Double.POSITIVE_INFINITY : Math.max((j - 0.5 - y0) / dy, (j + 0.5 - y0) / dy);
				if (maxx < miny - EPS || maxy < minx - EPS) {
					continue;
				}
				double tt = Math.max(minx, miny);
				if (tt > t + EPS) {
					firstt = Math.min(firstt, tt);
				}
			}
		}
		if (firstt > 1.) {
			return x1 >= 0 && x1 < f.length && y1 >= 0 && y1 < f[0].length && f[x1][y1] == 'X';
		}
		if (tx > t + EPS && tx < firstt) {
			return false;
		}
		int sx = Integer.signum(dx);
		int sy = Integer.signum(dy);
		double x = x0 + dx * firstt - 0.5;
		double y = y0 + dy * firstt - 0.5;
		int rx = (int)Math.round(x);
		int ry = (int)Math.round(y);
		if (Math.abs(rx - x) < EPS && Math.abs(ry - y) < EPS) {
			if (dx == 0 || dy == 0) {
				throw new AssertionError();
			}
			boolean f11 = get(f, rx + (1 + sx) / 2, ry + (1 + sy) / 2);
			boolean f01 = get(f, rx + (1 - sx) / 2, ry + (1 + sy) / 2);
			boolean f10 = get(f, rx + (1 + sx) / 2, ry + (1 - sy) / 2);
			if (get(f, rx + (1 - sx) / 2, ry + (1 - sy) / 2) || !f11 && !f01 && !f10) {
				throw new AssertionError();
			}
			if (!f11) {
				return raytrace(x0, y0, x1, y1, f, firstt);
			}
			if (f01 && f10 && f11) {
				return raytrace(2 * rx + 1 - x0, 2 * ry + 1 - y0, 2 * rx + 1 - x1, 2 * ry + 1 - y1, f, firstt);
			}
			if (f10 && f11) {
				return raytrace(2 * rx + 1 - x0, y0, 2 * rx + 1 - x1, y1, f, firstt);
			}
			if (f01 && f11) {
				return raytrace(x0, 2 * ry + 1 - y0, x1, 2 * ry + 1 - y1, f, firstt);
			}
			return false;
		}
		if (Math.abs(rx - x) < EPS) {
			return raytrace(2 * rx + 1 - x0, y0, 2 * rx + 1 - x1, y1, f, firstt);
		}
		if (Math.abs(ry - y) < EPS) {
			return raytrace(x0, 2 * ry + 1 - y0, x1, 2 * ry + 1 - y1, f, firstt);
		}
		throw new AssertionError();
	}

	private boolean get(char[][] f, int i, int j) {
		return i >= 0 && i < f.length && j >= 0 && j < f[0].length && f[i][j] == '#';
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}