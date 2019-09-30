import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {
	final int MODULO = 1000000007;
	int m, n;
	String[] s;
	
	String solve() {
		int p = 1;
		for (int i = 0; i < m; i++) {
			p *= n;
		}
		int[] a = new int[m];
		int bestSize = -1;
		int bestCount = 0;
		for (int assign = 0; assign < p; assign++) {
			int q = assign;
			for (int i = 0; i < m; i++) {
				a[i] = q % n;
				q /= n;
			}
			int size = 0;
			for (int i = 0; i < n; i++) {
				Set<String> pref = new HashSet<>();
				for (int j = 0; j < m; j++) {
					if (a[j] == i) {
						for (int k = 0; k <= s[j].length(); k++) {
							pref.add(s[j].substring(0, k));
						}
					}
				}
				size += pref.size();
			}
			if (size > bestSize) {
				 bestSize = size;
				 bestCount = 1;
			} else if (size == bestSize) {
				bestCount++;
			}
		}
		return bestSize + " " + bestCount;
	}
	
	public D(Scanner in) {
		m = in.nextInt();
		n = in.nextInt();
		s = new String[m];
		for (int i = 0; i < m; i++) {
			s[i] = in.next();
		}
	}
	
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	
	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(4);
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final D testCase = new D(in);
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					return testCase.solve();
				}
			});
		}
		for (int t = 0; t < tests; t++) {
			out.println("Case #" + (t + 1) + ": " + outputs[t].get());
		}
		in.close();
		out.close();
		executor.shutdown();
	}
}
