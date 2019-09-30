import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Csmall {

	public static void main(String... args) throws Exception {
		FastScan sc = new FastScan(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter pw = new PrintWriter(System.out);

		for (int TC = 1, TCC = sc.in(); TC <= TCC; ++TC) {
			int N = sc.in();
			int K = sc.in();

			if (N != K)
				throw new RuntimeException();

			double U = sc.db();
			double[] probs = new double[N + 1];
			probs[N] = 1;
			for (int i = 0; i < N; ++i) {
				probs[i] = sc.db();
			}

			Arrays.sort(probs);

			double[] psum = new double[N + 1];
			psum[0] = 0;
			for (int i = 0; i < N; ++i) {
				psum[i + 1] = psum[i] + probs[i];
			}

			for (int i = 1;; ++i) {
				double needed = i >= N ? Double.POSITIVE_INFINITY : probs[i] * i - psum[i];
				if (needed > U) {
					double possible = probs[i - 1] * (i - 1) - psum[i - 1];
					double leftover = U - possible;
					double level = Math.min(1d, probs[i - 1] + leftover / i);

					for (int j = 0; j < i; ++j) {
						probs[j] = level;
					}
					break;
				}
			}

			double prob = 1d;
			for (double d : probs) {
				prob *= d;
			}

			pw.printf("Case #%d: %.9f\n", TC, prob);
		}

		sc.close();
		pw.close();
		System.exit(0);
	}

	static class FastScan implements Closeable {
		private BufferedReader br;
		private StringTokenizer tk;

		public FastScan(BufferedReader br) {
			this.br = br;
		}

		public int in() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long ln() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public double db() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		@Override
		public void close() throws IOException {
			tk = null;
			br.close();
		}

		public String next() throws IOException {
			while (tk == null || !tk.hasMoreTokens()) {
				String line = br.readLine();
				if (line == null)
					return null;
				tk = new StringTokenizer(line);
			}
			return tk.nextToken();
		}
	}
}
