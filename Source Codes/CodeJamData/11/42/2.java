import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
//	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
//	 final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int R = iread(), C = iread(), D = iread();
		int[][][] intMatrix = new int[3][R + 1][C + 1];
		int[][][] w = new int[3][R][C];
		for (int i = 0; i < R; i++) {
			String s = readword();
			for (int j = 0; j < C; j++) {
				w[0][i][j] = s.charAt(j) - '0';
				w[1][i][j] = w[0][i][j] * i;
				w[2][i][j] = w[0][i][j] * j;
			}
		}
		for (int t = 0; t < 3; t++) {
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					int ww = w[t][i - 1][j - 1];
					intMatrix[t][i][j] = -intMatrix[t][i - 1][j - 1]
							+ intMatrix[t][i - 1][j] + intMatrix[t][i][j - 1]
							+ ww;
				}
			}
		}
		int ans = 0;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				for (int k = 3; i + k <= R && j + k <= C; k++) {
					int[] m = new int[3];
					for (int t = 0; t < 3; t++) {
						m[t] = intMatrix[t][i + k][j + k]
								- intMatrix[t][i + k][j]
								- intMatrix[t][i][j + k] + intMatrix[t][i][j];
						m[t] -= w[t][i][j] + w[t][i + k - 1][j + k - 1]
								+ w[t][i + k - 1][j] + w[t][i][j + k - 1];
					}
					if ((2 * i + k-1) * m[0] == 2 * m[1]
							&& (2 * j + k-1) * m[0] == 2 * m[2])
						ans = Math.max(ans, k);
				}
			}
		if (ans == 0)
			out.write("IMPOSSIBLE");
		else
			out.write(ans + "");
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
			System.out.println("TEST "+test+" DONE");
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