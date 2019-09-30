import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class C {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "C";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "F:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.println("Case #" + t + ":");

			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();

			char[][] grid = new char[R][C];
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					grid[i][j] = '*';
				}
			}

			int empty = R * C - M;
			if (R == 1 || C == 1 || empty == 1) {
				int row = 0;
				int col = 0;
				for (int i = 0; i < empty; i++) {
					grid[row][col] = '.';

					col++;
					if (col == C) {
						row++;
						col = 0;
					}
				}

				grid[0][0] = 'c';
				output(out, grid);
			} else if (empty == 2 || empty == 3 || empty == 5 || empty == 7) {
				out.println("Impossible");
			} else if ((R == 2 || C == 2) && empty % 2 != 0) {
				out.println("Impossible");
			} else {
				grid[0][0] = '.';
				grid[0][1] = '.';
				grid[1][0] = '.';
				grid[1][1] = '.';

				if (empty > 4) {
					int remain = empty - 4;
					int col = 2;
					if (C > 2) {
						grid[0][2] = '.';
						grid[1][2] = '.';

						remain -= 2;
						col++;
					}

					int row = 2;
					while (remain >= 2 && row < R) {
						grid[row][0] = '.';
						grid[row][1] = '.';

						remain -= 2;
						row++;
					}

					while (remain >= 2 && col < C) {
						grid[0][col] = '.';
						grid[1][col] = '.';

						remain -= 2;
						col++;
					}

					row = 2;
					col = 2;
					for (int i = 0; i < remain; i++) {
						grid[row][col] = '.';

						row++;
						if (row == R) {
							row = 2;
							col++;
						}
					}
				}

				grid[0][0] = 'c';
				output(out, grid);
			}
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static void output(PrintStream out, char[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				out.print(grid[i][j]);
			}
			out.println();
		}
	}
}
