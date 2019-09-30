import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int[][] a = new int[n][n];
		for (int i = 1; i < 2 * n; i++) {
			for (int j = 1; j <= Math.min(i, 2 * n - i); j++) {
				int jj = j;
				if (i > n) {
					jj += i - n;
				}
				a[jj - 1][jj - i + n - 1] = in.nextInt();
			}
		}
		List<Integer> xs = new ArrayList<Integer>();
		List<Integer> ys = new ArrayList<Integer>();
		for (int x = 0; x <= 2 * n - 2; x++) {
			boolean good = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int d = i + j - x;
					int ii = i - d;
					int jj = j - d;
					if (ii >= 0 && jj >= 0 && ii < n && jj < n && a[ii][jj] != a[i][j]) {
						good = false;
					}
				}
			}
			if (!good) {
				xs.add(x);
			}
		}
		for (int x = - n + 1; x <= n - 1; x++) {
			boolean good = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int d = i - j - x;
					int ii = i - d;
					int jj = j + d;
					if (ii >= 0 && jj >= 0 && ii < n && jj < n && a[ii][jj] != a[i][j]) {
						good = false;
					}
				}
			}
			if (!good) {
				ys.add(x);
			}
		}
		for (int m = n;; m++) {
			for (int x = 0; x + m >= n; x--) {
				for (int y = 0; y + m >= n; y--) {
					if (xs.contains(x + y + m - 1)) {
						continue;
					}
					if (ys.contains(x - y)) {
						continue;
					}
					out.println(m * m - n * n);
					return;
				}
			}
		}
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
		}
		in.close();
		out.close();
	}
}
