import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		int n = sc.nextInt();
		int k = sc.nextInt();

		int[] a = new int[n];
		int[] sum = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			sum[i + 1] = sum[i] + a[i];
		}

		if (sum[n] == k) {
			pr.println(1);

			pr.close();
			sc.close();
			return;
		}

		int[][] dp = new int[n + 1][n + 1];
		final int INF = Integer.MAX_VALUE / 2;
		for (int i = 0; i <= n; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0];
			for (int j = 1; j <= i; j++) {
				double value;
				if (i == 1) {
					value = 0;
				} else {
					value = (double)dp[i - 1][j - 1] / sum[i - 1];
				}

				int tmp = (int)Math.floor(sum[i] * value + 1);

				if (dp[i - 1][j - 1] == INF) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = Math.min(dp[i - 1][j], tmp);
				}
			}
		}

		for (int j = n; j >= 0; j--) {
			if (dp[n][j] <= k) {
				pr.println(j);
				break;
			}
		}

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
					it = Arrays.asList(br.readLine().split(" ")).iterator();
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