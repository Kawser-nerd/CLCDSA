import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		long n = in.nextLong();
		int nn = (int) Math.ceil(Math.sqrt(n));
		boolean[] isPrime = new boolean[nn + 1];
		for (int i = 2; i <= nn; i++)
			isPrime[i] = true;
		for (int i = 2, j; (j = i * i) <= nn; i++) {
			if (!isPrime[i])
				continue;
			do {
				isPrime[j] = false;
				j += i;
			} while (j <= nn);
		}
		int ans = (n > 1) ? 1 : 0;
		for (int p = 2; p * (long) p <= n; p++) {
			if (!isPrime[p]) {
				continue;
			}
			long q = 1;
			while (q * p <= n) {
				ans++;
				q *= p;
			}
			ans--;
		}
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
