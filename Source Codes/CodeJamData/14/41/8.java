import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int n;
	int cap;
	int[] s;
	
	String solve() {
		Arrays.sort(s);
		int ans = 0;
		List<Integer> list = new ArrayList<>();
		for (int x : s) {
			list.add(x);
		}
		while (!list.isEmpty()) {
			ans++;
			int x = list.get(list.size() - 1);
			list.remove(list.size() - 1);
			int i = -1;
			while (i + 1 < list.size() && x + list.get(i + 1) <= cap) {
				i++;
			}
			if (i >= 0) {
				list.remove(i);
			}
		}
		return "" + ans;
	}
	
	public A(Scanner in) {
		n = in.nextInt();
		cap = in.nextInt();
		s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
		}
	}
	
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
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
			final A testCase = new A(in);
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
