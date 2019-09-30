import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	String solve() {
		Arrays.sort(a);
		Arrays.sort(b);
		boolean[] xor = new boolean[len];
		String[] c = new String[n];
		int ans = len + 1;
		for (int k = 0; k < n; k++) {
			int diff = 0;
			for (int j = 0; j < len; j++) {
				xor[j] = (a[0].charAt(j) == '1') ^ (b[k].charAt(j) == '1');
				diff += xor[j] ? 1 : 0;
			}
			for (int i = 0; i < n; i++) {
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < len; j++) {
					sb.append(((a[i].charAt(j) == '1') ^ xor[j]) ? '1' : '0');
				}
				c[i] = sb.toString();
			}
			Arrays.sort(c);
			if (Arrays.equals(c, b)) {
				ans = Math.min(ans, diff);
			}
		}
		return ans > len ? "NOT POSSIBLE" : "" + ans;
	}
	
	int n, len;
	String[] a, b;
	
	public A(Scanner in) {
		n = in.nextInt();
		len = in.nextInt();
		a = readArray(in);
		b = readArray(in);
	}
	
	String[] readArray(Scanner in) {
		String[] res = new String[n];
		for (int i = 0; i < n; i++) {
			res[i] = in.next();
		}
		return res;
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
