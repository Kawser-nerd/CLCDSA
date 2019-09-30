import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		out.println();
		int n = nextInt();
		int[][] m = new int[n][n];
		int[] games = new int[n];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < n; j++) {
				if (s.charAt(j) == '.')
					continue;
				m[i][j] = s.charAt(j) == '1' ? 1 : -1;
			}
		}
		double[] wp = new double[n];
		for (int i = 0; i < n; i++) {
			int g = 0;
			int wins = 0;
			for (int j = 0; j < n; j++) {
				if (m[i][j] != 0)
					++g;
				if (m[i][j] == 1)
					++wins;
			}
			games[i] = g;
			wp[i] = (double) wins / g;
		}
		double[] owp = getOWP(m, wp, games);
		double[] oowp = getOOWP(m, owp);
		for (int i = 0; i < n; i++) {
			double cur = .25 * wp[i] + .5 * owp[i] + .25 * oowp[i];
			out.println(cur);
		}
	}

	double[] getOWP(int[][] m, double[] wp, int[] games) {
		int n = wp.length;
		double[] owp = new double[n];
		for (int i = 0; i < n; i++) {
			double s = 0;
			for (int j = 0; j < n; j++) {
				if (m[i][j] != 0) {
					double cur = wp[j] * games[j];
					if (m[i][j] < 0)
						cur -= 1;
					cur /= games[j] - 1;
					s += cur;
				}
			}
			owp[i] = s / games[i];
		}
		return owp;
	}

	double[] getOOWP(int[][] m, double[] owp) {
		int n = owp.length;
		double[] oowp = new double[n];
		for (int i = 0; i < n; i++) {
			double s = 0;
			int games = 0;
			for (int j = 0; j < n; j++) {
				if (m[i][j] != 0) {
					s += owp[j];
					++games;
				}
			}
			oowp[i] = s / games;
		}
		return oowp;
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "A-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}