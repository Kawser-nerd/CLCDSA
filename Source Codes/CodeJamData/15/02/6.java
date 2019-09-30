package gcj2015.qualif;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {
	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/q/ExoB/";
		final String input = base + "b1.in";
		final String output = base + "b2.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test3(sc, pw);
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

	private static void test3(final Scanner sc, final PrintWriter pw) {
		final int D = sc.nextInt();
		List<Integer> nums = new ArrayList<Integer>();
		for (int i = 0; i < D; i++) {
			nums.add(sc.nextInt());
		}
		int max = Collections.max(nums);
		int bt = max;
		for (int m = 1; m <= max; m++) {
			System.out.println("for m = " + m);
			int t = m;
			for (int k : nums) {
				if (k != 0)
					t += (k % m == 0) ? (k / m) - 1 : k / m;
			}
			System.out.println("t = " + t);
			if (t < bt) {
				bt = t;
			}
		}
		pw.print(bt);
	}

}
