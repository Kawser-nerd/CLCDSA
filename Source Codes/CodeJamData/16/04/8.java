package gcj2016.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoD {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/q/ExoD/";
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
		int K = sc.nextInt();
		int C = sc.nextInt();
		int S = sc.nextInt();

		int res;

		if (K <= C) {
			res = 1;
		} else {
			res = K % C != 0 ? K / C + 1 : K / C;
		}

		if (S < res) {
			pw.print("IMPOSSIBLE");
			return;
		}

		int count = 0;
		BigInteger k = BigInteger.valueOf(K);
		BigInteger sol = BigInteger.ZERO;
		for (int i = 1; i <= K; i++) {
			sol = sol.multiply(k).add(BigInteger.valueOf(i - 1));
			if (i % C == 0 || i == K) {
				pw.print(sol.add(BigInteger.ONE).toString());
				pw.print(' ');
				sol = BigInteger.ZERO;
				count++;
			}
		}

		if (count != res) {
			System.out.println("???");
		}

	}
}
