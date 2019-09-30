import java.util.*;
import java.io.*;

public class Main {

	class Point {
		long x, y;

		public Point(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	
	long vm(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}
	
	void solve() {
		int mod = 998244353;
		int n = in.nextInt();
		Point[] a=  new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextLong(), in.nextLong());
		}
		long[] pow2 = new long[n + 1];
		pow2[0] = 1;
		for (int i = 0; i < n; i++) {
			pow2[i + 1] = pow2[i] * 2 % mod;
		}
		long result = pow2[n] - 1;
		for (int i = 0; i < n; i++) {
			result--;
			for (int j = i + 1; j < n; j++) {
				int cnt = 0;
				for (int k = j + 1; k < n; k++) {
					if (vm(a[i], a[j], a[k]) == 0) {
						cnt++;
					}
				}
				result -= pow2[cnt];
			}
		}
		out.println((result % mod + mod) % mod);
		
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}