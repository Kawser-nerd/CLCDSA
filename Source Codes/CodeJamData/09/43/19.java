import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;

public class C {
	static int maxMatching(boolean[][] d) {
		int n1 = d.length;
		int n2 = n1 == 0 ? 0 : d[0].length;
		int[] matching = new int[n2];
		fill(matching, -1);
		int matches = 0;
		for (int u = 0; u < n1; u++) {
			boolean[] vis = new boolean[n1];
			if (findPath(u, d, matching, vis)) {
				matches++;
			}
		}
		return matches;
	}

	static boolean findPath(int u, boolean[][] d, int[] matching, boolean[] vis) {
		if (!vis[u]) {
			vis[u] = true;
			for (int v = 0; v < matching.length; ++v) {
				if (d[u][v] && (matching[v] == -1 || findPath(matching[v], d, matching, vis))) {
					matching[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		String name = "C-large";
		String path = "C:/codejam/";
		Scanner sc = new Scanner(new File(path + name + ".in"));
		PrintWriter pw = new PrintWriter(path + name + ".out");
		int testCases = sc.nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			int n = sc.nextInt();
			int k = sc.nextInt();

			int[][] prices = new int[n][k];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					prices[i][j] = sc.nextInt();
				}
			}

			boolean[][] d = new boolean[n][n];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					boolean ok = true;
					for (int p = 0; p < k; p++) {
						if (prices[i][p] <= prices[j][p]) {
							ok = false;
							break;
						}
					}
					if (ok) {
						d[i][j] = true;
					}
				}
			}

			int res = n - maxMatching(d);

			pw.println("Case #" + testCase + ": " + res);
			pw.flush();
		}
		pw.close();
	}
}
