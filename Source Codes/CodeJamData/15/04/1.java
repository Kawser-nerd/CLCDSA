import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {
	int x, hei, wid;
	
	boolean solve() {
		if (hei > wid) {
			int t = hei;
			hei = wid;
			wid = t;
		}
		if (x >= 7) {
			return true;
		}
		if (hei * wid % x != 0) {
			return true;
		}
		if (x >= hei * 2 + 1) {
			return true;
		}
		if (x >= wid + 1) {
			return true;
		}
		if (x < 4) {
			return false;
		}
		if (x == 4) {
			if (hei == 2) {
				return true;
			}
			return false;
		}
		if (x == 5) {
			if (hei == 3) {
				if (wid == 5) {
					return true;
				}
			}
			return false;
		}
		if (hei == 3) {
			return true;
		}
		return false;
	}
	
	public D(Scanner in) {
		x = in.nextInt();
		hei = in.nextInt();
		wid = in.nextInt();
	}
	
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
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
			final D testCase = new D(in);
			final int testCaseNumber = t;
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve() ? "RICHARD" : "GABRIEL";
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
