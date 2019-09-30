import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	int n;
	String[] s, t;
	
	String solve() {
		String[] ss = sortedUnique(s);
		String[] tt = sortedUnique(t);
		int a = ss.length;
		int b = tt.length;
		e = new boolean[a][b];
		for (int i = 0; i < n; i++) {
			int x = Arrays.binarySearch(ss, s[i]);
			int y = Arrays.binarySearch(tt, t[i]);
			e[x][y] = true;
		}
		int edgeCover = a + b - matching(); 
		return n - edgeCover + "";
	}
	
	public C(Scanner in) {
		n = in.nextInt();
		s = new String[n];
		t = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
			t[i] = in.next();
		}
	}
	
	public boolean[][] e;
	
	private boolean[] mark;
	private int[] left;
	
	public int matching() {
		mark = new boolean[e.length];
		left = new int[e[0].length];
		Arrays.fill(left, -1);
		int ans = 0;
		for (int i = 0; i < e.length; i++) {
			Arrays.fill(mark, false);
			if (dfs(i)) {
				ans++;
			}
		}
		return ans;
	}

	private boolean dfs(int i) {
		if (mark[i]) {
			return false;
		}
		mark[i] = true;
		for (int j = 0; j < e[i].length; j++) {
			if (!e[i][j]) {
				continue;
			}
			if (left[j] == -1 || dfs(left[j])) {
				left[j] = i;
				return true;
			}
		}
		return false;
	}
	
	static String[] sortedUnique(String[] s) {
		TreeSet<String> treeSet = new TreeSet<String>(Arrays.asList(s));
		return treeSet.toArray(new String[treeSet.size()]);
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
//		/* "IPSC" */
//		String fileNameSuffix = "0";
//		String formatOut = "%s";
//		String formatSystemOut = "Case #%2$d solved.";//"Case #%2$d: %1$s";
		
		String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt(); in.nextLine();//1;
		nThreads = Math.min(nThreads, tests);
		@SuppressWarnings("unchecked")
		Callable<String>[] callables = new Callable[tests];
		for (int t = 0; t < tests; t++) {
			final C testCase = new C(in);
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
