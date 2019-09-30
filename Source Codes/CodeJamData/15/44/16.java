import java.io.File;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class D {

	private static final List<int[][]> arrays = new LinkedList<int[][]>();

	private static boolean equalArray(int[][] array1, int[][] array2, int r,
			int c) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (array1[i][j] != array2[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	private static void addIfNotExist(int[][] drum, int r, int c) {
		boolean exists = false;
		int[][] rotated = new int[r][c];

		for (int rotate = 1; rotate <= c; rotate++) {

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					int j1 = j + rotate;
					if (j1 >= c) {
						j1 -= c;
					}
					rotated[i][j1] = drum[i][j];

				}
			}

			for (int[][] other : arrays) {
				if (equalArray(rotated, other, r, c)) {
					exists = true;
					break;
				}
			}
			if (exists) {
				break;
			}
		}
		if (!exists) {
			arrays.add(rotated);
		}
	}

	private static boolean checkRow(int row, int[][] drum, int r, int c) {
		for (int j = 0; j < c; j++) {
			int number = drum[row][j];
			int k = 0;

			if (row > 0 && drum[row - 1][j] == number) {
				k++;
			}

			if (row < r - 1 && drum[row + 1][j] == number) {
				k++;
			}

			if (j > 0 && drum[row][j - 1] == number) {
				k++;
			}

			if (j == 0 && drum[row][c - 1] == number) {
				k++;
			}

			if (j < c - 1 && drum[row][j + 1] == number) {
				k++;
			}

			if (j == c - 1 && drum[row][0] == number) {
				k++;
			}

			if (k != number) {
				return false;
			}
		}
		return true;
	}

	private static void fillNumber(int i, int j, int r, int c, int[][] drum) {
		if (i == r) {
			if (checkRow(i - 2, drum, r, c) && checkRow(i - 1, drum, r, c)) {
				addIfNotExist(drum, r, c);
			}
			return;
		}

		if (j == c) {
			if (i > 1 && !checkRow(i - 2, drum, r, c)) {
				return;
			}
			fillNumber(i + 1, 0, r, c, drum);
			return;
		}

		for (int number = 1; number <= 3; number++) {
			drum[i][j] = number;
			fillNumber(i, j + 1, r, c, drum);
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int r = in.nextInt();
			int c = in.nextInt();

			arrays.clear();

			fillNumber(0, 0, r, c, new int[r][c]);

			out.println("Case #" + test + ": " + arrays.size());
		}

		in.close();
		out.close();
	}

}
