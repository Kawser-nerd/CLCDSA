import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*

??D
?A?
CA?
*/
public class a {
	static final int STDIO = 0, SMALL = 1, LARGE = 2;
	static int inType = STDIO;
	static int outType = LARGE;

	public static void main(String[] args) throws IOException {
		Scanner in = getScanner();
		PrintWriter out = getPrintWriter();
		int maxT = in.nextInt();
		for (int curT = 1; curT <= maxT; curT++) {
			int R = in.nextInt(), C = in.nextInt();
			char[][] grid = new char[R][C];
			for (int i = 0; i < R; i++) {
				String s = in.next();
				for (int j = 0; j < C; j++) {
					grid[i][j] = s.charAt(j);
				}
			}
			for (int i = 0; i < R; i++) {
				char cur = '?';
				for (int j = 0; j < C; j++) {
					if (grid[i][j] != '?')
						cur = grid[i][j];
					grid[i][j] = cur;
				}
			}
			for (int i = 0; i < R; i++) {
				char cur = '?';
				for (int j = C - 1; j >= 0; j--) {
					if (grid[i][j] != '?')
						cur = grid[i][j];
					grid[i][j] = cur;
				}
			}
			for (int j = 0; j < C; j++) {
				char cur = '?';
				for (int i = 0; i < R; i++) {
					if (grid[i][j] != '?')
						cur = grid[i][j];
					grid[i][j] = cur;
				}
			}
			for (int j = 0; j < C; j++) {
				char cur = '?';
				for (int i = R-1; i >=0; i--) {
					if (grid[i][j] != '?')
						cur = grid[i][j];
					grid[i][j] = cur;
				}
			}
			out.printf("Case #%d: ", curT);
			out.println();
			for(int i=0;i<R;i++)
				out.println(new String(grid[i]));

			//// OUTPUT

			if (inType != STDIO)
				System.out.println(curT + "/" + maxT);
		}

		out.close();
	}

	static final String PROBLEM_LETTER = "A";

	static Scanner getScanner() throws IOException {
		if (outType != STDIO)
			inType = outType;
		if (inType == SMALL)
			return new Scanner(new File(PROBLEM_LETTER + "-small-attempt0.in"));
		else if (inType == LARGE)
			return new Scanner(new File(PROBLEM_LETTER + "-large.in"));
		return new Scanner(System.in);
	}

	static PrintWriter getPrintWriter() throws IOException {
		if (outType == SMALL) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-SMALL");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-small.out"));
		} else if (outType == LARGE) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-LARGE");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-large.out"));
		}
		return new PrintWriter(System.out);
	}
}
