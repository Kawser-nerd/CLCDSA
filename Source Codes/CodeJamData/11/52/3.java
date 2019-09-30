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
		if (n == 0) {
			out.println(0);
			return;
		}
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		int low = 0;
		int high = n + 1;
		while (low + 1 < high) {
			int m = (low + high) / 2;
			boolean ok = true;
			ArrayList<Integer> open = new ArrayList<Integer>();
			for (int v = a[0]; v <= a[n - 1] + 1; v++) {
				int k = 0;
				for (int i = 0; i < n; i++) {
					if (a[i] == v) {
						k++;
					}
				}
				for (int i = 0; i < open.size(); i++) {
					int len = open.get(i);
					if (k > 0) {
						k--;
						open.set(i, open.get(i) + 1);
					} else {
						if (len < m) {
							ok = false;
							break;
						} else {
							while (i < open.size()) {
								open.remove(open.size() - 1);
							}
							break;
						}
					}
				}
				while (k > 0) {
					open.add(1);
					k--;
				}
				Collections.sort(open);
			}
			if (ok) {
				low = m;
			} else {
				high = m;
			}
		}
		out.println(low);
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
