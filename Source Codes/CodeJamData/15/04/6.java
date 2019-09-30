package gcj2015.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoD {
	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/q/ExoD/";
		final String input = base + "b1.in";
		final String output = base + "b1.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test(sc, pw);
				pw.println();
			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (final FileNotFoundException ex) {
			Logger.getLogger(ExoD.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		final int X = sc.nextInt();
		final int R = sc.nextInt();
		final int C = sc.nextInt();

		if (X >= 7 || (R * C) % X != 0) {
			pw.print("RICHARD");
		} else {
			if (X == 1 || X == 2 || (X == 3 && (R != 1 && C != 1)) || (X == 4 && (R >= 4 && C > 2 || C >= 4 && R > 2))
					|| (X == 5 && ((R >= 4 && C >= 4) || (R == 3 && C >= 10 || R >= 10 && C == 3)))
					|| (X == 6 && (R >= 4 && C >= 4 && (R >= 6 || C >= 6)))) {
				pw.print("GABRIEL");
			} else {
				pw.print("RICHARD");
			}

		}
	}
}
