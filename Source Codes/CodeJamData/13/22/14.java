import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Diamonds {
	public static void main(String[] args) {
		new Diamonds().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	String FNAME = "b";

	private void solve() throws IOException {
		// for (int n = 1; n <= 10; n++) {
		// for (int left = 0; left <= 2 * n; left++) {
		// int[] pos1 = new int[n];
		// int[] pos2 = new int[n];
		// for (int prof = 0; prof < 1 << left; prof++) {
		// int s1 = 0;
		// int s2 = 0;
		// for (int i = 0; i < left; i++) {
		// if (s2 >= n || ((prof & (1 << i)) != 0 && s1 < n)) {
		// s1++;
		// } else {
		// s2++;
		// }
		// }
		// for (int i = 0; i < s1; i++) {
		// pos1[i]++;
		// }
		// for (int i = 0; i < s2; i++) {
		// pos2[i]++;
		// }
		// }
		// // for (int i = 0; i < pos1.length; i++) {
		// // pos1[i] /= 1 << left;
		// // pos2[i] /= 1 << left;
		// // }
		// System.out.println("n = " + n + "; left = " + left + "; "
		// + (1 << left));
		// System.out.println(Arrays.toString(pos1));
		// System.out.println(Arrays.toString(pos2));
		// }
		// }

		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			System.out.println("test " + test);
			out.print("Case #" + (test) + ": ");
			int n = nextInt();
			int x = nextInt();
			int y = nextInt();
			if (Math.abs(x + y) % 2 != 0) {
				out.println("0.0");
				continue;
			}
			int generation = (Math.abs(x) + Math.abs(y)) / 2;
			long size = (generation + 1L) * (2 * generation + 1L);
			if (x == 0) {
				if (n >= size) {
					out.println("1.0");
				} else {
					out.println("0.0");
				}
				continue;
			}
			if (n >= size) {
				out.println("1.0");
				continue;
			}
			generation--;
			size = (generation + 1L) * (2 * generation + 1L);
			generation++;
			generation *= 2;
			if (n <= size) {
				out.println("0.0");
				continue;
			}
			int left = (int) (n - size);
			int pos = Math.abs(y);
			System.out.println(pos + " " + left);
			BigInteger[][] a = new BigInteger[pos + 1][left + 1];
			for (int i = 0; i < a[0].length; i++) {
				a[0][i] = BigInteger.ONE.shiftLeft(i).subtract(BigInteger.ONE);
				if (i > generation) {
					a[0][i] = BigInteger.ONE.shiftLeft(i);
				}
			}
			for (int i = 1; i < a.length; i++) {
				a[i][0] = BigInteger.ZERO;
				for (int j = 1; j < a[i].length; j++) {
					a[i][j] = a[i - 1][j - 1].add(a[i][j - 1]);
					if (j - i > generation) {
						a[i][j] = BigInteger.ONE.shiftLeft(j);
					}
				}
			}
			BigInteger ansp = a[pos][left];
			BigInteger ansq = BigInteger.ONE.shiftLeft(left);
			if (ansp.compareTo(ansq) >= 0) {
				out.print("1.");
				ansp = ansp.subtract(ansq);
			} else {
				out.print("0.");
			}
			for (int i = 0; i < 12; i++) {
				ansp = ansp.multiply(BigInteger.TEN);
				BigInteger[] bi = ansp.divideAndRemainder(ansq);
				out.print(bi[0]);
				ansp = bi[1];
			}
			out.println();
			out.flush();
		}
	}
}
