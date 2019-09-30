import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		final int MOD = 1_000_000_007;

		int n = sc.nextInt();
		int c = sc.nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
		}

		long[][] tmp2 = new long[400 + 1][400 + 1];
		for (int i = 1; i <= 400; i++) {
			long tmp = 1;
			for (int j = 0; j <= 400; j++) {
				if (j > 0) {
					tmp *= i;
					tmp %= MOD;
				}
				tmp2[i][j] += tmp2[i - 1][j] + tmp;
				tmp2[i][j] %= MOD;
			}
		}

		long[][] dp = new long[n + 1][c + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= c; j++) {
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][j - k] * ((tmp2[b[i - 1]][k] - tmp2[a[i - 1] - 1][k] + MOD) % MOD) % MOD;
					dp[i][j] %= MOD;
				}
			}
		}

		pr.println(dp[n][c]);

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;
		Iterator<String> it;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		String next() throws RuntimeException  {
			try {
				if (it == null || !it.hasNext()) {
//					it = Arrays.asList(br.readLine().split(" ")).iterator();
					it = Arrays.asList(br.readLine().split("\\p{javaWhitespace}+")).iterator();
				}
				return it.next();
			} catch (IOException e) {
				throw new IllegalStateException();
			}
		}

		int nextInt() throws RuntimeException {
			return Integer.parseInt(next());
		}

		long nextLong() throws RuntimeException {
			return Long.parseLong(next());
		}

		float nextFloat() throws RuntimeException {
			return Float.parseFloat(next());
		}

		double nextDouble() throws RuntimeException {
			return Double.parseDouble(next());
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new IllegalStateException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}