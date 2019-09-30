import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	String solve() {
		int ans = 1;
		for (int r = 0; r < n; r++) {
			ans = Math.max(ans, dfs(r, -1));
		}
		return n - ans + "";
	}
	
	int dfs(int v, int p) {
		List<Integer> kids = new ArrayList<>();
		for (int u : nei.get(v)) {
			if (u == p) {
				continue;
			}
			kids.add(dfs(u, v));
		}
		if (kids.size() < 2) {
			return 1;
		}
		Collections.sort(kids);
		Collections.reverse(kids);
		return kids.get(0) + kids.get(1) + 1;
	}

	int n;
	ArrayList<ArrayList<Integer>> nei;
	
	public B(Scanner in) {
		n = in.nextInt();
		nei = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			nei.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < n - 1; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			nei.get(a).add(b);
			nei.get(b).add(a);
		}
	}
	
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
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
			final B testCase = new B(in);
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
