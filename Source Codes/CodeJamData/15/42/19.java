import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemB {

	public static void solve(FastScanner sc) {
		int N = sc.nextInt();
		double V = sc.nextDouble();
		double X = sc.nextDouble();
		double[] v = new double[N];
		double[] x = new double[N];
		for (int i = 0; i < N; i++) {
			v[i] = sc.nextDouble();
			x[i] = sc.nextDouble();
		}
		if (N == 1) {
			if (X == x[0]) {
				System.out.format(Locale.US, "%.08f\n", V / v[0]);
			} else {
				System.out.println("IMPOSSIBLE");
				return;
			}
		} else {
			if (X < x[0] && X < x[1]) {
				System.out.println("IMPOSSIBLE");
				return;
			}
			if (X > x[0] && X > x[1]) {
				System.out.println("IMPOSSIBLE");
				return;
			}
			if (x[0] == x[1]) {
				System.out.format(Locale.US, "%.08f\n", V / (v[0] + v[1]));
				return;
			}
			// solve equation
			double needed0 = (X * V - x[1] * V) / (x[0] - x[1]);
			double needed1 = (X * V - x[0] * V) / (x[1] - x[0]);
			double time0 = needed0 / v[0];
			double time1 = needed1 / v[1];
			System.out.format(Locale.US, "%.08f\n", Math.max(time0, time1));
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		 FastScanner sc = new FastScanner(new File("B-practice.in"));
//		FastScanner sc = new FastScanner(new File("B-small-attempt0.in"));
		// FastScanner sc = new FastScanner(new File("B-large.in"));
		// sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
	}

	static class FastScanner {
		BufferedReader br = null;
		StringTokenizer st = null;

		FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		FastScanner(File in) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(in));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
