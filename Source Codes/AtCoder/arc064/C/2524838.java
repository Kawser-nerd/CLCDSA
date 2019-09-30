import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = false;
	static final double INF = 1e18;

	static void solve() {
		int[] sp = ir.nextIntArray(2);
		int[] gp = ir.nextIntArray(2);
		int n = ir.nextInt();
		int[][] c = new int[n][];
		for (int i = 0; i < n; i++)
			c[i] = ir.nextIntArray(3);
		Graph[] g = new Graph[n + 2];
		for (int i = 0; i < n + 2; i++)
			g[i] = new Graph();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				g[i].add(new double[] { j,
						Math.max(0.0, dist(c[i][0], c[i][1], c[j][0], c[j][1]) - c[i][2] - c[j][2]) });
				g[j].add(new double[] { i,
						Math.max(0.0, dist(c[i][0], c[i][1], c[j][0], c[j][1]) - c[i][2] - c[j][2]) });
			}
		}
		for (int i = 0; i < n; i++) {
			g[i].add(new double[] { n, Math.max(0.0, dist(c[i][0], c[i][1], sp[0], sp[1]) - c[i][2]) });
			g[n].add(new double[] { i, Math.max(0.0, dist(c[i][0], c[i][1], sp[0], sp[1]) - c[i][2]) });
			g[i].add(new double[] { n + 1, Math.max(0.0, dist(c[i][0], c[i][1], gp[0], gp[1]) - c[i][2]) });
			g[n + 1].add(new double[] { i, Math.max(0.0, dist(c[i][0], c[i][1], gp[0], gp[1]) - c[i][2]) });
		}
		g[n].add(new double[] { n + 1, dist(sp[0], sp[1], gp[0], gp[1]) });
		g[n + 1].add(new double[] { n, dist(sp[0], sp[1], gp[0], gp[1]) });
		double[] d = dijkstra(n, g);
		DecimalFormat df = new DecimalFormat("0.0000000000");
		out.println(df.format(d[n + 1]));
	}

	static double dist(double a, double b, double c, double d) {
		return Math.sqrt((a - c) * (a - c) + (b - d) * (b - d));
	}

	static class Graph extends ArrayList<double[]> {
	}

	static double[] dijkstra(int s, Graph[] g) {
		double[] ret = new double[g.length];
		Arrays.fill(ret, INF);
		PriorityQueue<double[]> pq = new PriorityQueue<double[]>(new Comparator<double[]>() {
			public int compare(double[] p, double[] q) {
				return Double.compare(p[0], q[0]);
			}
		});
		ret[s] = 0;
		pq.add(new double[] { 0.0, s });
		while (!pq.isEmpty()) {
			double[] p = pq.poll();
			int from = (int) p[1];
			if (ret[from] < p[0])
				continue;
			for (int i = 0; i < g[from].size(); i++) {
				double[] edge = g[from].get(i);
				if (ret[(int) edge[0]] > ret[from] + edge[1]) {
					ret[(int) edge[0]] = ret[from] + edge[1];
					pq.add(new double[] { ret[(int) edge[0]], edge[0] });
				}
			}
		}
		return ret;
	}

	public static void main(String[] args) throws Exception {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}

	static void tr(Object... o) {
		if (debug)
			out.println(Arrays.deepToString(o));
	}
}