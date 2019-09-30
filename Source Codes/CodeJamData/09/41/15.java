import java.io.*;
import java.util.*;

public class A implements Runnable {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++) {
				if (s.charAt(j) == '1') {
					a[i] = j;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int j;
			for (j = i;; j++) {
				if (a[j] <= i)
					break;
			}
			for (int k = j; k > i; k--) {
				ans++;
				int t = a[k];
				a[k] = a[k - 1];
				a[k - 1] = t;
			}
		}
		out.println(ans);
	}

	public void run() {
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			solve();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		Thread thread = new Thread(new A());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
