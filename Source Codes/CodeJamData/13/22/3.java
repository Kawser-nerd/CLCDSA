import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int x = Math.abs(in.nextInt());
		int y = in.nextInt();
		int m = 1;
		while (m * (m + 1) / 2 < n) {
			m += 2;
		}
		int d = (x + y) / 2;
		if (d < m / 2) {
			out.println(1.0);
			return;
		}
		if (d > m / 2) {
			out.println(0.0);
			return;
		}
		n -= (m - 2) * (m - 1) / 2;
		if (n == 2 * m - 1) {
			out.println(1.0);
			return;
		}
		if (y == m - 1) {
			out.println(0.0);
			return;
		}
		double[][] p = new double[n + 1][m];
		p[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k = i - j;
				if (j == m - 1) {
					p[i + 1][j] += p[i][j];
					continue;
				}
				if (k == m - 1) {
					p[i + 1][j + 1] += p[i][j];
					continue;
				}
				p[i + 1][j] += 0.5 * p[i][j];
				p[i + 1][j + 1] += 0.5 * p[i][j];
			}
		}
		double ans = 0;
		for (int j = y + 1; j < m; j++) {
			ans += p[n][j];
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
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
