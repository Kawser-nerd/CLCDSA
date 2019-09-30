import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int n;
	int[] a;
	
	String solve() {
		String[][] game = new String[n + 1][3];
		game[0] = new String[]{"P", "R", "S"};
		for (int m = 1; m <= n; m++) {
			for (int i = 0; i < 3; i++) {
				String gThis = game[m - 1][i];
				String gThat = game[m - 1][(i + 1) % 3];
				String g1 = gThis + gThat;
				String g2 = gThat + gThis;
				game[m][i] =  (g1.compareTo(g2) < 0) ? g1 : g2;
			}
		}
		for (int i = 0; i < 3; i++) {
			String s = game[n][i];
			int[] b = new int[3];
			for (int j = 0; j < s.length(); j++) {
				b["PRS".indexOf(s.charAt(j))]++;
			}
			if (Arrays.equals(b, a)) {
				return s;
			}
		}
		return "IMPOSSIBLE";
	}
	
	public A(Scanner in) {
		n = in.nextInt();
		a = new int[3];
		a[1] = in.nextInt();
		a[0] = in.nextInt();
		a[2] = in.nextInt();
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
