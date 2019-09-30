import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Safety {
	public static void main(final String... args) throws IOException {
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			final int n = sc.nextInt();
			final int[] a = new int[n];
			final List<Double> d = new ArrayList<Double>();
			int x = 0;
			for (int j = 0; j < n; ++j) {
				a[j] = sc.nextInt();
				d.add((double) a[j]);
				x += a[j];
			}
			double y = x;
			while (Math.abs(y) > 1e-6) {
				final List<Double> l = new ArrayList<Double>(d);
				Collections.sort(l);
				double m1 = l.get(0);
				double m2 = -1;
				for (Double q : l) {
					if (q > m1 + 1e-6) {
						m2 = q;
						break;
					}
				}
				if (m2 < 0) {
					for (int j = 0; j < n; ++j) {
						d.set(j, d.get(j) + y / n);
					}
					break;
				}
				int m = 0;
				for (int j = 0; j < n; ++j) {
					if (Math.abs(d.get(j) - m1) < 1e-6) {
						m++;
					}
				}
				double tot = m * (m2 - m1);
				if (y > tot - 1e-6) {
					for (int j = 0; j < n; ++j) {
						if (Math.abs(d.get(j) - m1) < 1e-6) {
							d.set(j, m2);
						}
					}
					y -= tot;
				}
				else {
					for (int j = 0; j < n; ++j) {
						if (Math.abs(d.get(j) - m1) < 1e-6) {
							d.set(j, m1 + y / m);
						}
					}
					break;
				}
			}
			pw.print("Case #" + i + ":");
			for (int j = 0; j < n; ++j) {
				double r = 100 * (d.get(j) - a[j]) / x;
				pw.print(" " + r);
			}
			pw.println();
		}
		pw.close();
	}
}
