import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	int wid, hei, m;
	int[] x0, y0, x1, y1;
	
	String solve() {
		m += 2;
		x0 = Arrays.copyOf(x0, m);
		y0 = Arrays.copyOf(y0, m);
		x1 = Arrays.copyOf(x1, m);
		y1 = Arrays.copyOf(y1, m);
		x0[m - 2] = -1;
		x1[m - 2] = -1;
		y0[m - 2] = 0;
		y1[m - 2] = hei - 1;
		x0[m - 1] = wid;
		x1[m - 1] = wid;
		y0[m - 1] = 0;
		y1[m - 1] = hei - 1;
		int[] dist = new int[m];
		boolean[] mark = new boolean[m];
		int inf = wid + 10;
		Arrays.fill(dist, inf);
		dist[m - 2] = 0;
		for (;;) {
			int v = -1;
			for (int i = 0; i < m; i++) {
				if (mark[i]) {
					continue;
				}
				if (v == -1 || dist[i] < dist[v]) {
					v = i;
				}
			}
			if (v == -1) {
				break;
			}
			mark[v] = true;
			for (int i = 0; i < m; i++) {
				if (mark[i]) {
					continue;
				}
				int xd = dist(x0[v], x1[v], x0[i], x1[i]);
				int yd = dist(y0[v], y1[v], y0[i], y1[i]);
				int cur = Math.max(xd, yd);
				if (dist[v] + cur < dist[i]) {
					dist[i] = dist[v] + cur;
				}
			}
		}
		return "" + dist[m - 1];
	}
	
	private int dist(int x0, int x1, int x2, int x3) {
		if (x2 > x1) {
			return x2 - x1 - 1;
		}
		if (x0 > x3) {
			return x0 - x3 - 1;
		}
		return 0;
	}

	public C(Scanner in) {
		wid = in.nextInt();
		hei = in.nextInt();
		m = in.nextInt();
		x0 = new int[m];
		y0 = new int[m];
		x1 = new int[m];
		y1 = new int[m];
		for (int i = 0; i < m; i++) {
			x0[i] = in.nextInt();
			y0[i] = in.nextInt();
			x1[i] = in.nextInt();
			y1[i] = in.nextInt();
		}
	}
	
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	
	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(4);
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final C testCase = new C(in);
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					return testCase.solve();
				}
			});
		}
		for (int t = 0; t < tests; t++) {
			out.println("Case #" + (t + 1) + ": " + outputs[t].get());
		}
		in.close();
		out.close();
		executor.shutdown();
	}
}
