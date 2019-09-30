import java.io.*;
import java.util.*;

public class D {
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		String s = in.next();
		int n = s.length();
		int init = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '.') {
				init |= 1 << i;
			}
		}
		double[] a = new double[1 << n];
		for (int mask = 1; mask <= init; mask++) {
			for (int i = 0; i < n; i++) {
				int j = 0;
				int k = i;
				for (;;) {
					if (((mask >> k) & 1) == 1) {
						break;
					}
					j++;
					k++;
					if (k == n) {
						k = 0;
					}
				}
				int nm = mask ^ (1 << k);
				a[mask] += (n - j + a[nm]) / n;
			}
		}
		out.println(a[init]);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new File(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new D().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
