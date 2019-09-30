import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class A {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "A";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "F:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int r1 = in.nextInt();
			int[][] rows1 = readRows(in);
			int r2 = in.nextInt();
			int[][] rows2 = readRows(in);

			ArrayList<Integer> results = merge(rows1[r1 - 1], rows2[r2 - 1]);
			if (results.size() == 1) {
				out.println(results.get(0));
			} else if (results.size() > 1) {
				out.println("Bad magician!");
			} else {
				out.println("Volunteer cheated!");
			}
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static int[][] readRows(Scanner in) {
		int[][] rows = new int[4][4];
		for (int i = 0; i < rows.length; i++) {
			for (int j = 0; j < rows[0].length; j++) {
				rows[i][j] = in.nextInt();
			}
		}
		return rows;
	}

	static ArrayList<Integer> merge(int[] a, int[] b) {
		ArrayList<Integer> merged = new ArrayList<Integer>();
		for (int elem1 : a) {
			boolean found = false;
			for (int elem2 : b) {
				if (elem1 == elem2) {
					found = true;
				}
			}
			if (found) {
				merged.add(elem1);
			}
		}
		return merged;
	}
}
