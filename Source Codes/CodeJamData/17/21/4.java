import java.io.*;
import java.util.*;

public class A {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	String get() throws Exception {
		double ans = 0;
		double d = nextInt();
		int c = nextInt();
		double maxt = 0;
		for (int i = 0; i < c; i++) {
			double x = nextInt();
			double v = nextInt();
			double t = (d - x) / v;
			maxt = Math.max(t, maxt);
		}

		return "" + String.format("%.8f", d/maxt);
	}

	void solve() throws Exception {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.println("Case #" + (i + 1) + ": " + get());
		}
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
			final String className = this.getClass().getName().toLowerCase();
			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		new A().run();
	}

}
