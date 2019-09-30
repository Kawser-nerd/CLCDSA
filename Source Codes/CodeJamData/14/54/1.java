import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
	// final String filename = problem + "-sample";

	final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		N = iread();
		C = new int[N];
		for (int i = 0; i < N; i++)
			C[i] = iread();
		first = new Edge[N];
		for (int i = 0; i + 1 < N; i++) {
			int x = i;
			int y = iread();
			y--;
			new Edge(x, y);
			new Edge(y, x);
		}

		int ans = -INF;
		was = new int[N];
		mark = new int[N][N];
		for (int x = 0; x < N; x++) {
			int res = INF;
			for (int y = 0; y < N; y++) {
				res = Math.min(res, best(x, y, false));
			}
			ans = Math.max(ans, res);
		}
		out.write(ans + "");
	}

	int INF = 1000000000;

	public int best(int x, int y, boolean stuck) {
		was[x]++;
		int ans = INF;
		for (Edge e = first[x]; e != null; e = e.next) {
			if (mark[e.from][e.to] == 0) {
				mark[e.from][e.to]++;
				mark[e.to][e.from]++;
				ans = Math.min(ans, best(y, e.to, false));
				mark[e.from][e.to]--;
				mark[e.to][e.from]--;
			}
		}
		if (ans == INF) {
			if (stuck)
				ans = 0;
			else
				ans = best(y, x, true);
		}
		was[x]--;
		ans = -ans;
		if (was[x] == 0)
			ans += C[x];
		return ans;
	}

	Edge[] first;
	int N;
	int[] C;
	int[][] mark;
	int[] was;

	class Edge {
		int from, to;
		Edge next;

		public Edge(int from, int to) {
			super();
			this.from = from;
			this.to = to;
			next = first[from];
			first[from] = this;
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