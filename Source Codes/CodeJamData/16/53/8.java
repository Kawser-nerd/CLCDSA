import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	int n, s;
	int[] x, y, z, vx, vy, vz;
	double[][] dist;
	boolean[] mark;
	double jump;
	
	String solve() {
		dist = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = Math.hypot(x[i] - x[j], Math.hypot(y[i] - y[j], z[i] - z[j]));
			}
		}
		double low = 0;
		double high = dist[0][1];
		while (low + 1e-5 < high) {
			jump = (low + high) * 0.5;
			mark = new boolean[n];
			dfs(0);
			if (mark[1]) {
				high = jump;
			} else {
				low = jump;
			}
		}
		return "" + high;
	}
	
	void dfs(int v) {
		if (mark[v]) {
			return;
		}
		mark[v] = true;
		for (int u = 0; u < n; u++) {
			if (dist[v][u] <= jump) {
				dfs(u);
			}
		}
	}

	public C(Scanner in) {
		n = in.nextInt();
		s = in.nextInt();
		x = new int[n];
		y = new int[n];
		z = new int[n];
		vx = new int[n];
		vy = new int[n];
		vz = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			z[i] = in.nextInt();
			vx[i] = in.nextInt();
			vy[i] = in.nextInt();
			vz[i] = in.nextInt();
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
		
		String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final C testCase = new C(in);
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
