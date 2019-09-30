import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static class Dist implements Comparable<Dist> {
		final double dist;
		final int id;

		Dist(double dist, int id) {
			this.dist = dist;
			this.id = id;
		}

		public int compareTo(Dist o) {
			return Double.compare(dist, o.dist);
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int s = nextInt();
		int pos[][] = new int[3][n];
		int speed[][] = new int[3][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				pos[j][i] = nextInt();
			}
			for (int j = 0; j < 3; j++) {
				speed[j][i] = nextInt();
			}
		}
		boolean seen[] = new boolean[n];
		PriorityQueue<Dist> dists = new PriorityQueue<>();
		dists.add(new Dist(0, 0));
		double ans = 0;
		while (true) {
			Dist cur = dists.remove();
			if (seen[cur.id]) {
				continue;
			}
			ans = max(ans, cur.dist);
			if (cur.id == 1) {
				printCase();
				out.printf(Locale.US, "%.9f\n", sqrt(ans));
				return;
			}
			seen[cur.id] = true;
			for (int i = 0; i < n; i++) {
				if (!seen[i]) {
					double d = 0;
					for (int j = 0; j < 3; j++) {
						double dpos = pos[j][cur.id] - pos[j][i];
						d += dpos * dpos;
					}
					dists.add(new Dist(d, i));
				}
			}
		}
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