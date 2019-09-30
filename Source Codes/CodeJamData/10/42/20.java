import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int p = in.nextInt();
		int n = 1 << p;
		int[][] a = new int[2 * n][p + 1];
		int inf = Integer.MAX_VALUE / 3;
		for (int i = 2 * n - 1; i >= n; i--) {
			int miss = in.nextInt();
			for (int t = 0; t <= p; t++) {
				a[i][t] = (t <= miss) ? 0 : inf;
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			int c = in.nextInt();
			for (int t = 0; t <= p; t++) {
				int a1 = c + a[2 * i][t] + a[2 * i + 1][t];
				int a2 = (t + 1 <= p) ? a[2 * i][t + 1] + a[2 * i + 1][t + 1] : inf;
				a[i][t] = Math.min(a1, a2);
				if (a[i][t] > inf) {
					a[i][t] = inf;
				}
			}
		}
		out.println(a[1][0]);
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
			new B().solve();
		}
		in.close();
		out.close();
	}
}
