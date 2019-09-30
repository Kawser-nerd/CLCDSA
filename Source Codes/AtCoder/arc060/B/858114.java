import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		long n = sc.nextLong();
		long s = sc.nextLong();

		out:
		if (n == s) {
			pr.println(n + 1);
		} else if (n < s) {
			pr.println(-1);
		} else {
			for (long b = 2; b < 1_000_000; b++) {
				long ret = 0;
				long tmp = n;
				while (tmp > 0) {
					ret += tmp % b;
					tmp /= b;
				}

				if (ret == s) {
					pr.println(b);

					break out;
				}
			}

			for (long p = Math.min(1_000_000, s); p >= 1; p--) {
				if ((n - s) % p == 0) {
					long b = (n - s) / p + 1;

					if (s - p < b) {
						pr.println(b);

						break out;
					}
				}
			}

			pr.println(-1);
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