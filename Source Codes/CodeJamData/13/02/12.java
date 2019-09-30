import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemB {

	static final String YES = "YES";
	static final String NO = "NO";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int N = in.nextInt();
			int M = in.nextInt();
			int[][] a = new int[N][M];
			for (int i = 0 ; i < N ; i++) {
				for (int j = 0 ; j < M ; j++) {
					a[i][j] = in.nextInt();
				}
			}
			out.println(String.format("Case #%d: %s", cn, (solve(a) ? YES : NO)));
		}
		out.flush();
	}
	
	private static boolean solve(int[][] board) {
		int N = board.length;
		int M = board[0].length;
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < M ; j++) {
				int a = board[i][j];
				int rmax = 0, cmax = 0;
				for (int x = 0 ; x < M ; x++) {
					if (x != j) {
						rmax = Math.max(rmax, board[i][x]);
					}
				}
				for (int y = 0 ; y < N ; y++) {
					if (y != i) {
						cmax = Math.max(cmax, board[y][j]);
					}
				}
				if (rmax > a && cmax > a) {
					return false;
				}
			}
		}
		return true;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
