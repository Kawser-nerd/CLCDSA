import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

import javax.activation.CommandInfo;

import java.io.*;

public class Main {

	static final long MOD = (long)(1e9+7);
	long A;
	
	void solve() {
		int N = sc.nextInt();
		A = sc.nextLong();
		long B = sc.nextLong();
		long[] a = new long[N];
		for (int i = 0; i < N; i++) a[i] = sc.nextLong();
		
		if (A == 1) {
			sort(a);
			for (int i = 0; i < N; i++) {
				out.println(a[i] % MOD);
			}
			return;
		}
		if (N == 1) {
			out.println(a[0] * mod_pow(A, B, MOD) % MOD);
			return;
		}
		
		P[] p = new P[N];
		for (int i = 0; i < N; i++) p[i] = new P(a[i]);
//		for (P pi : p) tr(pi);
		
		Comparator<P> comp = new Comparator<P>() {
			public int compare(P a, P b) {
				if (a.x != b.x) return a.x < b.x ? -1 : 1;
				return Double.compare(a.y, b.y);
			};
		};
		
		sort(p, comp);
		while (B > 0 && p[0].x != p[N-1].x) {
			B--;
			p[0].x++;
			p[0].times++;
			sort(p, comp);
		}
		long all = B / N;
		for (int i = 0; i < N; i++) {
			p[i].x += all;
			p[i].times += all;
		}
		B %= N;
		while (B > 0) {
			B--;
			p[0].x++;
			p[0].times++;
			sort(p, comp);
		}
		
		for (int i = 0; i < N; i++) {
			long v = p[i].a * mod_pow(A, p[i].times, MOD) % MOD;
			out.println(v);
		}
	}
	
	class P {
		// num = A^s + t
		long a;
		long x;
		double y;
		long times = 0;
		P(long a) {
			this.a = a;
			this.x = 0;
			this.y = a;
			while (a >= A) {
				this.x++;
				a /= A;
				this.y /= A;
			}
		}
		@Override
		public String toString() {
			return String.format("[%d, %d, %.6f]", a, x, y);
		}
	}

	long mod_pow(long a, long b, long p) {
		long res = 1;
		while (b > 0) {
			if ((b & 1) == 1)
				res = (res * a) % p;
			a = (a * a) % p;
			b >>= 1;
		}
		return res;
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