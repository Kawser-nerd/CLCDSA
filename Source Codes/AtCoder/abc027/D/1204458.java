import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;
import java.io.*;

public class Main {
	final int INF = 987654321;
	void solve() {
		char[] s = sc.next().toCharArray();
		int n = s.length;
		int[] g = new int[n+1];
		List<Integer> ms = new ArrayList<>();
		for (int i = n - 1; i >= 0; i--) {
			g[i] = g[i+1];
			if (s[i] == '+') g[i]++;
			if (s[i] == '-') g[i]--;
			if (s[i] == 'M') ms.add(g[i]);
		}
		Collections.sort(ms);
		int ans = 0;
		for (int i = 0; i < ms.size() / 2; i++) ans -= ms.get(i);
		for (int i = ms.size() / 2; i < ms.size(); i++) ans += ms.get(i);
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