import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
class Main {
	public static void main(String[] args) {
		new Main().new C().run();
	}
	static void debug(Object... os) {
		System.err.println(deepToString(os));
	}
	class A {
		void run() {
			Scanner sc = new Scanner(System.in);
			try {
// sc = new Scanner(new File("A-small-attempt0.in"));
// System.setOut(new PrintStream("A-small-attempt0.out"));
				sc = new Scanner(new File("A-large.in"));
				System.setOut(new PrintStream("A-large.out"));
			} catch (Exception e) {}
			int oo = sc.nextInt();
			sc.nextLine();
			int max = 100000;
			int[][] memo = new int[max][11];
			for (int[] is : memo)
				fill(is, -1);
			for (int i = 0; i < max; i++) {
				for (int j = 2; j <= 10; j++) {
					isHappy(i, j, memo);
				}
			}
// debug(memo);
			for (int o = 1; o <= oo; o++) {
				debug(o);
				System.out.printf("Case #%d: ", o);
				String[] ss = sc.nextLine().split(" ");
				int n = ss.length;
				int[] is = new int[n];
				for (int i = 0; i < n; i++)
					is[i] = Integer.valueOf(ss[i]);
				for (int i = 2;; i++) {
					boolean ok = true;
					for (int j = 0; j < n; j++) {
						if (i < max) {
							if (memo[i][is[j]] == 0) {
								ok = false;
								break;
							} else if (memo[i][is[j]] == 1) ;
							else throw new IllegalArgumentException();
						} else {
							if (!isHappy(i, is[j], max, memo)) {
								ok = false;
								break;
							}
						}
					}
					if (ok) {
						System.out.println(i);
						break;
					}
				}
			}
		}
		boolean isHappy(int n, int b, int max, int[][] memo) {
			if (n < max) return isHappy(n, b, memo) == 1;
			int k = n;
			int nn = 0;
			while (k > 0) {
				nn += (k % b) * (k % b);
				k /= b;
			}
			return isHappy(nn, b, max, memo);
		}
		int isHappy(int n, int b, int[][] memo) {
			if (n == 1) return memo[n][b] = 1;
			if (memo[n][b] >= 0) {
				if (memo[n][b] == 2) { return memo[n][b] = 0; }
				return memo[n][b];
			}
			memo[n][b] = 2;
			int k = n;
			int nn = 0;
			while (k > 0) {
				nn += (k % b) * (k % b);
				k /= b;
			}
			return memo[n][b] = isHappy(nn, b, memo);
		}
	}
	class B {
		void run() {
			Scanner sc = new Scanner(System.in);
			try {
				sc = new Scanner(new File("B-small-attempt0.in"));
				System.setOut(new PrintStream("B-small-attempt0.out"));
				// sc = new Scanner(new File("B-large.in"));
				// System.setOut(new PrintStream("B-large.out"));
			} catch (Exception e) {}
			int oo = sc.nextInt();
			for (int o = 1; o <= oo; o++) {
				debug(o);
				System.out.printf("Case #%d: ", o);

			}
		}
	}
	class C {
		void run() {
			Scanner sc = new Scanner(System.in);
			try {
//				sc = new Scanner(new File("C-small-attempt1.in"));
//				System.setOut(new PrintStream("C-small-attempt1.out"));
				 sc = new Scanner(new File("C-large.in"));
				 System.setOut(new PrintStream("C-large.out"));
			} catch (Exception e) {}
			int oo = sc.nextInt();
			int max = 41;
			double[][][] memo = new double[max][max][max];
			for (int i = 0; i < max; i++) {
				for (int j = 0; j < max; j++) {
					fill(memo[i][j], -1);
				}
			}
			for (int n = 1; n < max; n++) {
				for (int k = 0; k <= n; k++) {
					for (int c = 1; c <= n; c++) {
						E(n, k, c, memo);
					}
				}
			}
			debug(memo[max - 1][0]);
// debug(memo);
			for (int o = 1; o <= oo; o++) {
				System.out.printf("Case #%d: ", o);
				System.out.printf("%.07f%n", memo[sc.nextInt()][0][sc.nextInt()]);
			}
		}
		double E(int n, int k, int c, double[][][] memo) {
			if (k == n) return memo[n][k][c] = 0;
			if (memo[n][k][c] >= 0) { return memo[n][k][c]; }
			memo[n][k][c] = 0;
			for (int i = max(0, c - k); i <= min(n - k, c); i++) {
				memo[n][k][c] += comb(n - k, i) * comb(k, c - i) * (E(n, k + i, c, memo) + 1);
			}
			memo[n][k][c] /= (comb(n, c) - comb(k, c));
// debug(n, k, c, memo[n][k][c]);
			return memo[n][k][c];
		}
		long comb(int n, int m) {
			if (n < m) {
// debug(n, m);
				return 0;
			}
			long res = 1;
			for (int i = 0; i < m; i++) {
				res *= n - i;
				res /= i + 1;
			}
			return res;
		}
	}
}
