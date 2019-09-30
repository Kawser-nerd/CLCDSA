import java.io.*;
import java.util.*;
import java.math.*;

public class Cards implements Runnable {

	public static void main(String[] args) {
		new Thread(new Cards()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "cards";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int c = nextInt();
			int n = nextInt();
			double[][] cnk = new double[c + 1][c + 1];
			for (int i = 0; i < cnk.length; i++) {
				cnk[i][0] = 1;
				cnk[i][i] = 1;
			}
			for (int i = 1; i < cnk.length; i++) {
				for (int j = 1; j < i; j++) {
					cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
				}
			}
			// for (int i = 0; i < cnk.length; i++) {
			// System.out.println(Arrays.toString(cnk[i]));
			// }
			// System.out.println();
			double[][] b = new double[c + 1][n + 1];
			for (int i = 0; i < b.length; i++) {
				for (int j = 0; j < b[i].length; j++) {
					b[i][j] = cnk[i][n - j] * cnk[c - i][j] / cnk[c][n];
				}
			}
			// for (int i = 0; i < cnk.length; i++) {
			// System.out.println(Arrays.toString(b[i]));
			// }
			// System.out.println();
			// double[][] d = new double[c + 1][c + 1];
			// for (int i = 0; i < d.length; i++) {
			// double sum = 0;
			// for (int j = 0; j < d[i].length; j++) {
			// if (j <= n) {
			// d[i][j] = (cnk[i][j] * cnk[c - i][n - j] / cnk[c][n]);
			// sum += d[i][j];
			// }
			// }
			// System.out.println(sum);
			// sum -= d[i][0];
			// for (int j = 0; j < d.length; j++) {
			// d[i][j] /= sum;
			// }
			// }
			double[] a = new double[c + 1];
			a[c] = 0;
			for (int i = c - 1; i >= 0; i--) {
				// a[i] = 1 / ((1 - b[i][0]) * (1 - b[i][0]));
				for (int j = 1; j <= Math.min(n, c - i); j++) {
					a[i] += (b[i][j])
							* ((a[i + j] + (1 / (1 - b[i][0]))) / (1 - b[i][0]));
				}
			}
			// System.out.println(Arrays.toString(a));
			// System.out.println();
			out.println(a[0]);
		}
	}
}
