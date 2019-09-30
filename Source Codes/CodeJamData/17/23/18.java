package r1b2017;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt();
			int q = in.nextInt();
			int[] e = new int[n];
			int[] s = new int[n];
			for (int i = 0; i < n; i++) {
				e[i] = in.nextInt();
				s[i] = in.nextInt();
			}
			int[][] d = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = in.nextInt();
				}
			}
			
			long[][] r = new long[n][];
			for (int i = 0; i < n; i++) {
				long[] x = new long[n];
				boolean[] b = new boolean[n];
				Arrays.fill(x, Long.MAX_VALUE);
				x[i] = 0;
				while (true) {
					int st = -1;
					long min = Long.MAX_VALUE;
					for (int u = 0; u < n; u++) {
						if (!b[u] && x[u] < min) {
							st = u;
							min = x[u];
						}
					}
					if (st == -1 || min > e[i]) {
						break;
					}
					b[st] = true;
					for (int u = 0; u < n; u++) {
						if (d[st][u] != -1) {
							long next = x[st] + d[st][u];
							if (next <= e[i]) {
								x[u] = Math.min(x[u], x[st] + d[st][u]);
							}
						}
					}
				}
				r[i] = x;
				//System.out.println(i + " " + Arrays.toString(x));
			}
			
			for (int cnt = 0; cnt < q; cnt++) {
				int u = in.nextInt()-1, v = in.nextInt()-1;
				double[] a = new double[n];
				Arrays.fill(a, Double.MAX_VALUE);
				a[u] = 0;
				boolean[] b = new boolean[n];
				while (true) {
					int st = -1;
					double min = Double.MAX_VALUE;
					for (int i = 0; i < n; i++) {
						if (!b[i] && a[i] < min) {
							st = i;
							min = a[i];
						}
					}
					//System.out.println(st + " " + Arrays.toString(a));
					if (st == v) {
						out.print(a[st] + " ");
						break;
					}
					b[st] = true;
					for (int i = 0; i < n; i++) {
						if (r[st][i] != Long.MAX_VALUE) {
							a[i] = Math.min(a[i], a[st] + (1.0 * r[st][i] / s[st]));
						}
					}
				}
			}
			
			out.println();
		}

		out.flush();
	}

}
