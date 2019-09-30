import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	String solve() {
		Collections.sort(d[0]);
		Collections.sort(d[1]);
		int x = 0;
		while (x < d[0].size() && d[0].get(x) == 0) {
			x++;
		}
		int y = 0;
		while (y < d[1].size() && d[1].get(y) == 0) {
			y++;
		}
		int cnt = Math.max(d[0].size(), d[1].size());
		cnt = Math.max(cnt, x + y);
		if (cnt == x + y) {
			return cnt + " 0";
		}
		int z = cnt - x - y;
		int ans = 0;
		for (int p = 0; p < n; p++) {
			int a = count[0][p];
			int b = count[1][p];
			if (a + b > cnt) {
				ans += a + b - cnt;
			}
		}
		return cnt + " " + ans;
	}
	
	int n, c;
	ArrayList<Integer>[] d;
	int[][] count;
	
	public B(Scanner in) {
		n = in.nextInt();
		c = in.nextInt();
		int m = in.nextInt();
		d = new ArrayList[c];
		for (int i = 0; i < c; i++) {
			d[i] = new ArrayList<Integer>();
		}
		count = new int[c][n];
		for (int i = 0; i < m; i++) {
			int p = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			d[b].add(p);
			count[b][p]++;
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
