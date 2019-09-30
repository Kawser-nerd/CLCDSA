import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String filename = "A-large";

	public void solve() throws Exception {
		int T = iread();
		for (int t = 1; t <= T; t++) {
			out.write("Case #" + t + ": ");
			int n = iread(), K = iread() - 1;
			char[][] a = new char[n][n];
			for (int i = 0; i < n; i++)
				a[i] = readword().toCharArray();
			boolean p1 = false, p2 = false;
			for (int i = 0; i < n; i++) {
				int j = n - 1;
				for (int k = n - 1; k >= 0; k--) {
					if (a[i][k] != '.')
						a[i][j--] = a[i][k];
				}
				while (j >= 0)
					a[i][j--] = '.';
			}
			int[][] left = new int[n][n], top = new int[n][n], d1 = new int[n][n], d2 = new int[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					left[i][j] = (j == 0 || a[i][j] != a[i][j - 1]) ? 0
							: left[i][j - 1] + 1;
					top[i][j] = (i == 0 || a[i][j] != a[i - 1][j]) ? 0
							: top[i - 1][j] + 1;
					d1[i][j] = (j == 0 || i == 0 || a[i][j] != a[i - 1][j - 1]) ? 0
							: d1[i - 1][j - 1] + 1;
					d2[i][j] = (i == 0 || j == n - 1 || a[i][j] != a[i - 1][j + 1]) ? 0
							: d2[i - 1][j + 1] + 1;
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (a[i][j] == '.')
						continue;
					int m = 0;
					if (left[i][j] < K && top[i][j] < K && d1[i][j] < K
							&& d2[i][j] < K)
						continue;
					if (a[i][j] == 'R')
						p1 = true;
					if (a[i][j] == 'B')
						p2 = true;
				}
			if (p1 && p2)
				out.write("Both\n");
			if (!p1 && !p2)
				out.write("Neither\n");
			if (p1 && !p2)
				out.write("Red\n");
			if (!p1 && p2)
				out.write("Blue\n");
			out.flush();
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