import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int n;
	long tNeed, vNeed;
	Source[] sources;
	double eps = 1e-9;
	
	String solve() {
		Arrays.sort(sources);
		if (tNeed < sources[0].t - eps || tNeed > sources[n - 1].t + eps) {
			return "IMPOSSIBLE";
		}
		Source[] sourcesReversed = new Source[n];
		double sumR = 0;
		for (int i = 0; i < n; i++) {
			sumR += sources[i].rate;
			sourcesReversed[n - 1 - i] = sources[i];
		}
		double vtNeed = tNeed * 1.0 * vNeed;
		double low = vNeed / sumR;
		double high = 1e4 * vNeed;
		while (low + eps < high) {
			double time = (low + high) * 0.5;
			double[] res = new double[2];
			for (int q = 0; q < 2; q++) {
				Source[] array = (q == 0) ? sources : sourcesReversed;
				double vTaken = 0;
				double vt = 0;
				for (int i = 0; i < n; i++) {
					double take = Math.min(array[i].rate * time, vNeed - vTaken);
					vTaken += take;
					vt += take * array[i].t;
				}
				assert Math.abs(vTaken - vNeed) < eps;
				res[q] = vt;
			}
			if (res[0] <= vtNeed && vtNeed <= res[1]) {
				high = time;
			} else {
				low = time;
			}
		}
		return String.format("%.8f", high);
	}
	
	class Source implements Comparable<Source> {
		long t, rate;

		public Source(long r, long t) {
			this.t = t;
			this.rate = r;
		}

		@Override
		public int compareTo(Source that) {
			return Long.compare(t, that.t);
		}
	}
	
	public B(Scanner in) {
		n = in.nextInt();
		vNeed = Math.round(in.nextDouble() * 10000);
		tNeed = Math.round(in.nextDouble() * 10000);
		sources = new Source[n];
		for (int i = 0; i < n; i++) {
			sources[i] = new Source(Math.round(in.nextDouble() * 10000), Math.round(in.nextDouble() * 10000));
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
