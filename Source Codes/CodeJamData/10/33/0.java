import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int hei = in.nextInt();
		int wid = in.nextInt();
		boolean[][] a = new boolean[hei][wid];
		boolean[][] used = new boolean[hei][wid];
		boolean[][] ok = new boolean[hei][wid];
		for (int i = 0; i < hei; i++) {
			String s = in.next();
			for (int j = 0; j < wid / 4; j++) {
				int t = Integer.parseInt(s.substring(j, j + 1), 16);
				for (int k = 0; k < 4; k++) {
					a[i][4 * j + k] = (t & (1 << (3 - k))) > 0;
				}
			}
		}
		for (int i = hei - 1; i >= 0; i--) {
			for (int j = wid - 1; j >= 0; j--) {
				if (i + 1 == hei || j + 1 == wid) {
					continue;
				}
				if ((a[i][j + 1] != a[i][j]) && (a[i + 1][j] != a[i][j]) && (a[i + 1][j + 1] == a[i][j])) {
					ok[i][j] = true;
				}
			}
		}
		int[][] max = new int[hei][wid];
		int ans = 0;
		StringBuilder answer = new StringBuilder();
		for (int size = Math.min(hei, wid); size >= 1; size--) {
			for (int i = hei - 1; i >= 0; i--) {
				for (int j = wid - 1; j >= 0; j--) {
					if (used[i][j]) {
						max[i][j] = 0;
						continue;
					}
					if (ok[i][j]) {
						max[i][j] = 1 + Math.min(max[i + 1][j], Math.min(max[i][j + 1], max[i + 1][j + 1]));
					} else {
						max[i][j] = 1;
					}
				}
			}
			int count = 0;
			for (int i = 0; i < hei; i++) {
				for (int j = 0; j < wid; j++) {
					if (max[i][j] >= size) {
						count++;
						for (int ii = 0; ii < size; ii++) {
							for (int jj = 0; jj < size; jj++) {
								used[i + ii][j + jj] = true;
							}
						}
						for (int ii = 0; ii < size; ii++) {
							for (int jj = Math.max(1 - size, -j); jj < size; jj++) {
								max[i + ii][j + jj] = 0;
							}
						}
					}
				}
			}
			if (count > 0) {
				ans++;
				answer.append(size + " " + count + "\n");
			}
		}
		out.println(ans);
		out.print(answer);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
		}
		in.close();
		out.close();
	}
}
