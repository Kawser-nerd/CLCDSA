import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread(), M = iread();
		String[] s = new String[N];
		for (int i = 0; i < N; i++)
			s[i] = readword();
		int[][][] field = new int[4][N][M];
		for (int i = 1; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (field[0][i - 1][j] == 1 || s[i - 1].charAt(j) != '.')
					field[0][i][j] = 1;
			}
		for (int i = N - 2; i >= 0; i--)
			for (int j = 0; j < M; j++) {
				if (field[1][i + 1][j] == 1 || s[i + 1].charAt(j) != '.')
					field[1][i][j] = 1;
			}
		for (int i = 0; i < N; i++)
			for (int j = 1; j < M; j++) {
				if (field[2][i][j - 1] == 1 || s[i].charAt(j - 1) != '.')
					field[2][i][j] = 1;
			}
		for (int i = 0; i < N; i++)
			for (int j = M - 2; j >= 0; j--) {
				if (field[3][i][j + 1] == 1 || s[i].charAt(j + 1) != '.')
					field[3][i][j] = 1;
			}
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (s[i].charAt(j) != '.') {
					if (field[0][i][j] + field[1][i][j] + field[2][i][j]
							+ field[3][i][j] == 0) {
						out.write("IMPOSSIBLE");
						return;
					}
					if (s[i].charAt(j) == '^' && field[0][i][j] == 0)
						ans++;
					if (s[i].charAt(j) == 'v' && field[1][i][j] == 0)
						ans++;
					if (s[i].charAt(j) == '<' && field[2][i][j] == 0)
						ans++;
					if (s[i].charAt(j) == '>' && field[3][i][j] == 0)
						ans++;
				}
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