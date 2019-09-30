import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {
	int p;
	long[] e, f;
	
	String solve() {
		long sumF = 0;
		for (long ff : f) {
			sumF += ff;
		}
		int n = (int) Math.round(Math.log(sumF) / Math.log(2));
		long[] a = new long[n];
		for (int k = 0; k < n; k++) {
			long[] g = new long[p];
			g[0] = 1;
			for (int i = 0; i < k; i++) {
				long[] h = new long[p];
				for (int j = p - 1; j >= 0; j--) {
					if (g[j] == 0) {
						continue;
					}
					long sum = e[j] + a[i];
					int index = Arrays.binarySearch(e, sum);
					assert index >= 0;
					h[index] += g[j];
					h[j] += g[j];
				}
				g = h;
			}
			for (int j = 0; j < p; j++) {
				if (g[j] == f[j]) {
					continue;
				}
				a[k] = e[j] - e[0];
				break;
			}
		}
		for (int k = n - 1; k >= 0; k--) {
			int z = Arrays.binarySearch(e, 0);
			long[] g = new long[e.length];
			g[0] = 1;
			for (int i = 0; i < k; i++) {
				long[] h = new long[e.length];
				for (int j = e.length - 1; j >= 0; j--) {
					if (g[j] == 0) {
						continue;
					}
					long sum = e[j] + a[i];
					int index = Arrays.binarySearch(e, sum);
					assert index >= 0;
					h[index] += g[j];
					h[j] += g[j];
				}
				g = h;
			}
			if (g[z] < f[z]) {
				a[k] *= -1;
				for (int j = 0; j < e.length; j++) {
					f[j] = f[j] - g[j];
				}
			} else {
				for (int j = 0; j < e.length; j++) {
					f[j] = g[j];
				}
			}
			long[] ne = new long[e.length];
			long[] nf = new long[e.length];
			int j = 0;
			for (int i = 0; i < e.length; i++) {
				if (f[i] == 0) {
					continue;
				}
				ne[j] = e[i];
				nf[j] = f[i];
				j++;
			}
			e = Arrays.copyOf(ne, j);
			f = Arrays.copyOf(nf, j);
		}
		Arrays.sort(a);
		return Arrays.toString(a).replaceAll("[\\[\\],]", "");
	}
	
	public D(Scanner in) {
		p = in.nextInt();
		e = new long[p];
		f = new long[p];
		for (int i = 0; i < p; i++) {
			e[i] = in.nextLong();
		}
		for (int i = 0; i < p; i++) {
			f[i] = in.nextLong();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
		
		String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
