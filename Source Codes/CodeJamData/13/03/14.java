import java.io.*;
import java.util.*;
import java.math.*;

public class FairSquare implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	final long maxValue = 100000000000000L;

	void solve() throws IOException {
		ArrayList<Long> good = new ArrayList<Long>();

		for (long i = 1; i * i <= maxValue; i++)
			if (isGood(i) && isGood(i * i))
				good.add(i * i);

		int tests = nextInt();

		for (int test = 1; test <= tests; test++)
			out.println("Case #" + test + ": " + solveOne(good));

	}

	private boolean isGood(long n) {
		String s = Long.toString(n);
		int l = 0, r = s.length() - 1;
		while (l < r)
			if (s.charAt(l++) != s.charAt(r--))
				return false;

		return true;
	}

	private String solveOne(ArrayList<Long> good) throws IOException {
		long l = nextLong(), r = nextLong();
		return Long.toString(solveOne(good, r) - solveOne(good, l - 1));
	}

	private int solveOne(ArrayList<Long> good, long n) {
		int l = -1, r = good.size();
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (good.get(m) <= n)
				l = m;
			else
				r = m;
		}
		return l + 1;
	}

	public static void main(String[] args) {
		new FairSquare().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}