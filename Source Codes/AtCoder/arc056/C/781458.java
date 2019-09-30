import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		int n = sc.nextInt();
		int k = sc.nextInt();

		int[][] w = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				w[i][j] = sc.nextInt();
			}
		}

		int[] tr2 = new int[0x1 << n];
		for (int i = 1; i < 0x1 << n; i++) {
			int j = Integer.numberOfTrailingZeros(i);
			int mask = i & ~(0x1 << j);
			tr2[i] = tr2[mask];
			for (int l = 0; l < n; l++) {
				if ((mask & 0x1 << l) == 0) {
					continue;
				}
				tr2[i] += w[j][l];
			}
		}

		int[] dp = new int[0x1 << n];
		for (int i = 1; i < 0x1 << n; i++) {
			for (int sub = i; sub > 0; sub = (sub - 1) & i) {
				int isub = i ^ sub;
				dp[i] = Math.max(dp[i], k + dp[isub] -tr2[i] + tr2[sub] + tr2[isub]);
			}
		}

		pr.println(dp[(0x1 << n) - 1]);

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