package gcj2015.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoC {

	public static final int U = 1;
	public static final int I = 2;
	public static final int J = 3;
	public static final int K = 4;

	public static int[][] quaternions = new int[][] {
			{ U, I, J, K },
			{ I, -U, K, -J },
			{ J, -K, -U, I },
			{ K, J, -I, -U } };

	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/q/ExoC/";
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
			Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		final int L = sc.nextInt();
		final long X = sc.nextLong();
		String s = sc.next();
		String ss = "";

		if (X < 16) {
			for (int i = 0; i < X; i++) {
				ss = ss + s;
			}
		} else {
			for (int i = 0; i < ((X % 4) + 12); i++) {
				ss = ss + s;
			}
		}

		if (check(ss)) {
			pw.print("YES");
		} else {
			pw.print("NO");
		}
	}

	private static boolean check(final String s) {
		int res = U;
		int search = I;
		for (int i = 0; i < s.length(); i++) {
			int q = (s.charAt(i) - 'i') + I;
			res = multiply(res, q);
			if (res == search) {
				search++;
				res = U;
			}
		}
		return search == 5 && res == 1;
	}

	private static int multiply(final int x, final int y) {
		int res = quaternions[Math.abs(x) - 1][Math.abs(y) - 1];
		if (x * y > 0) {
			return res;
		} else {
			return -res;
		}
	}
}
