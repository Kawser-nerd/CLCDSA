import java.util.Scanner;

// Google Codejam
// Qualification Round 2013
// Problem A. Tic-Tac-Toe-Tomek

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int tt = scanner.nextInt();
		for (int t = 1; t <= tt; t++) {
			int rows = scanner.nextInt();
			int cols = scanner.nextInt();

			int[] rowmax = new int[rows];
			int[] colmax = new int[cols];
			for (int i = 0; i < rows; i++)
				rowmax[i] = 0;
			for (int j = 0; j < cols; j++)
				colmax[j] = 0;

			int[][] lawn = new int[rows][cols];

			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++) {
					int h = scanner.nextInt();
					lawn[i][j] = h;
					if (h > rowmax[i])
						rowmax[i] = h;
					if (h > colmax[j])
						colmax[j] = h;
				}

			// check
			boolean yes = true;
			for (int i = 0; yes && i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (rowmax[i] > lawn[i][j] && colmax[j] > lawn[i][j]) {
						yes = false;
						break;
					}

			// output
			if (yes)
				System.out.printf("Case #%d: YES\n", t);
			else
				System.out.printf("Case #%d: NO\n", t);
		}
	}

}
