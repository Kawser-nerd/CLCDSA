import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int n = iread(), m = iread();
		int[] code = new int[n];
		boolean[][] mat = new boolean[n][n];
		for (int i = 0; i < n; i++)
			code[i] = iread();
		for (int i = 0; i < m; i++) {
			int x = iread(), y = iread();
			x--;
			y--;
			mat[x][y] = mat[y][x] = true;
		}
		StringBuilder sb = new StringBuilder();
		String ans = null;
		int INF = 100000;
		for (int start = 0; start < n; start++) {
			sb.setLength(0);
			sb.append(code[start] + "");

			int[] cities = new int[n];
			int len = 1;
			int cc = 1;
			cities[0] = start;
			boolean[] was = new boolean[n];
			was[start] = true;
			while (cc < n) {
				int bestS = -1, bestY = -1, bestCode = INF;
				for (int stack = len - 1; stack >= 0; stack--) {
					for (int i = 0; i < n; i++)
						if (!was[i] && mat[cities[stack]][i]) {
							if (bestCode > code[i]) {
								bestS = stack;
								bestY = i;
								bestCode = code[i];
							}
						}
					int[] queue = new int[n];
					boolean[] test = new boolean[n];
					int qlen = 0;
					for (int i = 0; i < stack; i++) {
						queue[qlen++] = cities[i];
						test[cities[i]] = true;
					}
					int ccc = cc;
					for (int qcur = 0; qcur < qlen; qcur++) {
						int x = queue[qcur];
						for (int i = 0; i < n; i++)
							if (mat[x][i] && !was[i] && !test[i]) {
								test[i] = true;
								queue[qlen++] = i;
								ccc++;
							}
					}
					if (ccc < n)
						break;
				}
				len = bestS + 1;
				cities[len++] = bestY;
				was[bestY] = true;
				sb.append(code[bestY] + "");
				cc++;
			}

			String s = sb.toString();
			if (ans == null || s.compareTo(ans) < 0) {
				ans = s;
			}
		}
		out.write(ans + "");
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			// try {
			solve();
			// } catch (Throwable e) {
			// System.out.println("Exception on test" + test);
			// }
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