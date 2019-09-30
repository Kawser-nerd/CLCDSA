package gcj.y2017.qual;
import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {
	static final String SIGNS = ".x+o";
	
	int n, m;
	int[] types, xs, ys;

	String solve() {
		boolean[][][] out = new boolean[2][2 * n - 1][2 * n - 1];
		int[][] orig = new int[n][n];
		int[][] set = new int[n][n];
		for (int i = 0; i < m; i++) {
			int type = types[i];
			int x = xs[i];
			int y = ys[i];
			orig[x][y] = type;
			if ((type & 1) != 0) {
				out[0][x][y] = true;
			}
			if ((type & 2) != 0) {
				out[1][x + y][x - y + n - 1] = true;
			}
		}
		for (int t = 0; t < 2; t++) {
			e = new boolean[2 * n - 1][2 * n - 1];
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (t == 0) {
						e[x][y] = true;
					} else {
						e[x + y][x - y + n - 1] = true;
					}
				}
			}
			boolean[] outI = new boolean[e.length];
			boolean[] outJ = new boolean[e.length];
			for (int i = 0; i < e.length; i++) {
				for (int j = 0; j < e.length; j++) {
					if (out[t][i][j]) {
						outI[i] = true;
						outJ[j] = true;
					}
				}				
			}
			for (int i = 0; i < e.length; i++) {
				for (int j = 0; j < e.length; j++) {
					if (outI[i] || outJ[j]) {
						e[i][j] = false;
					}
				}
			}
			matching();
			for (int j = 0; j < e.length; j++) {
				int i = left[j];
				if (i == -1) {
					continue;
				}
				if (t == 0) {
					set[i][j] |= 1;
				} else {
					System.out.println(i + " " + j);
					set[(i + (j + 1 - n)) / 2][(i - (j + 1 - n)) / 2] |= 2;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		int score = 0, added = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int v = orig[i][j] | set[i][j];
				score += Integer.bitCount(v);
				if (set[i][j] == 0) {
					continue;
				}
				sb.append("\n" + SIGNS.charAt(v) + " " + (i + 1) + " " + (j + 1));
				added++;
			}
		}
		return score + " " + added + sb.toString();
	}
	
	public D(Scanner in) {
		n = in.nextInt();
		m = in.nextInt();
		types = new int[m];
		xs = new int[m];
		ys = new int[m];
		for (int i = 0; i < m; i++) {
			types[i] = SIGNS.indexOf(in.next().charAt(0));
			xs[i] = in.nextInt() - 1;
			ys[i] = in.nextInt() - 1;
		}
	}
	
	boolean[][] e;
	
	boolean[] mark;
	int[] left;

	int matching() {
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

	boolean dfs(int i) {
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
	
	public static void main(String[] args) throws Exception {
		int nThreads = 1;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
//		/* "IPSC" */
//		String fileNameSuffix = "0";
//		String formatOut = "%s";
//		String formatSystemOut = "Case #%2$d solved.";//"Case #%2$d: %1$s";
		
		String fileName = D.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
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
			final D testCase = new D(in);
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
