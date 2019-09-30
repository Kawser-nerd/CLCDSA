import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {
	int n;
	boolean[][] a;
	
	String solve() {
		int maskGiven = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					maskGiven |= (1 << (n * i + j));
				}
			}
		}
		int ans = n * n;
		for (int mask = 0; mask < (1 << (n * n)); mask++) {
			if ((mask & maskGiven) != maskGiven) {
				continue;
			}
			int cost = Integer.bitCount(mask ^ maskGiven);
			if (cost >= ans) {
				continue;
			}
			if (canFail(mask, 0, 0)) {
				continue;
			}
			ans = cost;
		}
		return "" + ans;
	}
	
	boolean canFail(int mask, int came, int occupied) {
		if (came == (1 << n) - 1) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (((came >> i) & 1) == 1) {
				continue;
			}
			int var = 0;
			for (int j = 0; j < n; j++) {
				if (((occupied >> j) & 1) == 1) {
					continue;
				}
				if (((mask >> (n * i + j)) & 1) == 0) {
					continue;
				}
				var++;
				if (canFail(mask, came | (1 << i), occupied | (1 << j))) {
					return true;
				}
			}
			if (var == 0) {
				return true;
			}
		}
		return false;
	}
	
	public D(Scanner in) {
		n = in.nextInt();
		a = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j) == '1';
			}
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
		
		String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final D testCase = new D(in);
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
