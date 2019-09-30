import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

import static java.math.BigInteger.*;

public class Main {
	void solve() {
		int n = sc.nextInt();
		P ps[] = new P[n];
		for (int i = 0; i < n; i++) {
			ps[i] = new P(sc.nextInt(), sc.nextInt());
		}
		sort(ps);
		long t = 0;
		long max_t = 0;
		for (P p : ps) {
			t += p.a;
			max_t = Math.max(max_t, t);
			t -= p.b;
		}
		out.println(max_t);
	}
	
	class P implements Comparable<P> {
		int a, b;
		int d;
		public int compareTo(P o) {
			if (Integer.signum(this.d) != Integer.signum(o.d)) {
				return Integer.compare(this.d, o.d);
			}
			if (this.d < 0) {
				return Integer.compare(a, o.a);
			} else if (this.d > 0) {
				return -Integer.compare(b, o.b);
			}
			else
				return 0;
		}
		public P(int a, int b) {
			this.a = a;
			this.b = b;
			this.d = a - b;
		}
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