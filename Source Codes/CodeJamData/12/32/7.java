import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double find(double v0, double a, double s) {
		double l = 0;
		double r = s/(v0+1e-12);
		for (int i = 0; i < 1000; i++) {
			double x = (l + r) / 2;
			if (v0 * x + a * x * x/2.0 > s-1e-10) {
				r = x;
			} else {
				l = x;
			}
		}
		return l;
	}

	void solve() throws IOException {
		double h = nextDouble();
		int n = nextInt();
		int A = nextInt();
		double[] t = new double[n];
		double[] x = new double[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextDouble();
			x[i] = nextDouble();
		}
		while (n > 1 && x[n - 2] > h) {
			n--;
		}
		if (n > 1) {
			double v = (x[n - 1] - x[n - 2]) / (t[n - 1] - t[n - 2]);
			x[n - 1] = h;
			t[n - 1] = (x[n - 1] - x[n - 2]) / v;
		}
		for (int tmp = 0; tmp < A; tmp++) {
			double a = nextDouble();
			double res = find(0, a, Math.min(x[0], h));
			double v = res * a;
			for (int i = 0; i < n - 1; i++) {
				double tm = find(v, a, x[i + 1] - x[i]);
				if (res + tm - 1e-10 > t[i + 1]) {
					res += tm;
					continue;
				}
				res = t[i + 1];
				v = (x[i + 1] - x[i]) / (t[i + 1] - t[i]);
			}
			out.println(res);
		}

	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.println("Case #" + (i + 1) + ":");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().run();
	}

}