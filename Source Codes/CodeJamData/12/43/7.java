import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	final long MAX = 1000000000;
	int n;
	int[] a;
	long[] ans;
	
	private void solve() {
		n = in.nextInt();
		a = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			a[i] = in.nextInt() - 1;
		}
		ans = new long[n];
		ans[n - 1] = MAX;
		try {
			solve(0, n - 1, 0, MAX);
			for (int i = 0; i < n; i++) {
				out.print(" " + ans[i]);
			}
			out.println();
		} catch (Exception e) {
			out.println(" Impossible");
		}
	}

	private void solve(int from, int to, int slope, long h) {
		if (from == to) {
			return;
		}
		int i = from;
		while (i < to) {
			ans[i] = h - slope * (to - i);
			if (a[i] > to) {
				throw new RuntimeException();
			}
			solve(i + 1, a[i], slope + 1, h - slope * (to - a[i]));
			i = a[i];
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
			out.print("Case #" + t + ":");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
