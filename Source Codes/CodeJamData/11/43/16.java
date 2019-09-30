import java.io.*;
import java.util.*;

public class ExpensiveDinner {

	void solve() throws Exception {
		long n = nextLong();
		if (n == 1) {
			out.println(0);
			return;
		}
		ArrayList<Long> primes = new ArrayList<Long>();
		int sqrt = (int) Math.sqrt(n) + 10;
		boolean[] a = new boolean[sqrt + 1];
		for (int i = 2; i <= sqrt; i++) {
			if (!a[i]) {
				primes.add((long) i);
				for (int j = 2 * i; j <= sqrt; j += i)
					a[j] = true;
			}
		}
		long ans1 = 0;
		long ans2 = 1;
		for (long i : primes) {
			if (i > n)
				break;
			ans1++;
			long j = i;
			while (j <= n) {
				ans2++;
				j *= i;
			}
		}
		out.println(ans2 - ans1);
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("ExpensiveDinner").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new ExpensiveDinner().run();
	}

}
