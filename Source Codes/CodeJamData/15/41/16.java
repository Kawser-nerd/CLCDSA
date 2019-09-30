import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int hei, wid;
	char[][] c;
	
	int[] dx = new int[]{1, 0, -1, 0};
	int[] dy = new int[]{0, 1, 0, -1};
	String dirs = "v>^<";
	
	String solve() {
		int ans = 0;
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				if (c[i][j] == '.') {
					continue;
				}
				int ok = 0;
				for (int d = 0; d < 4; d++) {
					int ii = i;
					int jj = j;
					for (;;) {
						ii += dx[d];
						jj += dy[d];
						if (ii < 0 || ii >= hei || jj < 0 || jj >= wid) {
							break;
						}
						if (c[ii][jj] == '.') {
							continue;
						}
						ok |= 1 << d;
						break;
					}
				}
				int d = dirs.indexOf(c[i][j]);
				if ((ok & (1 << d)) != 0) {
					continue;
				}
				if (ok == 0) {
					return "IMPOSSIBLE";
				}
				ans++;
			}
		}
		return "" + ans;
	}
	
	public A(Scanner in) {
		hei = in.nextInt();
		wid = in.nextInt();
		c = new char[hei][];
		for (int i = 0; i < hei; i++) {
			c[i] = in.next().toCharArray();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
		
		String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
