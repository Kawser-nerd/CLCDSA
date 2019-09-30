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
		int[] a = new int[n];
		int[] b = new int[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
			for (int j = 0; j < i; j++) {
				if ((a[i] > a[j]) ^ (b[i] > b[j])) {
					ans++;
				}
			}
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
			new A().solve();
		}
		in.close();
		out.close();
	}
}
