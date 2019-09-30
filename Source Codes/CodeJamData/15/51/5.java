import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {
	int n;
	int diff;
	int s0, as, cs, rs, m0, am, cm, rm;
	int[] s;
	int[] c;
	ArrayList<Integer>[] kids;
	
	String solve() {
		s = new int[n];
		int[] m = new int[n];
		s[0] = s0;
		m[0] = m0;
		for (int i = 1; i < n; i++) {
			s[i] = (int) ((s[i - 1] * 1L * as + cs) % rs);
			m[i] = (int) ((m[i - 1] * 1L * am + cm) % rm);
		}
		m[0] = -1;
		for (int i = 1; i < n; i++) {
			m[i] %= i;
		}
		kids = new ArrayList[n];
		int maxS = 0;
		for (int i = 0; i < n; i++) {
			kids[i] = new ArrayList<Integer>();
			maxS = Math.max(maxS, s[i]);
		}
		for (int i = 1; i < n; i++) {
			kids[m[i]].add(i);
		}
		c = new int[maxS + diff + 2];
		dfs(0, maxS, 0);
		int count = 0;
		int ans = 0;
		for (int i = 0; i < c.length; i++) {
			count += c[i];
			if (s[0] <= i && i <= s[0] + diff) {
				ans = Math.max(ans, count);
			}
		}
		return "" + ans;
	}
	
	void dfs(int v, int minAncestor, int maxAncestor) {
		int min = Math.min(minAncestor, s[v]);
		int max = Math.max(maxAncestor, s[v]);
		int sMin = max;
		int sMax = min + diff;
		if (sMin <= sMax) {
			c[sMin]++;
			c[sMax + 1]--;
		}
		for (int u : kids[v]) {
			dfs(u, min, max);
		}
	}

	public A(Scanner in) {
		n = in.nextInt();
		diff = in.nextInt();
		s0 = in.nextInt();
		as = in.nextInt();
		cs = in.nextInt();
		rs = in.nextInt();
		m0 = in.nextInt();
		am = in.nextInt();
		cm = in.nextInt();
		rm = in.nextInt();
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
		
		String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final A testCase = new A(in);
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
