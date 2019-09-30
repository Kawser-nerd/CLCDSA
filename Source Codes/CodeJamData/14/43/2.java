import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Val implements Comparable<Val> {
		final int i, dist;

		Val(int i, int dist) {
			this.i = i;
			this.dist = dist;
		}
		
		public int compareTo(Val o) {
			return dist - o.dist;
		}
	}
	
	static int dist(int x0a, int x1a, int x0b, int x1b) {
		if (x1a < x0b) {
			return x0b - x1a;
		} else if (x1b < x0a) {
			return x0a - x1b;
		} else {
			return 0;
		}
	}
	
	static void solve() throws Exception {
		int w = nextInt();
		/*int h = */nextInt();
		int b = nextInt();
		int x0[] = new int[b];
		int y0[] = new int[b];
		int x1[] = new int[b];
		int y1[] = new int[b];
		for (int i = 0; i < b; i++) {
			x0[i] = nextInt();
			y0[i] = nextInt();
			x1[i] = nextInt() + 1;
			y1[i] = nextInt() + 1;
		}
		int dist[] = new int[b];
		PriorityQueue<Val> q = new PriorityQueue<>();
		for (int i = 0; i < b; i++) {
			dist[i] = x0[i];
			q.add(new Val(i, x0[i]));
		}
		while (!q.isEmpty()) {
			Val v = q.remove();
			int i = v.i;
			if (dist[i] != v.dist) {
				continue;
			}
			for (int j = 0; j < b; j++) {
				if (j == i) {
					continue;
				}
				int ndist = dist[i] + max(dist(x0[i], x1[i], x0[j], x1[j]), dist(y0[i], y1[i], y0[j], y1[j]));
				if (dist[j] > ndist) {
					dist[j] = ndist;
					q.add(new Val(j, ndist));
				}
			}
		}
		int ans = w;
		for (int i = 0; i < b; i++) {
			ans = min(ans, dist[i] + w - x1[i]);
		}
		printCase();
		out.println(ans);
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