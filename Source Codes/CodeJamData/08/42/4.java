import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int tests = nextInt();
		loop: for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
			int m = nextInt();
			int a = nextInt();
			out.print("Case #" + test + ": ");
			for (int x1 = 0; x1 <= n; ++x1) {
				for (int x2 = 0; x2 <= n; ++ x2) {
					for (int y1 = 0; y1 <= m; ++y1) {
						for (int y2 = 0; y2 <= m; ++y2) {
							int b = x1 * y2 - x2 * y1;
							if (a == Math.abs(b)) {
								out.println("0 0 " + x1 + " " + y1 + " " + x2 + " " + y2);
								continue loop;
							}
						}
					}
				}
			}
			out.println("IMPOSSIBLE");
		}
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