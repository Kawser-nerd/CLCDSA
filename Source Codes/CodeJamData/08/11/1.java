import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	private boolean[] col;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			long[] a = new long[n];
			long[] b = new long[n];
			for (int i = 0; i < n; ++i) {
				a[i] = nextLong();
			}
			for (int i = 0; i < n; ++i) {
				b[i] = nextLong();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			col = new boolean[n];
			long res = 0;
			for (int i = 0; i < n; ++i) {
				res += a[i] * b[n - i - 1];
			}
			out.println("Case #" + (test + 1) + ": " + res);
		}
	}

	private long rec(int i, long[] a, long[] b, long v) {
		int n =  col.length;
		if (i == n) {
			return v;
		}
		long res = Long.MAX_VALUE;
		for (int j = 0; j < n; ++j) {
			if (col[j]) {
				continue;
			}
			col[j] = true;
			res = Math.min(res, rec(i + 1, a, b, v + a[i] * b[j]));
			col[j] = false;
		}
		return res;
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
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
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}