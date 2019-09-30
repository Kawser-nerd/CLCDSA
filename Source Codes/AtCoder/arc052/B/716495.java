import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] X = new int[N];
		int[] R = new int[N];
		int[] H = new int[N];
		for (int i = 0; i < N; i++) {
			X[i] = sc.nextInt();
			R[i] = sc.nextInt();
			H[i] = sc.nextInt();
		}
		while (Q-->0) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			double ans = 0;
			for (int i = 0; i < N; i++) {
				ans += calc(X[i], R[i], H[i], A, B);
			}
			out.printf("%.8f%n", ans);
		}
	}
	
	double calc(double X, double R, double H, double A, double B) {
		if (B <= X || X + H <= A) return 0;
		double v1 = calc2(X, R, H, A);
		double v2 = calc2(X, R, H, B);
		return v1 - v2;
	}
	
	double calc2(double X, double R, double H, double A) {
		if (A < X) A = X;
		if (X + H <= A) return 0;
		double h = (X + H - A);
		double r = R * (X + H - A) / (H);
		return r * r * Math.PI * h / 3;
	}

	static void tr(Object... os) { System.err.println(deepToString(os)); }
	static void tr(int[][] as) { for (int[] a : as) tr(a); }

	void print(int[] a) {
		out.print(a[0]);
		for (int i = 1; i < a.length; i++) out.print(" " + a[i]);
		out.println();
	}

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	MyScanner sc = null;
	PrintWriter out = null;
	public void run() throws Exception {
		sc = new MyScanner(System.in);
		out = new PrintWriter(System.out);
		for (;sc.hasNext();) {
			solve();
			out.flush();
		}
		out.close();
	}

	class MyScanner {
		String line;
		BufferedReader reader;
		StringTokenizer tokenizer;

		public MyScanner(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
		public void eat() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					line = reader.readLine();
					if (line == null) {
						tokenizer = null;
						return;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		public String next() {
			eat();
			return tokenizer.nextToken();
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		public boolean hasNext() {
			eat();
			return (tokenizer != null && tokenizer.hasMoreElements());
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
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
	}
}