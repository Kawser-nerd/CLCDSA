import java.io.*;
import java.util.*;

public class A {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.println("Case #" + testCase + ": " + solveOneTest());
		}
	}

	static String solveOneTest() throws IOException {
		char[][] board = new char[4][];
		for (int i = 0; i < 4; i++) {
			board[i] = nextToken().toCharArray();
		}
		boolean firstWon = won(board, 'X');
		boolean secondWon = won(board, 'O');
		if (firstWon && secondWon) {
			throw new AssertionError();
		}
		if (firstWon) {
			return "X won";
		}
		if (secondWon) {
			return "O won";
		}
		if (gridIsFilled(board)) {
			return "Draw";
		} else {
			return "Game has not completed";
		}
	}

	private static boolean gridIsFilled(char[][] board) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == '.') {
					return false;
				}
			}
		}
		return true;
	}

	static int[] DX = { 0, 1, 1, 1 };
	static int[] DY = { 1, 0, 1, -1 };

	private static boolean won(char[][] board, char c) {
		for (int startI = 0; startI < 4; startI++) {
			for (int startJ = 0; startJ < 4; startJ++) {
				for (int direction = 0; direction < DX.length; direction++) {
					int i = startI, j = startJ;
					int ok = 0;
					while (i < 4 && i >= 0 && j < 4 && j >= 0
							&& (board[i][j] == c || board[i][j] == 'T')) {
						ok++;
						i += DX[direction];
						j += DY[direction];
					}
					if (ok == 4) {
						return true;
					}
				}
			}
		}
		return false;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("a.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
