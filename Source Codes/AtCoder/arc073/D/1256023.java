import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {
	
	static final long INF = 1L << 58;
	class PointUpdateRangeMin {
		int n;
		long[] segMin;

		PointUpdateRangeMin(int n) {
			this.n = n;
			int size = n <= 1 ? 1 : (Integer.highestOneBit(n - 1) << 2);
			segMin = new long[size];
		}
		void fill(long val) {
			Arrays.fill(segMin, val);
		}
		void update(int a, long x) {
			update(a, x, 0, 0, n);
		}
		private void update(int a, long x, int k, int l, int r)
		{
			// ????? k ???? [l,r)?
			if (l <= a && a < r) {
				segMin[k] = Math.min(segMin[k], x);
				if (r - l >= 2) {
					update(a, x, k * 2 + 1, l, (l + r) / 2);
					update(a, x, k * 2 + 2, (l + r) / 2, r);
				}
			}
		}
		/**
		 * ??[a, b) ????????
		 */
		long getMin(int a, int b) {
			return getMin(a, b, 0, 0, n);
		}
		private long getMin(int a, int b, int k, int l, int r)
		{
			// ????? k ???? [l,r)?
			if (r <= a || b <= l) return INF;
			if (a <= l && r <= b) return (segMin[k]);
			long left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //????????????.
			long right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //????????????
			return Math.min(left, right);
		}
	}

	
	void solve() {
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		long addToAll = 0;
		PointUpdateRangeMin rmq = new PointUpdateRangeMin(200000 + 10);
		PointUpdateRangeMin rmqmj = new PointUpdateRangeMin(200000 + 10);
		PointUpdateRangeMin rmqpj = new PointUpdateRangeMin(200000 + 10);
		rmq.fill(INF);
		rmqmj.fill(INF);
		rmqpj.fill(INF);
		{
			rmq.update(B, 0);
			rmqmj.update(B, -B);
			rmqpj.update(B, B);
		}
		int s = A;
		for (int q = 0; q < Q; q++) {
			int t = sc.nextInt();
			long d = Math.abs(s - t);
			
			long m1 = rmqmj.getMin(1, t) + t;
			long m2 = rmqpj.getMin(t, N+1) - t;
			long m3 = rmq.getMin(s, s+1) + d;
			long m = min(m1, min(m2, m3));
			
			long v = (m - d);
			rmq.update(s, v);
			rmqmj.update(s, v - s);
			rmqpj.update(s, v + s);
			addToAll += d;
			s = t;
		}
		long ans = rmq.getMin(1, N+1) + addToAll;
		out.println(ans);
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