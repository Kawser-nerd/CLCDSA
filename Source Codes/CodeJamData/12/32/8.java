import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	
	private static final double eps = 1e-239;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private double d;
	private double[] t;
	private double[] x;
	
	private double solve(double a) {
		double low = 0;
		double high = t[t.length - 1];
		while (true) {
			double m = (low + high) / 2;
			if (m <= eps || m == low || m == high) {
				break;
			}
			if (intersect(m, a)) {
				low = m;
			} else {
				high = m;
			}
		}
		double start = high;
		double answer = start + Math.sqrt(2 * d / a);
		return answer;
	}
	
	private boolean intersect(double start, double a) {
		for (int i = 0; i < t.length; i++) {
			if (t[i] < start || x[i] >= d) {
				continue;
			}
			double tm = t[i] - start;
			double y = a * tm * tm / 2;
			if (y > x[i]) {
				return true;
			}
		}
		double tf = start + Math.sqrt(2 * d / a);
		for (int i = 0; i + 1 < t.length; i++) {
			if (t[i] < tf && tf < t[i + 1]) {
				double xx = x[i] + (x[i + 1] - x[i]) * (tf - t[i]) / (t[i + 1] - t[i]);
				if (xx < d) {
					return true;
				}
			}
		}
		return false;
	}

	private void solve() throws IOException {
		int tt = nextInt();
		for (int test = 1; test <= tt; test++) {
			System.out.println(test);
			d = nextDouble();
			int n = nextInt();
			int a = nextInt();
			t = new double[n];
			x = new double[n];
			for (int i = 0; i < n; i++) {
				t[i] = nextDouble();
				x[i] = nextDouble();
			}
			out.println("Case #" + test + ":");
			for (int i = 0; i < a; i++) {
				double av = nextDouble();
				double answer = solve(av);
				out.println(answer);
			}
		}
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	private void apstenu(Throwable e) {
		e.printStackTrace();
		System.exit(1);
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			apstenu(e);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
	
}
