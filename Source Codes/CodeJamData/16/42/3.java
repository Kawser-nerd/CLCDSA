import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int n, k;
	double[] p;
	
	String solve() {
		Arrays.sort(p);
		double ans = 0;
		for (int m = 0; m <= k; m++) {
			double[] a = new double[k + 1];
			a[0] = 1;
			for (int i = 0; i < n; i++) {
				if (i >= m && i < m + n - k) {
					continue;
				}
				double[] b = new double[k + 1];
				for (int j = 0; j < k; j++) {
					b[j + 1] += a[j] * p[i];
					b[j] += a[j] * (1 - p[i]);
				}
				a = b;
			}
			ans = Math.max(ans, a[k / 2]);
		}
		return "" + ans;
	}
	
	public B(Scanner in) {
		n = in.nextInt();
		k = in.nextInt();
		p = new double[n];
		for (int i = 0; i < n; i++) {
			p[i] = in.nextDouble();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
//		/* "IPSC" */
//		String fileNameSuffix = "0";
//		String formatOut = "%s";
//		String formatSystemOut = "Case #%2$d solved.";//"Case #%2$d: %1$s";
		
		String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt(); in.nextLine();//1;
		nThreads = Math.min(nThreads, tests);
		@SuppressWarnings("unchecked")
		Callable<String>[] callables = new Callable[tests];
		for (int t = 0; t < tests; t++) {
			final B testCase = new B(in);
			final int testCaseNumber = t + 1;
			callables[t] = new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					System.out.println(String.format(formatSystemOut, answer, testCaseNumber));
					return String.format(formatOut, answer, testCaseNumber);
				}
			};
		}
		try {
			if (nThreads > 1) {
				ExecutorService executor = Executors.newFixedThreadPool(4);
				@SuppressWarnings("unchecked")
				Future<String>[] outputs = new Future[tests];
				for (int t = 0; t < tests; t++) {
					outputs[t] = executor.submit(callables[t]);
				}
				for (int t = 0; t < tests; t++) {
					out.println(outputs[t].get());
				}
				executor.shutdown();
			} else {
				for (int t = 0; t < tests; t++) {
					out.println(callables[t].call());
				}
			}
		} catch (Exception e) {
			System.out.flush();
			System.err.flush();
			e.printStackTrace();
			System.exit(1);
		}
		System.out.println("COMPLETE");
		in.close();
		out.close();
	}
}
