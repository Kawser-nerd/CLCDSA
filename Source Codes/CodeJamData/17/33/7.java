import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.util.*;
import java.io.*;

@SuppressWarnings("unused")
public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();		
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		if (new File("input.txt").exists())
			in = new BufferedReader(new FileReader("input.txt"));
		else
			in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter("output.txt");
//		out = new PrintWriter(System.out);
		solve();
		in.close();
		out.close();
	}

	private void solve() throws IOException {
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			int n = nextInt();
			int m = nextInt();
			double u = nextDouble();
			
			double a[] = new double[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextDouble();
			}
			sort(a);
			double sum = 0;
			int id = 1;
			while (id < n && sum + (id) * (a[id] - a[id - 1]) <= u) {
				sum += (id) * (a[id] - a[id - 1]);
				id++;
			}
//			System.err.println(id);
			double g = (id < n) ? a[id] : 1;
			double h = u - sum;
			double d = (id) * (g - a[id - 1]);
//			System.err.println(g + " " + h + " " + d);
			double p = g;
			if (h < d)
				p = a[id - 1] + h / (id);
			for (int i = 0; i < id; i++)
				a[i] = p;
			double ans = 1;
			for (int i = 0; i < n; i++) {
				ans *= a[i];
			}
//			ans += PI * a[0].r * a[0].r;
//			for (int i = 0; i < k; i++) {
//				ans += a[i].r * 2. * PI * a[i].h;
//			}
			out.printf(Locale.US, "Case #%d: %.10f\n", t + 1, ans);
		}
		
	}
	
	class P implements Comparable<P> {

		int r;
		int h;
		P(int r, int h) {
			this.r = r;
			this.h = h;
		}
		
		@Override
		public int compareTo(P o) {
			if (this.r != o.r)
				return o.r - this.r;
			return this.r - o.r;
		}
		
	}
	
	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
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
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
