import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemA {

	static final String BAD = "Bad magician!";
	static final String CHEATED = "Volunteer cheated!";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int row1 = in.nextInt()-1;
			int[][] board1 = new int[4][4];
			for (int i = 0 ; i < 4 ; i++) {
				for (int j = 0 ; j < 4 ; j++) {
					board1[i][j] = in.nextInt()-1;
				}
			}
			
			int row2 = in.nextInt()-1;
			int[][] board2 = new int[4][4];
			for (int i = 0 ; i < 4 ; i++) {
				for (int j = 0 ; j < 4 ; j++) {
					board2[i][j] = in.nextInt()-1;
				}
			}
			out.println(String.format("Case #%d: %s", cn, solve(row1, board1, row2, board2)));
		}
		out.flush();
	}

	
	private static String solve(int row1, int[][] board1, int row2, int[][] board2) {
		int ptn1 = 0;
		for (int j = 0 ; j < 4 ; j++) {
			ptn1 |= 1<<board1[row1][j];
		}
		int ptn2 = 0;
		for (int j = 0 ; j < 4 ; j++) {
			ptn2 |= 1<<board2[row2][j];
		}
		
		int ans = ptn1 & ptn2;
		if (ans == 0) {
			return CHEATED;
		} else if (Integer.bitCount(ans) >= 2) {
			return BAD;
		}
		for (int i = 0 ; i < 16 ; i++) {
			if ((ans & (1<<i)) >= 1) {
				return (i+1)+"";
			}
		}
		return CHEATED;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
