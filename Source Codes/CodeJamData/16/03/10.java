package gcj2016.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoC {
	private static final BigInteger MAXDIV = new BigInteger("500");
	private static final BigInteger THREE = new BigInteger("3");
	private static final BigInteger TWO = new BigInteger("2");

	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/q/ExoC/";
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
		int N = sc.nextInt();
		int J = sc.nextInt();

		int count = 0;
		int t = 0;

		loop: while (count < J) {

			t++;
			String s = Integer.toBinaryString(t);
			while (s.length() < N - 2) {
				s = "0" + s;
			}
			s = "1" + s + "1";
			System.out.println(s);

			for (int r = 2; r <= 10; r++) {
				BigInteger integer = new BigInteger(s, r);
				if (findPrimeFactor(integer) == BigInteger.ZERO) {
					continue loop;
				}
			}

			System.out.println("ok!");

			count++;

			pw.println();
			pw.print(s);
			pw.print(' ');

			for (int r = 2; r <= 10; r++) {
				BigInteger integer = new BigInteger(s, r);
				BigInteger primeFactor = findPrimeFactor(integer);
				pw.print(primeFactor.toString());
				pw.print(' ');
			}
		}

	}

	private static BigInteger findPrimeFactor(final BigInteger n) {
		if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
			return TWO;
		}
		for (BigInteger i = THREE; MAXDIV.compareTo(i) >= 0; i = i.add(TWO)) {
			if (n.mod(i).compareTo(BigInteger.ZERO) == 0) {
				return i;
			}
		}

		return BigInteger.ZERO;
	}
}
