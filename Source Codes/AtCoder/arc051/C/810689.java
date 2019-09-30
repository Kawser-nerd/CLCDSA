import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		final int MOD = 1_000_000_007;

		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();

		PriorityQueue<Long> pq = new PriorityQueue<>();
		long max = 0;
		for (int i = 0; i < n; i++) {
			long tmp = sc.nextInt();
			pq.add(tmp);
			max = Math.max(max, tmp);
		}

		int i;
		for (i = 0; i < b && a > 1; i++) {
			long e = pq.peek();

			if (e * a > max) {
				break;
			} else {
				pq.remove();
				pq.add(e * a);
			}
		}

		if (a == 1 || i == b) {
			for (int j = 0; j < n; j++) {
				pr.println(pq.remove() % MOD);
			}
		} else {
			List<Long> ret = new ArrayList<>(pq);
			Collections.sort(ret);

			int m = b - i;
			for (int j = 0; j < m % n; j++) {
				ret.set(j, ret.get(j) * a % MOD);
			}

			long pow = pow(a, m / n);

			for (int j = m % n; j < n; j++) {
				pr.println(ret.get(j) * pow % MOD);
			}
			for (int j = 0; j < m % n; j++) {
				pr.println(ret.get(j) * pow % MOD);
			}
		}

		pr.close();
		sc.close();
	}

	private static final int MOD = 1_000_000_007;

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