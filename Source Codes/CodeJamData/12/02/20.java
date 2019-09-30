package qualification;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class B {
	public static void main(String[] args) throws IOException {
		new B().go();
	}

	Scanner in;
	PrintWriter out;

	int[] maxS = new int[31];
	int[] maxNS = new int[31];

	private void go() throws IOException  {
		buildMax();
		in = new Scanner(new File("src\\qualification\\b.in"));
		out = new PrintWriter(new File("src\\qualification\\b.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			out.println("Case #" + tn + ": " + solveCase());
		}
		in.close();
		out.close();
	}

	private void buildMax() {
		Arrays.fill(maxS, -1);
		Arrays.fill(maxNS, -1);
		for (int a = 0; a <= 10; a++)
			for (int b = Math.max(0, a - 2); b <= Math.min(10, a + 2); b++)
				for (int c = Math.max(0, Math.max(a - 2, b - 2)); c <= Math.min(10, Math.min(a + 2, b + 2)); c++) {
					int t = a + b + c;
					int max = Math.max(a, Math.max(b, c));
					if (Math.abs(a - b) == 2 || Math.abs(a - c) == 2 || Math.abs(b - c) == 2)
						maxS[t] = Math.max(maxS[t], max);
					else
						maxNS[t] = Math.max(maxNS[t], max);
				}
	}

	private int solveCase() {
		int n = in.nextInt();
		int s = in.nextInt();
		int p = in.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++)
			t[i] = in.nextInt();
		int[][] r = new int[n + 1][s + 1];
		Arrays.fill(r[0], -1);
		r[0][0] = 0;
		for (int i = 0; i < n; i++) {
			Arrays.fill(r[i + 1], -1);
			for (int j = 0; j <= s; j++) {
				if (r[i][j] >= 0 && maxNS[t[i]] >= 0)
					r[i + 1][j] = r[i][j] + (maxNS[t[i]] >= p ? 1 : 0);
				if (j > 0 && r[i][j - 1] >= 0 && maxS[t[i]] >= 0)
					r[i + 1][j] = Math.max(r[i + 1][j], r[i][j - 1] + (maxS[t[i]] >= p ? 1 : 0));
			}
		}
		return r[n][s];
	}
}
