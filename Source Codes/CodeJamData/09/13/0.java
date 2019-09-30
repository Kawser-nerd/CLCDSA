import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "C-large";

	public void solve() throws Exception {
		double ans = 0.0;

		double[][] C = new double[41][41];
		C[0][0] = 1.0;
		for (int i = 1; i <= 40; i++) {
			C[i][0] = 1.0;
			for (int j = 1; j <= i; j++)
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}

		int ntest = iread();
		for (int test = 1; test <= ntest; test++) {
			int cnt = iread(), N = iread();
			double[] d = new double[cnt + 1];
			for (int k = 1; k <= cnt; k++) {
				for (int j = 1; j <= Math.min(N, k); j++)
					d[k] += d[k - j]
							* (C[k][j] * C[cnt - k][N - j] / C[cnt][N]);
				double p = C[cnt - k][N] / C[cnt][N];
				d[k] += 1.0;
				d[k] /= 1.0 - p;
			}
			DecimalFormat df = new DecimalFormat("0.00000000");
			out.write("Case #" + test + ": " + df.format(d[cnt]) + "\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
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
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}