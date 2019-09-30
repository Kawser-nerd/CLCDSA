import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemC {

	
	static final String IMP = "Impossible";
	
	static final int[] DX = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	static final int[] DY = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			out.println(String.format("Case #%d:", cn));
			String[] res1 = solve(R, C, M);
			if (res1 != null) {
				for (String r : res1) {
					out.println(r);
				}
			} else {
				String[] res2 = solve(C, R, M);
				if (res2 != null) {
					for (String r : rotate(res2)) {
						out.println(r);
					}
				} else {
					out.println(IMP);
				}
			}
		}
		out.flush();
	}


	private static String[] solve(int r, int c, int m) {
		int empty = r * c - m;
		if (empty == 1) {
			boolean[][] mines = new boolean[r][c];
			for (int i = 0 ; i < r ; i++) {
				Arrays.fill(mines[i], true);
			}
			mines[0][0] = false;
			return convert(mines, 0, 0);
		}

		boolean[][][] dp = new boolean[c+1][r+1][m+1];
		int[][][][] prev = new int[c+1][r+1][m+1][4];
		for (int i = 0 ; i <= r ; i++) {
			dp[0][i][0] = true;
		}
		for (int i = 0 ; i < c; i++) {
			for (int j = 0 ; j <= r ; j++) {
				for (int k = 0 ; k <= m ; k++) {
					if (dp[i][j][k]) {
						for (int next = j ; next >= 0 ; next--) {
							if (i == c-1 && next != j) {
								continue;
							}
							if (k+next <= m && next != r-1) {
								dp[i+1][next][k+next] = true;
								prev[i+1][next][k+next][0] = i;
								prev[i+1][next][k+next][1] = j;
								prev[i+1][next][k+next][2] = k;
								prev[i+1][next][k+next][3] = next;
							}
						}
					}
				}
			}
		}
		for (int i = 0 ; i <= r ; i++) {
			if (dp[c][i][m]) {
				boolean[][] mines = new boolean[r][c];
				int nowC = c;
				int nowR = i;
				int nowM = m;
				while (nowC >= 1) {
					int tc = prev[nowC][nowR][nowM][0];
					int tr = prev[nowC][nowR][nowM][1];
					int tm = prev[nowC][nowR][nowM][2];
					int used = prev[nowC][nowR][nowM][3];
					int kr = r;
					while (used >= 1) {
						kr--;
						used--;
						mines[kr][nowC-1] = true;
					}
					nowC = tc;
					nowR = tr;
					nowM = tm;
				}
				return convert(mines, 0, c-1);
			}
		}
		return null;
	}
	
	public static String[] convert(boolean[][] a, int fi, int fj) {
		int r = a.length;
		int c = a[0].length;
		String[] ret = new String[r];
		for (int i = 0 ; i < r ; i++) {
			StringBuilder builder = new StringBuilder();
			for (int j = 0 ; j < c ; j++) {
				if (fi == i && fj == j) {
					builder.append('c');
				} else if (a[i][j]) {
					builder.append('*');
				} else {
					builder.append('.');
				}
			}
			ret[i] = builder.toString();
		}
		return ret;
	}
	

	public static String[] rotate(String[] a) {
		int r = a.length;
		int c = a[0].length();
		String[] ret = new String[c];
		for (int i = 0 ; i < c ; i++) {
			StringBuilder builder = new StringBuilder();
			for (int j = 0 ; j < r ; j++) {
				builder.append(a[j].charAt(i));
			}
			ret[i] = builder.toString();
		}
		return ret;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
