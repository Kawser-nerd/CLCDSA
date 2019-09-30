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
		int[] a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			sum += a[i];
		}
		for (int i = 0; i < n; i++) {
			double low = 0;
			double high = 1;
			while (low + 1e-8 < high) {
				double m = (low + high) / 2;
				double need = 0;
				for (int j = 0; j < n; j++) {
					if (j == i) {
						continue;
					}
					need += Math.max(a[i] + sum * m - a[j], 0);
				}
				if (m + need / sum > 1) {
					high = m;
				} else {
					low = m;
				}
			}
			out.print(" " + low * 100);
		}
		out.println();
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
			out.print("Case #" + t + ":");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
