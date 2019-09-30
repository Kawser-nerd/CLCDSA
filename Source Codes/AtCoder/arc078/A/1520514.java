import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{ // 

	public static void main(String args[]) {
		ConsoleScanner cin = new ConsoleScanner();
		PrintWriter cout = new PrintWriter(System.out);
		solve(cin, cout);
		cout.flush();
	}

	static long now() {
		return System.currentTimeMillis();
	}

	static void trace(Object... objects) {
		assert null != System.out.format("trace:%s\n", Arrays.deepToString(objects));
	}

	private static void solve(ConsoleScanner cin, PrintWriter cout) {
		// assert solve(1) == 1;

		int n = cin.nextInt();

		int[] a = new int[n];
		for (int i = 0; i < a.length; i++)
			a[i] = cin.nextInt();

		long start = now();

		long ans = solve(n, a);
		cout.println(ans);

		trace("elapsed", now() - start);
	}

	private static long solve(int n, int[] a) {
		long total = Arrays.stream(a).mapToLong(x -> x).sum();
		long ans = Long.MAX_VALUE;
		long s = 0;
		for (int i = 0; i < n - 1; i++) {
			s += a[i];
			ans = Math.min(ans, Math.abs(total - 2 * s));
		}
		return ans;
	}

	static class ConsoleScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			try {
				while (!st.hasMoreElements())
					st = new StringTokenizer(br.readLine());
				return st.nextToken();
			} catch (IOException e) {
				throw new AssertionError(e);
			}
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}