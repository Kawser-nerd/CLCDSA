import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		int n = sc.nextInt();

		String s = sc.next();
		int k = s.length();

		int[][] dp = new int[n + 2][n + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == 0) {
					dp[j][i] += dp[j][i - 1];
					dp[j][i] %= MOD;
					dp[j][i] += dp[j + 1][i - 1];
					dp[j][i] %= MOD;
				} else {
					dp[j][i] += dp[j - 1][i - 1];
					dp[j][i] %= MOD;
					dp[j][i] += dp[j - 1][i - 1];
					dp[j][i] %= MOD;
					dp[j][i] += dp[j + 1][i - 1];
					dp[j][i] %= MOD;
				}
			}
		}

		pr.println(dp[k][n] * pow((MOD + 1) / 2, k) % MOD);

		pr.close();
		sc.close();
	}

	static final int MOD = 1_000_000_007;

	private static long pow(int a, long n) {
		long loop = n;
		long ret = 1;
		long x = a;
		while (loop > 0) {
			if (loop % 2 == 1) {
				ret = ret * x % MOD;
			}
			x = x * x % MOD;
			loop /= 2;
		}

		return ret;
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