import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
	// final String filename = problem + "-sample";

	// final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int n = iread();
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = readword();
		int m = 1;
		for (int i = 1; i < s[0].length(); i++)
			if (s[0].charAt(i) != s[0].charAt(i - 1))
				m++;
		int[][] x = new int[m][n];
		int[] d = new int[m];
		m = 1;
		d[0] = s[0].charAt(0);
		for (int i = 1; i < s[0].length(); i++)
			if (s[0].charAt(i) != s[0].charAt(i - 1))
				d[m++] = s[0].charAt(i);
		for (int i = 0; i < n; i++) {
			int pos = 0, c = 0;
			for (int j = 0; j < s[i].length(); j++) {
				if (s[i].charAt(j) == d[pos]) {
					c++;
				} else {
					if (c == 0) {
						out.write("Fegla Won");
						return;
					}
					x[pos][i] = c;
					pos++;
					c = 1;
					if (pos == m || d[pos] != s[i].charAt(j)) {
						out.write("Fegla Won");
						return;
					}
				}
			}
			if (pos != m - 1) {
				out.write("Fegla Won");
				return;
			}
			x[pos][i] = c;
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			Arrays.sort(x[i]);
			for (int j = 0; j < n / 2; j++)
				ans += x[i][n / 2] - x[i][j];
			for (int j = n / 2; j < n; j++)
				ans += -x[i][n / 2] + x[i][j];
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