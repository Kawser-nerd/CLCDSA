import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class D_Large {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "D";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int omino = in.nextInt();
			int row = in.nextInt();
			int col = in.nextInt();

			boolean firstPlayerWin;
			if (row * col % omino != 0) {
				firstPlayerWin = true;
			} else {
				int minSide = Math.min(row, col);
				int maxSide = Math.max(row, col);

				if (omino == 1) {
					firstPlayerWin = false;
				} else if (omino == 2) {
					firstPlayerWin = false;
				} else if (omino == 3) {
					if (minSide == 1) {
						firstPlayerWin = true;
					} else {
						firstPlayerWin = false;
					}
				} else if (omino == 4) {
					if (minSide <= 2) {
						firstPlayerWin = true;
					} else {
						firstPlayerWin = false;
					}
				} else if (omino == 5) {
					if (minSide <= 2) {
						firstPlayerWin = true;
					} else if (minSide == 3) {
						if (maxSide == 5) {
							firstPlayerWin = true;
						} else {
							firstPlayerWin = false;
						}
					} else {
						firstPlayerWin = false;
					}
				} else if (omino == 6) {
					if (minSide <= 2) {
						firstPlayerWin = true;
					} else if (minSide == 3) {
						firstPlayerWin = true;
					} else {
						firstPlayerWin = false;
					}
				} else { // omino >= 7
					firstPlayerWin = true;
				}
			}
			out.println(firstPlayerWin ? "RICHARD" : "GABRIEL");
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}
}
