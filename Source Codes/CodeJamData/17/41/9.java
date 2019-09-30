import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	String solve() {
		int[] a = new int[4];
		for (int i = 0; i < n; i++) {
			a[g[i] % p]++;
		}
		int[][][][] m = new int[a[1] + 1][a[2] + 1][a[3] + 1][p];
		for (int i = 0; i <= a[1]; i++) {
			for (int j = 0; j <= a[2]; j++) {
				for (int k = 0; k <= a[3]; k++) {
					for (int t = 0; t < p; t++) {
						int w = (t == 0) ? 1 : 0;
						if (i > 0) m[i][j][k][t] = Math.max(m[i][j][k][t], w + m[i - 1][j][k][(t + 1) % p]);
						if (j > 0) m[i][j][k][t] = Math.max(m[i][j][k][t], w + m[i][j - 1][k][(t + 2) % p]);
						if (k > 0) m[i][j][k][t] = Math.max(m[i][j][k][t], w + m[i][j][k - 1][(t + 3) % p]);
					}
				}
			}
		}
		return a[0] + m[a[1]][a[2]][a[3]][0] + "";
	}
	
	int n, p;
	int[] g;
	
	public A(Scanner in) {
		n = in.nextInt();
		p = in.nextInt();
		g = new int[n];
		for (int i = 0; i < n; i++) {
			g[i] = in.nextInt();
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
		
		String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final A testCase = new A(in);
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
