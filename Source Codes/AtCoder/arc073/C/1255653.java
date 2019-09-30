import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {
	
	final long INF = 1001001001;
	void solve() {
		int N = sc.nextInt();
		int[][] p = new int[N][2];
		for (int i = 0; i < N; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			p[i][0] = min(x, y);
			p[i][1] = max(x, y);
		}
		sort(p, new Comparator<int[]>(){
			@Override
			public int compare(int[] a, int[] b) {
				if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
				return Integer.compare(a[1], b[1]);
			}
		});
		long Rmax = 0, Bmax = 0;
		long Rmin = INF, Bmin = INF;
		for (int i = 0; i < N; i++) {
			Rmax = max(Rmax, p[i][0]);
			Rmin = min(Rmin, p[i][0]);
			Bmax = max(Bmax, p[i][1]);
			Bmin = min(Bmin, p[i][1]);
		}
		long ans = (Rmax - Rmin) * (Bmax - Bmin);
		
		long Gmax = max(Rmax, Bmax);
		long Gmin = min(Rmin, Bmin);

		ans = min(ans, (Gmax - Gmin) * f(p));
		out.println(ans);
	}
	
	long f(int[][]p) {
		TreeSet<Long> st = new TreeSet<>();
		for (int i = 0; i < p.length; i++) {
			st.add( ((long)p[i][0] << 20) + i );
		}
		long res = d(st);
		for (int i = 0; i < p.length; i++) {
			st.remove(((long) p[i][0] << 20) + i);
			st.add(((long) p[i][1] << 20) + i);
			res = min(res, d(st));
		}
		return res;
	}
	
	long d(TreeSet<Long> st) {
		long mi = (st.first() >> 20);
		long ma = (st.last() >> 20);
		return ma - mi;
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