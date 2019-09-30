import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	int segDist(int l1, int r1, int l2, int r2) {
		if (l1 > l2) {
			int temp = l1;
			l1 = l2;
			l2 = temp;
			temp = r1;
			r1 = r2;
			r2 = temp;
		}
		if (l2 <= r1) {
			return 0;
		} else {
			return l2 - r1 - 1;
		}
	}
	
	public void solve() throws Exception {
		int T = sc.nextInt();
		for (int Case = 1; Case <= T; Case++) {
			int w = sc.nextInt(), h = sc.nextInt(), b = sc.nextInt();
			int[] x0 = new int[b], y0 = new int[b], x1 = new int[b], y1 = new int[b];
			for (int i = 0; i < b; i++) {
				x0[i] = sc.nextInt();
				y0[i] = sc.nextInt();
				x1[i] = sc.nextInt();
				y1[i] = sc.nextInt();
			}
			int n = b + 2;
			int[][] g = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(g[i], Integer.MAX_VALUE / 4);
				g[i][i] = 0;
			}
			g[0][n - 1] = g[n - 1][0] = w;
			for (int i = 0; i < b; i++) {
				g[0][i + 1] = g[i + 1][0] = x0[i];
				g[b + 1][i + 1] = g[i + 1][b + 1] = w - 1 - x1[i];
				for (int j = 0; j < b; j++) {
					g[i + 1][j + 1] = max(segDist(x0[i], x1[i], x0[j], x1[j]), segDist(y0[i], y1[i], y0[j], y1[j]));
				}
			}
			boolean[] used = new boolean[n];
			int[] dist = new int[n];
			/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					out.print(g[i][j] + " ");
				}
				out.println();
			}
			*/
			Arrays.fill(dist, Integer.MAX_VALUE / 4);
			dist[0] = 0;
			for (int i = 0; i < n; i++) {
				int minv = -1;
				for (int j = 0; j < n; j++) {
					if (!used[j] && (minv == -1 || dist[j] < dist[minv])) {
						minv = j;
					}
				}
				if (minv == -1) {
					throw new Exception();
				}
				used[minv] = true;
				for (int j = 0; j < n; j++) {
					dist[j] = min(dist[j], dist[minv] + g[minv][j]);
				}
			}
			out.printf(Locale.US, "Case #%d: %d\n", Case, dist[n - 1]);
		}
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter(new FileWriter("C-large.out"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}