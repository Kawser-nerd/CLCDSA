import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	long x;
	String sSingle;
	
	static int[][] mult = new int[][] {
		new int[] {0, 1, 2, 3},
		new int[] {1, 4, 3, 6},
		new int[] {2, 7, 4, 1},
		new int[] {3, 2, 5, 4},
	};
	
	int mult(int a, int b) {
		boolean minus = false;
		if (a >= 4) {
			a -= 4;
			minus ^= true;
		}
		if (b >= 4) {
			b -= 4;
			minus ^= true;
		}
		int result = mult[a][b];
		if (minus) {
			result ^= 4;
		}
		return result;
	}
	
	String solve() {
		if (x > 24) {
			x = x % 4 + 24;
		}
		String s = "";
		for (int i = 0; i < x; i++) {
			s += sSingle;
		}
		int poss = 1;
		for (int i = 0; i < s.length(); i++) {
			int c = s.charAt(i) - 'i' + 1;
			int possNew = 0;
			for (int j = 0; j < 24; j++) {
				if ((poss & (1 << j)) == 0) {
					continue;
				}
				int k = j / 8;
				int v = j % 8;
				int u = mult(v, c);
				possNew |= 1 << (8 * k + u);
				if (k < 2 && u == k + 1) {
					possNew |= 1 << (8 * (k + 1));
				}
			}
			poss = possNew;
		}
		return (poss & (1 << (8 * 2 + 3))) != 0 ? "YES" : "NO";
	}
	
	public C(Scanner in) {
		in.nextInt();
		x = in.nextLong();
		sSingle = in.next();
	}
	
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
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
			final C testCase = new C(in);
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
