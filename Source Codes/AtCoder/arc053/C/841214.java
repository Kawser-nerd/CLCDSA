import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Printer pr = new Printer(System.out);

		int n = sc.nextInt();

		List<Pair> pl = new ArrayList<>(n);
		List<Pair> mi = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			if (a >= b) {
				pl.add(new Pair(a, b));
			} else {
				mi.add(new Pair(a, b));
			}
		}

		Collections.sort(pl, (o1, o2) -> Integer.compare(o2.b, o1.b));
		Collections.sort(mi, (o1, o2) -> Integer.compare(o1.a, o2.a));

		long max = 0;
		long tmp = 0;
		for (Pair e : mi) {
			max = Math.max(max, tmp + e.a);
			tmp += e.a - e.b;
		}
		for (Pair e : pl) {
			max = Math.max(max, tmp + e.a);
			tmp += e.a - e.b;
		}

		pr.println(max);

		pr.close();
		sc.close();
	}

	private static class Pair {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
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