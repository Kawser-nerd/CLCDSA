import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
//	final String filename = problem + "-sample";
//	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	boolean[][] walls;
	int[][] next;
	int[] color;

	int n;

	boolean outer(int a, int b) {
		return a == (b + 1) % n;
	}

	public void solve() throws Exception {
		n = iread();
		int m = iread();
		walls = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			walls[i][(i + 1) % n] = true;
			walls[(i + 1) % n][i] = true;
		}
		int[] u = new int[m];
		int[] v = new int[m];
		for (int i = 0; i < m; i++)
			u[i] = iread();
		for (int i = 0; i < m; i++)
			v[i] = iread();
		for (int i = 0; i < m; i++) {
			int a = u[i] - 1, b = v[i] - 1;
			walls[a][b] = true;
			walls[b][a] = true;
		}
		next = new int[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!walls[i][j])
					continue;
				next[i][j] = -1;
				for (int k = j + n - 1; k >=0; k--) {
					if (walls[i][k % n]) {
						next[i][j] = k % n;
						break;
					}
				}
			}
		boolean[][] was = new boolean[n][n];
		int cnt = n + 1;
		int a1 = -1, b1 = -1;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (outer(a, b))
					continue;
				if (!walls[a][b])
					continue;
				if (was[a][b])
					continue;
				int x = 1;
				int i = a, j = b;
				was[a][b] = true;
//				System.out.print(i);
				while (j != a) {
//					System.out.print(" "+j);
					int k = next[j][i];
					i = j;
					j = k;
					was[i][j] = true;
					x++;
				}
				if (cnt > x) {
					cnt = x;
					a1 = a;
					b1 = b;
				}
//				System.out.println();
			}
		}
		for (int i = 0; i < n; i++)
			Arrays.fill(was[i], false);
		color = new int[n];
		int[] qa = new int[2 * n], qb = new int[2 * n];
		m = 0;
		qa[m] = a1;
		qb[m] = b1;
		color[a1] = 0;
		color[b1] = 1;
		m++;
		for (int s = 0; s < m; s++) {
			int a = qa[s], b = qb[s];
			int clr1 = color[a], clr2 = color[b];
			int i = a, j = b;
			was[a][b] = true;
			if (!outer(b, a) && !was[b][a]) {
				was[b][a] = true;
				qa[m] = b;
				qb[m] = a;
				m++;
			}

			int clr = clr2;
			while (j != a) {
				color[j] = clr;
				clr = (clr + 1) % cnt;
				if (clr == clr1)
					clr = (clr + 1) % cnt;

				int k = next[j][i];
				i = j;
				j = k;
				was[i][j] = true;
				if (!outer(j, i) && !was[j][i]) {
					was[j][i] = true;
					qa[m] = j;
					qb[m] = i;
					m++;
				}
			}
		}
		out.write(cnt + "\n");
		for (int i = 0; i < n; i++) {
			out.write((color[i] + 1) + "");
			if (i == n - 1)
				out.write("\n");
			else
				out.write(" ");
		}
		
//		for (int i = 0; i < n; i++)
//			Arrays.fill(was[i], false);
//		for (int a = 0; a < n; a++) {
//			for (int b = 0; b < n; b++) {
//				if (outer(a, b))
//					continue;
//				if (!walls[a][b])
//					continue;
//				if (was[a][b])
//					continue;
//				int x = 1;
//				int i = a, j = b;
//				was[a][b] = true;
//				System.out.print(color[i]);
//				while (j != a) {
//					System.out.print(" "+color[j]);
//					int k = next[j][i];
//					i = j;
//					j = k;
//					was[i][j] = true;
//					x++;
//				}
//				System.out.println();
//			}
//		}
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			System.out.println(test);
			out.write("Case #" + test + ": ");
			solve();
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