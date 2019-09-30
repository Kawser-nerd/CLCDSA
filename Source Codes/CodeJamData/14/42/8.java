import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int n;
	int[] a;
	
	String solve() {
		int ans = 0;
		int[] sorted = a.clone();
		Arrays.sort(sorted);
		for (int v : sorted) {
			int s1 = 0;
			int s2 = 0;
			boolean left = false;
			for (int i = 0; i < n; i++) {
				if (a[i] == v) {
					left = true;
					continue;
				}
				if (a[i] > v) {
					if (left) {
						s2++;
					} else {
						s1++;
					}
				}
			}
			ans += Math.min(s1, s2);
		}
		return "" + ans;
	}
	
	public B(Scanner in) {
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
	}
	
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
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
			final B testCase = new B(in);
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
