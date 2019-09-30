import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String filename = "B-large";
	final int max = 1000000;
	int D, I, M, N;

	int dist(int x, int y) {
		if (x == 256 || y == 256)
			return 0;
		x = Math.abs(x - y);
		if (x == 0)
			return 0;
		if (M == 0)
			return max;
		return ((x - 1) / M) * I;
	}

	public void solve() throws Exception {
		int T = iread();
		for (int t = 1; t <= T; t++) {
			out.write("Case #" + t + ": ");
			D = iread();
			I = iread();
			M = iread();
			N = iread();
			int[] a = new int[N];
			for (int i = 0; i < N; i++)
				a[i] = iread();
			int[][] d = new int[N + 1][257];
			for (int i = 0; i <= N; i++)
				Arrays.fill(d[i], max);
			d[0][256] = 0;
			for (int i = 0; i < N; i++) {
				for (int prev = 0; prev <= 256; prev++) {
					d[i + 1][prev] = Math.min(d[i + 1][prev], d[i][prev] + D);
					for (int next = 0; next <= 255; next++)
						d[i + 1][next] = Math.min(d[i + 1][next], d[i][prev]
								+ dist(prev, next) + Math.abs(next - a[i]));
				}
			}
			int ans = d[N][256];
			for (int i = 0; i < 256; i++)
				ans = Math.min(ans, d[N][i]);
			out.write(ans + "\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve();
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