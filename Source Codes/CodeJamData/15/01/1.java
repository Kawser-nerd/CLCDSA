import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int n;
	String s;
	
	String solve() {
		int up = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			int count = s.charAt(i) - '0';
			if (count == 0) {
				continue;
			}
			if (up < i) {
				ans += i - up;
				up = i;
			}
			up += count;
		}
		return "" + ans;
	}
	
	public A(Scanner in) {
		n = in.nextInt();
		s = in.next();
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
