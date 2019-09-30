package gcj2015.r1b;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoC {

	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/1b/ExoC/";
		final String input = base + "s1.in";
		final String output = base + "s1.out";

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
			Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		final int N = sc.nextInt();
		if (N == 1) {
			final int D = sc.nextInt();
			final int H = sc.nextInt();
			final int M = sc.nextInt();
			if (H == 1) {
				pw.print(0);
			} else {
				pw.print(solve(D, M, D, M + 1));
			}
		} else if (N == 2) {
			final int D = sc.nextInt();
			final int H = sc.nextInt();
			final int M = sc.nextInt();
			final int D2 = sc.nextInt();
			final int H2 = sc.nextInt();
			final int M2 = sc.nextInt();
			pw.print(solve(D, M, D2, M2));
		}

	}

	private static int solve(final int d, final int m, final int d2, final int m2) {
		if (m == m2)
			return 0;
		if (m2 < m) {
			return solve(d2, m2, d, m);
		}
		double t1 = (360. - d2) / 360. * m2;
		double t2;
		if (d >= d2) {
			t2 = (360. - (d - d2)) / ((360. / m) - (360. / m2));
		} else {
			t2 = (360. + (d2 - d)) / ((360. / m) - (360. / m2));
		}
		System.out.println(t1 + "-" + t2);
		if (t1 < t2) {
			return 0;
		} else {
			return 1;
		}
	}

}
