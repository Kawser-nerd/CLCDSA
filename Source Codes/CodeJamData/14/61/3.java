import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
//	final String filename = problem + "-sample";

//	 final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread();
		N *= 2;
		int[][] a = new int[N][N];
		int[] row = new int[N], col = new int[N];
		for (int i = 0; i < N; i++) {
			String s = readword();
			for (int j = 0; j < N; j++)
				a[i][j] = s.charAt(j) - '0';
		}
		row[0] = 1;
		int col1 = -1;
		for (int i = 0; i < N; i++) {
			if (a[0][i] == 1) {
				col1 = i;
				col[i] = 1;
			}
		}
		if (col1 == -1) {
			out.write("IMPOSSIBLE");
			return;
		}
		for (int i = 0; i < N; i++) {
			if (a[i][col1] == 1) {
				row[i] = 1;
			}
		}
		int c = 0;
		for (int i = 0; i < N; i++)
			if (row[i] == 1)
				c++;
		if (c != N / 2) {
			out.write("IMPOSSIBLE");
			return;
		}
		for (int i = 0; i < N; i++)
			if (col[i] == 1)
				c--;
		if (c != 0) {
			out.write("IMPOSSIBLE");
			return;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if ((a[i][j] ^ row[i] ^ col[j]) != 1) {
					out.write("IMPOSSIBLE");
					return;
				}
			}
		int ans = 0;
		int odd1 = 0;
		for (int i = 0; i < N; i += 2)
			if (row[i] == 0)
				odd1++;
		ans += Math.min(odd1, N / 2 - odd1);
		odd1 = 0;
		for (int i = 0; i < N; i += 2)
			if (col[i] == 0)
				odd1++;
		ans += Math.min(odd1, N / 2 - odd1);
		out.write(ans + "");
		// out.write(df.format(res));
	}

	DecimalFormat df = new DecimalFormat("0.0000000000");

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