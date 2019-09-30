import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int n;
	int[] a;
	
	String solve() {
		int ans1 = 0;
		int rate = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] > a[i]) {
				ans1 += a[i - 1] - a[i];
				rate = Math.max(rate, a[i - 1] - a[i]);
			}
		}
		int ans2 = 0;
		for (int i = 1; i < n; i++) {
			ans2 += Math.min(rate, a[i - 1]);
		}
		return ans1 + " " + ans2;
	}
	
	public A(Scanner in) {
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
	}
	
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	
	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(4);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final A testCase = new A(in);
			final int testCaseNumber = t;
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					String printed = "Case #" + (testCaseNumber + 1) + ": " + answer;
					System.out.println(printed);
					return printed;
				}
			});
		}
		for (int t = 0; t < tests; t++) {
			out.println(outputs[t].get());
		}
		in.close();
		out.close();
		executor.shutdown();
	}
}
