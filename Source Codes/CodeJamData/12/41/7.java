import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		long[] d = new long[n];
		long[] len = new long[n];
		for (int i = 0; i < n; i++) {
			d[i] = in.nextLong();
			len[i] = in.nextLong();
		}
		long dist = in.nextLong();
		long[] a = new long[n];
		Arrays.fill(a, -1);
		a[0] = d[0];
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				continue;
			}
			if (d[i] + a[i] >= dist) {
				out.println("YES");
				return;
			}
			for (int j = i + 1; j < n; j++) {
				if (d[j] > d[i] + a[i]) {
					break;
				}
				long cur = Math.min(d[j] - d[i], len[j]);
				a[j] = Math.max(a[j], cur);
			}
		}
		out.println("NO");
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
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
