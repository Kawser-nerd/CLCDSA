import java.io.*;
import java.util.*;

public class C implements Runnable {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	boolean[][] e;
	boolean[] mark;
	int[] left;

	private void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[][] a = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				a[i][j] = in.nextInt();
			}
		}
		e = new boolean[n][n];
		mark = new boolean[n];
		left = new int[n];
		Arrays.fill(left, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				e[i][j] = true;
				for (int t = 0; t < k; t++) {
					if (a[i][t] <= a[j][t]) {
						e[i][j] = false;
						break;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			Arrays.fill(mark, false);
			if (dfs(i)) {
				ans++;
			}
		}
		out.println(n - ans);
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
			if (left[j] == -1) {
				left[j] = i;
				return true;
			}
			if (dfs(left[j])) {
				left[j] = i;
				return true;
			}
		}
		return false;
	}

	public void run() {
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			solve();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		Thread thread = new Thread(new C());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
