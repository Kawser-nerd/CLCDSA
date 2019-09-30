package gcj2016.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoA {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/q/ExoA/";
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
		int N = sc.nextInt();

		if (N == 0) {
			pw.print("INSOMNIA");
			return;
		}

		int i = 0;
		long n = 0;
		boolean digits[] = new boolean[10];

		while (notFull(digits)) {
			i++;
			n += N;
			if (i > 100000 || n < 0) {
				pw.print("INSOMNIA");
				return;
			}
			fillDigits(n, digits);
		}

		pw.print(n);
	}

	private static void fillDigits(long n, final boolean[] digits) {
		while (n > 0) {
			long d = n % 10;
			digits[(int) d] = true;
			n = n / 10;
		}

	}

	private static boolean notFull(final boolean[] digits) {
		for (boolean b : digits) {
			if (!b) {
				return true;
			}
		}
		return false;
	}
}
