package gcj2016.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/q/ExoB/";
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
			Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		String in = sc.next();
		System.out.println(in);

		int i = count(in, in.length(), '+');
		pw.print(i);
	}

	private static int count(final String in, final int length, final char c) {
		if (length == 0) {
			return 0;
		}
		if (in.charAt(length - 1) == c) {
			return count(in, length - 1, c);
		} else {
			return 1 + count(in, length - 1, c == '+' ? '-' : '+');
		}
	}

}
