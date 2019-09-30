import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "D-small-attempt0";

	public void solve(int test) throws IOException {
		System.err.println(test);
		out.print("Case #" + (test + 1) + ": ");
		String s = next();
		long ones = 0, zeros = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(s.length() - i - 1) == '0') {
				zeros |= 1L << i;
			}
			if (s.charAt(s.length() - i - 1) == '1') {
				ones |= 1L << i;
			}
		}
		for (long x = 0; ; ++x) {
			long y = x * x;
			if ((y & zeros) == 0 && (y & ones) == ones) {
				out.println(Long.toBinaryString(y));
				return;
			}
		}
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
