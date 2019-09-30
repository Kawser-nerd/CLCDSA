import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Iskander Akishev
 */
public class Digging {

	private final static String FILE_NAME = "B-large";
	
	private static final int INF = 1000000;
	private static boolean[][] free;
	private static int n, m, f;
	private static int[][][] a;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		PrintWriter out = new PrintWriter(new File(FILE_NAME + ".out"));

		int numberOfTests = Integer.parseInt(in.readLine().trim());

		for (int caseNum = 1; caseNum <= numberOfTests; caseNum++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			f = Integer.parseInt(st.nextToken());
			free = new boolean[n][m + 2];
			a = new int[n][m + 2][m + 2];
			for (int i = 0; i < n; i++) {
				for (int[] aaa : a[i])
					Arrays.fill(aaa, INF + 1);
				char[] chars = in.readLine().trim().toCharArray();
				for (int j = 0; j < m; j++) {
					free[i][j + 1] = (chars[j] == '.');
				}
			}
			
			int ans = get(0, 1, 1);
			System.out.println("Case #" + caseNum + ": " + (ans < INF ? ("Yes " + ans) : "No"));
			out.println("Case #" + caseNum + ": " + (ans < INF ? ("Yes " + ans) : "No"));
		}

		in.close();
		out.close();
	}

	private static int get(int i, int j, int k) {
		if (a[i][j][k] == INF + 1)
			getImpl(i, j, k);
		return a[i][j][k];
	}

	private static void getImpl(int i, int j, int k) {
		if (i == n - 1) {
			a[i][j][k] = 0;
			return;
		}

		// fall
		if (free[i + 1][j]) {
			int h = 1;
			int ii = i;
			while ((ii < n - 1) && free[ii + 1][j]) {
				ii++;
				h++;
				if (h > f) {
					a[i][j][k] = INF;
					return;
				}
			}
			a[i][j][k] = get(ii, j, j);
			return;
		}

		int ans = INF;
		
		int lb = j;
		while (
			(free[i][lb - 1] || (lb - 1 >= k)) &&
			(!free[i + 1][lb - 1])
		) lb--;
		int rb = j;
		while (
			(free[i][rb + 1] || (rb + 1 <= k)) &&
			(!free[i + 1][rb + 1])
		) rb++;

		if (free[i][lb - 1] || (lb - 1 >= k))
			ans = Math.min(ans, get(i + 1, lb - 1, lb - 1));
		if (free[i][rb + 1] || (rb + 1 <= k))
			ans = Math.min(ans, get(i + 1, rb + 1, rb + 1));

		for (int ll = lb; ll < rb; ll++) {
			for (int rr = ll + 1; rr <= rb; rr++) {
				ans = Math.min(ans, get(i + 1, ll + 1, rr) + rr - ll);
				ans = Math.min(ans, get(i + 1, rr - 1, ll) + rr - ll);
			}
		}

//		a[i][j][k] = a[i][lb][rb] = a[i][rb][lb] = ans;
		a[i][j][k] = ans;
	}
}