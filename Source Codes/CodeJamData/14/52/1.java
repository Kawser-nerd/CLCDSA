import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int MAX = 1011;
		int P = iread(), Q = iread(), N = iread();
		int[] H = new int[N];
		int[] G = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = iread();
			G[i] = iread();
		}

		int[] diana = new int[N], tower = new int[N];
		for (int i = 0; i < N; i++) {
			int x = H[i] % Q;
			if (x == 0)
				x = Q;
			diana[i] = (x + P - 1) / P;
			tower[i] = (H[i] + Q - 1) / Q;
		}

		int[][] d = new int[2][MAX];
		Arrays.fill(d[0], -1);
		d[0][1] = 0;
		int step = 0;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			Arrays.fill(d[step ^ 1], -1);
			for (int j = 0; j < MAX; j++) {
				int t = d[step][j];
				if (t == -1)
					continue;
				{
					int j1 = j + tower[i];
					d[step ^ 1][j1] = Math.max(d[step ^ 1][j1], t);
				}
				if (diana[i] < tower[i] + j) {
					int j1 = tower[i] + j - diana[i] - 1;
					d[step ^ 1][j1] = Math.max(d[step ^ 1][j1], t + G[i]);
					ans = Math.max(ans, t + G[i]);
				}
			}
			step ^= 1;
		}
		out.write(ans + "");
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