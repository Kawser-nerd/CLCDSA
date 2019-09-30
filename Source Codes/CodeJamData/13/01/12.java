import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemA {

	static final String XWON = "X won";
	static final String OWON = "O won";
	static final String YET = "Game has not completed";
	static final String DRAW = "Draw";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			char[][] board = new char[4][4];
			for (int y = 0 ; y < 4 ; y++) {
				board[y] = in.next().toCharArray();
			}
			out.println(String.format("Case #%d: %s", cn, solve(board)));
		}
		out.flush();
	}

	
	private static String solve(char[][] board) {
		List<char[]> checkList = new ArrayList<char[]>();
		for (int y = 0 ; y < 4 ; y++) {
			checkList.add(new char[]{board[y][0], board[y][1], board[y][2], board[y][3]});
			checkList.add(new char[]{board[0][y], board[1][y], board[2][y], board[3][y]});
		}
		checkList.add(new char[]{board[0][0], board[1][1], board[2][2], board[3][3]});
		checkList.add(new char[]{board[3][0], board[2][1], board[1][2], board[0][3]});
		for (char[] cl : checkList) {
			String e = evaluate(cl);
			if (!"".equals(e)) {
				return e;
			}
		}
		int dots = 0;
		for (int y = 0 ; y < 4 ; y++) {
			for (int x = 0 ; x < 4 ; x++) {
				dots += (board[y][x] == '.') ? 1 : 0;
			}
		}
		return (dots >= 1) ? YET : DRAW;
	}


	private static String evaluate(char[] cl) {
		int x = 0, o = 0, t = 0;
		for (int i = 0 ; i < cl.length ; i++) {
			if (cl[i] == 'X') {
				x++;
			} else if (cl[i] == 'O') {
				o++;
			} else if (cl[i] == 'T') {
				t++;
			}
		}
		if (x == 4 || (x == 3 && t == 1)) {
			return XWON;
		}
		if (o == 4 || (o == 3 && t == 1)) {
			return OWON;
		}
		return "";
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
