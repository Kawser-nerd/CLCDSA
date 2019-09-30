import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		long s = in.nextInt();
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		int ans = n;
		int created = 0;
		for (int i = 0; i < n; i++) {
			if (s == 1) {
				break;
			}
			while (s <= a[i]) {
				created++;
				s += s - 1;
			}
			s += a[i];
			ans = Math.min(ans, created + n - i - 1);
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
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
