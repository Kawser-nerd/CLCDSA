import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int hei = in.nextInt();
		int hh = hei / 2;
		int wid = in.nextInt();
		int ww = wid / 2;
		int mass = in.nextInt() * 0 + 1;
		int[][] a = new int[hei][wid];
		for (int i = 0; i < hei; i++) {
			String s = in.next();
			for (int j = 0; j < wid; j++) {
				a[i][j] = (s.charAt(j) - '0') + mass;
			}
		}
		long[][] mi = new long[hei + 1][wid + 1];
		long[][] mj = new long[hei + 1][wid + 1];
		int[][] m = new int[hei + 1][wid + 1];
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				m[i + 1][j + 1] = m[i + 1][j] + m[i][j + 1] - m[i][j] + a[i][j];
				mi[i + 1][j + 1] = mi[i + 1][j] + mi[i][j + 1] - mi[i][j] + a[i][j] * (i - hh);
				mj[i + 1][j + 1] = mj[i + 1][j] + mj[i][j + 1] - mj[i][j] + a[i][j] * (j - ww);
			}
		}
		int ans = 2;
		for (int s = 3; s <= hei; s++) {
			for (int i = 0; i < hei; i++) {
				for (int j = 0; j < wid; j++) {
					int ii = i + s;
					int jj = j + s;
					if (ii > hei || jj > wid) {
						break;
					}
					long M = m[ii][jj] - m[ii][j] - m[i][jj] + m[i][j];
					long Mi = mi[ii][jj] - mi[ii][j] - mi[i][jj] + mi[i][j];
					long Mj = mj[ii][jj] - mj[ii][j] - mj[i][jj] + mj[i][j];
					for (int p = 0; p < 2; p++) {
						for (int q = 0; q < 2; q++) {
							int ic = (p == 0) ? i : (ii - 1);
							int jc = (q == 0) ? j : (jj - 1);
							M -= a[ic][jc];
							Mi -= a[ic][jc] * (ic - hh);
							Mj -= a[ic][jc] * (jc - ww);
						}
					}
					int i2 = (i + ii - 1) - 2 * hh;
					int j2 = (j + jj - 1) - 2 * ww;
					if ((Mi * 2 == i2 * M) && (Mj * 2 == j2 * M)) {
						ans = s;
					}
				}
			}
		}
		if (ans < 3) {
			out.println("IMPOSSIBLE");
			return;
		}
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
