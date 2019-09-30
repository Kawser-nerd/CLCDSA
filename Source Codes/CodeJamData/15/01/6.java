package gcj2015.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoA {
	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/q/ExoA/";
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
			Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		final int Smax = sc.nextInt();
		final String levels = sc.next();
		final int[] ls = new int[levels.length()];
		int ts = 0;
		int toAdd = 0;
		for (int i = 0; i < levels.length(); i++) {
			if (ts < i) {
				toAdd += (i - ts);
				ts = i;
			}
			ls[i] = levels.charAt(i) - '0';
			ts += ls[i];
		}
		pw.print(toAdd);

	}
}
