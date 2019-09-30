import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int n, k;
	int[] s;
	
	String solve() {
		int sum = s[0];
		int[] diff = new int[k];
		for (int i = 0; i < k; i++) {
			int shift = 0;
			int minShift = 0;
			int maxShift = 0;
			for (int j = i + k; j < n; j += k) {
				shift += (s[j - k + 1] - s[j - k]);
				minShift = Math.min(minShift, shift);
				maxShift = Math.max(maxShift, shift);
			}
			diff[i] = maxShift - minShift;
			sum += minShift;
		}
		sum %= k;
		sum += k;
		sum %= k;
		Arrays.sort(diff);
//		System.out.println(sum + " _  " + Arrays.toString(diff));
		int space = 0;
		int ans = diff[k - 1];
		for (int i = 0; i < k; i++) {
			space += ans - diff[i];
		}
		if (sum > space) {
			ans++;
		}
		return "" + ans;
	}
	
	public B(Scanner in) {
		n = in.nextInt();
		k = in.nextInt();
		s = new int[n - k + 1];
		for (int i = 0; i < s.length; i++) {
			s[i] = in.nextInt();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
		
		String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
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
