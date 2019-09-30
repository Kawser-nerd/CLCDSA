import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "B-large";
	
	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int[] a = new int[10002];
		for (int i = 0; i < n; ++i) {
			a[nextInt()]++;
		}
		int[] q = new int[n];
		int qs = 0, qe = 0;
		int ans = n;
		for (int i = 0; i <= 10001; ++i) {
			while (qe - qs > a[i]) {
				ans = Math.min(ans, i - q[qs++]);
			}
			while (qe - qs < a[i]) {
				q[qe++] = i;
			}
		}
		if (qs != qe) {
			throw new AssertionError();
		}
		out.println(ans);
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
