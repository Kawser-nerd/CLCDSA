import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Digging {
	class Position {
		int x;
		int cells;
	}
	
	static boolean canFall(final int r, final int c, final int f, final String[] map) {
		for (int i = 0; i < f; ++i) {
			if (map[r + 2 + i].charAt(c) == '#') {
				return true;
			}
		}
		return false;
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int n = sc.nextInt();
		for (int i = 0; i < n; ++i) {
			final int r = sc.nextInt();
			final int c = sc.nextInt();
			final int f = sc.nextInt();
			sc.nextLine();
			final String[] map = new String[r + 1];
			for (int j = 0; j < r; ++j) {
				map[j] = sc.nextLine();
			}
			final char[] b = new char[c];
			Arrays.fill(b, '#');
			map[r] = new String(b);
			int[][] s1 = new int[c][c];
			int[][] s2 = new int[c][c];
			final int M = 10000;
			for (int j = 0; j < c; ++j) {
				Arrays.fill(s1[j], M);
			}
			s1[0][0] = 0;
			for (int j = 0; j < r - 1; ++j) {
				for (int k = 0; k < c; ++k) {
					Arrays.fill(s2[k], M);
				}
				for (int k = 0; k < c; ++k) {
					for (int l = 0; l < c; ++l) {
						int m = s1[k][l];
						if (m < M) {
							if (map[j + 1].charAt(k) == '.') {
								s2[k][k] = Math.min(s2[k][k], m);
							} else {
								int xl = k;
								int xr = k;
								while (xl > 0 && (map[j].charAt(xl - 1) == '.' || xl > l) && map[j + 1].charAt(xl - 1) == '#') {
									--xl;
								}
								while (xr < c - 1 && (map[j].charAt(xr + 1) == '.' || xr < l) && map[j + 1].charAt(xr + 1) == '#') {
									++xr;
								}
								if (xl > 0 && (map[j].charAt(xl - 1) == '.' || xl > l) && map[j + 1].charAt(xl - 1) == '.' && canFall(j, xl - 1, f, map)) {
									s2[xl - 1][xl - 1] = Math.min(s2[xl - 1][xl - 1], m);
								}
								if (xr < c - 1 && (map[j].charAt(xr + 1) == '.' || xr < l) && map[j + 1].charAt(xr + 1) == '.' && canFall(j, xr + 1, f, map)) {
									s2[xr + 1][xr + 1] = Math.min(s2[xr + 1][xr + 1], m);
								}
								for (int x1 = xl + 1; x1 <= xr; ++x1) {
									if (canFall(j, x1, f, map)) {
										for (int x2 = x1; x2 <= xr; ++x2) {
											s2[x1][x2] = Math.min(s2[x1][x2], m + x2 - x1 + 1);
										}
									}
								}
								for (int x1 = xr - 1; x1 >= xl; --x1) {
									if (canFall(j, x1, f, map)) {
										for (int x2 = x1; x2 >= xl; --x2) {
											s2[x1][x2] = Math.min(s2[x1][x2], m + x1 - x2 + 1);
										}
									}
								}
							}
						}
					}
				}
				int[][] t = s1;
				s1 = s2;
				s2 = t;
			}
			int m = M;
			for (int k = 0; k < c; ++k) {
				for (int l = 0; l < c; ++l) {
					if (s1[k][l] < m) {
						m = s1[k][l];
					}
				}
			}
			if (m < M) {
				pw.println("Case #" + (i + 1) + ": Yes " + m);
			} else {
				pw.println("Case #" + (i + 1) + ": No");
			}
		}
		pw.close();
	}
}
