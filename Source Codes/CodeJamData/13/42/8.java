import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			long p = nextLong();
			long y = findGuara(n, p);
			long z = findCould(n, p);
			out.println("Case #" + test + ": " + y + " " + z);
		}
	}
	
	private long findGuara(int n, long p) {
		long left = 0;
		long right = (1L << n);
		while (left + 1 < right) {
			long mid = (left + right) / 2;
			if (worst(mid, n, p) < p) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return left;
	}

	private long findCould(int n, long p) {
		long left = 0;
		long right = (1L << n);
		while (left + 1 < right) {
			long mid = (left + right) / 2;
			if (best(mid, n, p) < p) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return left;
	}
	
	private long worst(long mid, int n, long p) {
		long remain = mid;
		long result = 0;
		for (int i = 0; i < n; i++) {
			if (remain >= (1L << i)) {
				remain -= (1L << i);
				result |= (1L << (n - 1 - i));
			} else {
				//result |= (1L << (n - 1 - i));
			}
		}
		return result;
	}
	
	private long best(long mid, int n, long p) {
		long remain = (1L << n) - 1 - mid;
		long result = 0;
		for (int i = 0; i < n; i++) {
			if (remain >= (1L << i)) {
				remain -= (1L << i);
				//result |= (1L << (n - 1 - i));
			} else {
				result |= (1L << (n - 1 - i));
			}
		}
		return result;
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
