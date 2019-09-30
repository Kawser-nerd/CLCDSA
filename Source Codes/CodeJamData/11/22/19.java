import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int points = in.nextInt();
		int d = in.nextInt();
		List<Integer> xs = new ArrayList<Integer>();
		for (int i = 0; i < points; i++) {
			int x = in.nextInt();
			int amount = in.nextInt();
			for (int j = 0; j < amount; j++) {
				xs.add(x);
			}
		}
		Collections.sort(xs);
		double left = 0;
		double right = 1e12;
		binsearch:
		while (left + 0.5e-6 < right) {
			System.out.println(right - left);
			double time = (left + right) / 2;
			double p = -1e15;
			for (int x : xs) {
				double pp = Math.max(x - time, p + d);
				if (pp > x + time) {
					if (left == time) {
						break;
					}
					left = time;
					continue binsearch;
				}
				p = pp;
			}
			if (right == time) {
				break;
			}
			right = time;
		}
		out.println(right);
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
