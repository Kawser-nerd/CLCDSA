package gcj2015.r1b;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {

	public static void main(final String[] args) {

		final String base = "/home/jean/gcj2015/1b/ExoB/";
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
		final int R = sc.nextInt();
		final int C = sc.nextInt();
		final int N = sc.nextInt();

		pw.print(solve(R, C, N));

	}

	private static int solve(final int r, final int c, int n) {
		if (r % 2 == 1 && c % 2 == 0) {
			return solve(c, r, n);
		}

		if (r % 2 == 0 && c % 2 == 0) {
			int m0 = (r * c) / 2;
			int m2 = 2;
			int m4 = ((r - 2) * (c - 2)) / 2;
			int m3 = (r * c) - m0 - m2 - m4;
			int t = 0;

			if (n > m0) {
				n = n - m0;
			} else {
				return t;
			}

			if (n > m2) {
				n = n - m2;
				t += 2 * m2;
			} else {
				return t + 2 * n;
			}

			if (n > m3) {
				n = n - m3;
				t += 3 * m3;
			} else {
				return t + 3 * n;
			}

			return t + 4 * n;

		} else if (r % 2 == 0 && c % 2 == 1) {
			if (c == 1) {
				int m0 = (r * c) / 2;
				int m1 = 1;
				int m2 = (r * c) - m0 - m1;
				int t = 0;

				if (n > m0) {
					n = n - m0;
				} else {
					return t;
				}

				if (n > m1) {
					n = n - m1;
					t += 1 * m1;
				} else {
					return t + 1 * n;
				}

				return t + 2 * n;

			} else {
				int m0 = (r * c) / 2;
				int m2 = 2;
				int m4 = ((r - 2) * (c - 2)) / 2;
				int m3 = (r * c) - m0 - m2 - m4;
				int t = 0;

				if (n > m0) {
					n = n - m0;
				} else {
					return t;
				}

				if (n > m2) {
					n = n - m2;
					t += 2 * m2;
				} else {
					return t + 2 * n;
				}

				if (n > m3) {
					n = n - m3;
					t += 3 * m3;
				} else {
					return t + 3 * n;
				}

				return t + 4 * n;
			}
		} else if (r % 2 == 1 && c % 2 == 1) {
			if (r == 1 && c == 1) {
				return 0;
			} else if (r == 1 || c == 1) {
				return Math.max(0, (n - ((r * c + 1) / 2)) * 2);
			} else {
				return Math.min(a1(r, c, n), a2(r, c, n));
			}

		} else {
			throw new IllegalArgumentException();
		}
	}

	private static int a1(final int r, final int c, int n) {
		{
			int m0 = ((r - 1) * (c - 1)) / 2 + (r - 1) / 2 + (c - 1) / 2 + 1;
			int m3 = (r - 1) + (c - 1);
			int m4 = (r * c) - m0 - m3;

			int t = 0;

			if (n > m0) {
				n = n - m0;
			} else {
				return t;
			}

			if (n > m3) {
				n = n - m3;
				t += 3 * m3;
			} else {
				return t + 3 * n;
			}

			return t + 4 * n;
		}
	}

	private static int a2(final int r, final int c, int n) {
		{
			int m0 = r * c - (((r - 1) * (c - 1)) / 2 + (r - 1) / 2 + (c - 1) / 2 + 1);
			int m2 = 4;
			int m3 = (r - 3) + (c - 3);
			int m4 = (r * c) - m0 - m2 - m3;

			int t = 0;

			if (n > m0) {
				n = n - m0;
			} else {
				return t;
			}

			if (n > m2) {
				n = n - m2;
				t += 2 * m2;
			} else {
				return t + 2 * n;
			}

			if (n > m3) {
				n = n - m3;
				t += 3 * m3;
			} else {
				return t + 3 * n;
			}

			return t + 4 * n;
		}
	}
}
