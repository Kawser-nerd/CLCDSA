package gcj2015.r1b;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoA {

	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/1b/ExoA/";
		final String input = base + "b1.in";
		final String output = base + "b1.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			pre();
			System.out.println(Arrays.asList(pre));

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
		final long N = sc.nextLong();
		if (N < 10) {
			pw.print(N);
			return;
		}
		String s = String.valueOf(N);
		if (Long.valueOf(s.substring(1)) == 0) {
			if (s.charAt(0) == '1') {
				pw.print(pre[s.length() - 1]);
				return;
			} else {
				long r = g(N - 1) + 1;
				pw.print(r);
				return;
			}
		}
		long r = g(N);
		pw.print(r);
	}

	private static long g(final long N) {
		String s = String.valueOf(N);
		int length = s.length();
		long r = -1;
		if (length % 2 == 0) {
			String s1 = s.substring(0, length / 2);
			String s2 = s.substring(length / 2);
			long l1 = Long.valueOf(new StringBuilder(s1).reverse().toString());
			long l2 = Long.valueOf(s2);
			if (l2 != 0) {
				r = pre[length - 1] + Math.min(l1 + 1 + l2 - 1, N - pow10(length - 1));
			} else {
				long l1b = Long.valueOf(new StringBuilder(String.valueOf(Long.valueOf(s1) - 1)).reverse().toString());
				r = pre[length - 1] + Math.min(l1b + 1 + pow10(length / 2) - 1, N - pow10(length - 1));
			}
		} else {
			String s1 = s.substring(0, length / 2);
			String s2 = s.substring(length / 2);
			long l1 = Long.valueOf(new StringBuilder(s1).reverse().toString());
			long l2 = Long.valueOf(s2);
			if (l2 != 0) {
				r = pre[length - 1] + Math.min(l1 + 1 + l2 - 1, N - pow10(length - 1));
			} else {
				long l1b = Long.valueOf(new StringBuilder(String.valueOf(Long.valueOf(s1) - 1)).reverse().toString());
				r = pre[length - 1] + Math.min(l1b + 1 + pow10((length + 1) / 2) - 1, N - pow10(length - 1));
			}
		}
		return r;
	}

	static Long pre[] = new Long[15];

	private static void pre() {
		pre[0] = 1L;
		pre[1] = 10L;
		for (int i = 2; i < 15; i++) {
			f(i);
		}
	}

	private static void f(final int n) {
		int j = n / 2;
		int i = (n + 1) / 2;
		pre[n] = pre[n - 1] + pow10(i) + pow10(j) - 1;
	}

	private static long pow10(final int n) {
		long r = 1;
		for (int i = 0; i < n; i++) {
			r = 10 * r;
		}
		return r;
	}
}
