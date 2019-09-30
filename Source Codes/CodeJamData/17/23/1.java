import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
//	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
//	 final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread(), Q = iread();

		int[] E = new int[N], S = new int[N];
		for (int i = 0; i < N; i++) {
			E[i] = iread();
			S[i] = iread();
		}

		int[][] D = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				D[i][j] = iread();
			}
		}

		long INF = 1000000000000L;

		long[][] km = new long[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				km[i][j] = D[i][j] == -1 ? INF : D[i][j];
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (km[j][k] > km[j][i] + km[i][k]) {
						km[j][k] = km[j][i] + km[i][k];
					}
		double[][] time = new double[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				time[i][j] = (km[i][j] <= E[i]) ? (km[i][j] * 1.0 / S[i]) : INF;
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (time[j][k] > time[j][i] + time[i][k]) {
						time[j][k] = time[j][i] + time[i][k];
					}

		for (int i = 0; i < Q; i++) {
			int X = iread(), Y = iread();
			X--;
			Y--;
			out.write(" " + df.format(time[X][Y]));
		}
	}

	DecimalFormat df = new DecimalFormat("0.00000000");

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ":");
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