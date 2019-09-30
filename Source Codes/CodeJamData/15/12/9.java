import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int b, n;
	int[] a;
	int which;
	
	boolean inTime(long time, boolean last) {
		List<Integer> free = new ArrayList<>();
		long prevFree = 0;
		for (int i = 0; i < b; i++) {
			prevFree += (time + a[i] - 1) / a[i];
			if (time % a[i] == 0) {
				free.add(i);
			}
		}
		if (last) {
			which = free.get((int) (n - prevFree));
		}
		return n < prevFree + free.size();
	}
	
	String solve() {
		n--;
		long low = -1;
		long high = a[0] * 1L * (n + 1);
		while (low + 1 < high) {
			long mid = (low + high) / 2;
			if (inTime(mid, false)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		inTime(high, true);
		return "" + (which + 1);
	}
	
	public B(Scanner in) {
		b = in.nextInt();
		n = in.nextInt();
		a = new int[b];
		for (int i = 0; i < b; i++) {
			a[i] = in.nextInt();
		}
	}
	
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	
	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(4);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final B testCase = new B(in);
			final int testCaseNumber = t;
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					String printed = "Case #" + (testCaseNumber + 1) + ": " + answer;
					System.out.println(printed);
					return printed;
				}
			});
		}
		for (int t = 0; t < tests; t++) {
			out.println(outputs[t].get());
		}
		in.close();
		out.close();
		executor.shutdown();
	}
}
