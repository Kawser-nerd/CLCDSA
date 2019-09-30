import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		int n = sc.nextInt();
		int q = sc.nextInt();

		int[] x = new int[n];
		int[] r = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			r[i] = sc.nextInt();
			h[i] = sc.nextInt();
		}

		for (int i = 0; i < q; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			double ret = 0;
			for (int j = 0; j < n; j++) {
				ret += v(x[j], r[j], h[j], a) - v(x[j], r[j], h[j], b);
			}

			pr.printf("%.4f\n", ret);
		}

		pr.close();
		sc.close();
	}

	private static double v(int x, int r, int h, int a) {
		if (a <= x) {
			return Math.PI / 3 * r * r * h;
		} else if (a >= x + h) {
			return 0;
		} else {
			double hh = x + h - a;
			double rr = (double)(x + h - a) / h * r;
			return Math.PI / 3 * rr * rr * hh;
		}
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