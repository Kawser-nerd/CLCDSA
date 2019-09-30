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
		int[] a = new int[n];
		int q = 0;
		for (int i = 0; i < n; i++) {
			switch (s.charAt(i)) {
			case '0':
				a[i] = 0;
				break;
			case '1':
				a[i] = 1;
				break;
			case '?':
				a[i] = 2;
				q++;
				break;
			}
		}
		for (int mask = 0; mask < (1 << q); mask++) {
			long v = 0;
			for (int i = 0, j = 0; i < n; i++) {
				int c = a[i];
				if (c == 2) {
					c = (mask >> j) & 1;
					j++;
				}
				v = 2 * v + c;
			}
			long u = Math.round(Math.sqrt(v));
			if (u * u == v) {
				out.println(Long.toBinaryString(v));
				return;
			}
		}
		throw new RuntimeException();
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
			new D().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
