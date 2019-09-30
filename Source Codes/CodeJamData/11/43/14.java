import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";
	
	long[] ps;
	{
		boolean[] primes = new boolean[1001001];
		Arrays.fill(primes, true);
		primes[0] = primes[1] = false;
		int psc = 0;
		for (int i = 2; i < primes.length; ++i) {
			if (primes[i]) {
				psc++;
				for (int j = 2 * i; j < primes.length; j += i) {
					primes[j] = false;
				}
			}
		}
		ps = new long[psc];
		for (int i = 0, j = 0; i < primes.length; ++i) {
			if (primes[i]) {
				ps[j++] = i;
			}
		}
	}

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		long n = nextLong();
		if (n == 1) {
			out.println(0);
			return;
		}
		long ans = 1;
		for (long p : ps) {
			if (p * p > n) {
				break;
			}
			for (long x = p * p; x <= n; x *= p) {
				ans++;
			}
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
