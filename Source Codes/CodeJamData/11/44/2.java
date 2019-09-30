import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
	// final String filename = problem + "-sample";

//	final String filename = problem + "-small-attempt0";

//	 final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int P = iread(), W = iread();
		first = new Edge[P];
		int NP = (P + 31) / 32;
		int[][] masks = new int[P + 1][NP];
		for (int i = 0; i < W; i++) {
			String s = readword();
			String[] ss = s.split(",");
			int a = Integer.parseInt(ss[0]), b = Integer.parseInt(ss[1]);
			masks[a][b / 32] |= 1 << (b & 31);
			masks[b][a / 32] |= 1 << (a & 31);
			new Edge(a, b);
			new Edge(b, a);
		}
		for (int i = 0; i < P; i++)
			masks[i][i / 32] |= 1 << (i & 31);
		int[][] wave = new int[P + 1][P + 1];
		int[] wc = new int[P + 1];
		int[] d = new int[P];
		Arrays.fill(d, -1);
		wc[0] = 1;
		wave[0][0] = 0;
		d[0] = 0;
		for (int nw = 0; nw < P; nw++) {
			for (int i = 0; i < wc[nw]; i++) {
				int x = wave[nw][i];
				for (Edge e = first[x]; e != null; e = e.next) {
					int y = e.to;
					if (d[y] != -1)
						continue;
					d[y] = nw + 1;
					wave[nw + 1][wc[nw + 1]] = y;
					wc[nw + 1]++;
				}
			}
		}
		final int INF = -1;
		int[][] best = new int[P + 1][P + 1];
		for (int i = 0; i <= P; i++)
			Arrays.fill(best[i], INF);

		int b0 = 0;
		for (int k = 0; k < NP; k++) {
			int a = masks[0][k];
			int s = 1;
			while (s != 0) {
				if ((a & s) != 0)
					b0++;
				s <<= 1;
			}
		}

		best[0][P] = b0;
		int dw = d[1];
		int ans = INF;
		for (int nw = 0; nw < dw; nw++) {
			for (int i = 0; i < wc[nw]; i++) {
				int x = wave[nw][i];
				for (int y = 0; y <= P; y++) {
					int b = best[x][y];
					if (b == INF)
						continue;
					for (Edge e = first[x]; e != null; e = e.next) {
						int z = e.to;
						if (d[z] != d[x] + 1)
							continue;
						if (z == 1) {
							ans = Math.max(ans, b);
							continue;
						}
						int b1 = b;
						for (int k = 0; k < NP; k++) {
							int a = (masks[z][k] & (~masks[y][k]))
									& (~masks[x][k]);
							int s = 1;
							while (s != 0) {
								if ((a & s) != 0)
									b1++;
								s <<= 1;
							}
						}
						best[z][x] = Math.max(best[z][x], b1);
					}
				}
			}
		}
		out.write((dw - 1) + " " + (ans - dw));
	}

	Edge[] first;

	class Edge {
		int from, to;
		Edge next;

		public Edge(int x, int y) {
			from = x;
			to = y;
			next = first[x];
			first[x] = this;
		}
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