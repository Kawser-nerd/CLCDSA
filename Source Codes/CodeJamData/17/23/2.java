import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class pC {
	double inf = 1e18;
	
	String solve() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (e[i][j] > e[i][k] + e[k][j]) {
						e[i][j] = e[i][k] + e[k][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (e[i][j] <= energy[i]) {
					e[i][j] /= speed[i];
				} else {
					e[i][j] = inf;
				}
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (e[i][j] > e[i][k] + e[k][j]) {
						e[i][j] = e[i][k] + e[k][j];
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < q; i++) {
			sb.append(e[from[i]][to[i]] + " ");
		}
		return sb.toString().trim();
	}
	
	int n, q;
	int[] energy, speed;
	double[][] e;
	int[] from, to;
	
	public pC(Scanner in) {
		n = in.nextInt();
		q = in.nextInt();
		energy = new int[n];
		speed = new int[n];
		for (int i = 0; i < n; i++) {
			energy[i] = in.nextInt();
			speed[i] = in.nextInt();
		}
		e = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				e[i][j] = in.nextInt();
				if (e[i][j] == -1) {
					e[i][j] = inf;
				}
			}
		}
		from = new int[q];
		to = new int[q];
		for (int i = 0; i < q; i++) {
			from[i] = in.nextInt() - 1;
			to[i] = in.nextInt() - 1;
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
		
		String fileName = pC.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final pC testCase = new pC(in);
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
