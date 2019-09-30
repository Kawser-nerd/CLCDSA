import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class EqualSums2 {
	public static void main(final String... args) throws IOException {
		final String fname = "C-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int n = sc.nextInt();
			final long[] a = new long[n];
			for (int j = 0; j < n; ++j) {
				a[j] = sc.nextLong();
			}
			final Random rnd = new Random();
			final Map<Long, Long> m = new HashMap<Long, Long>();
			long s1 = -1;
			long s2 = -1;
			while (true) {
				long j = rnd.nextLong();
				if (j < 0) {
					continue;
				}
				long x = j;
				int k = 0;
				long s = 0;
				while (x > 0) {
					if ((x & 1) != 0) {
						s += a[k];
					}
					x >>= 1;
					++k;
				}
				final Long b = m.get(s);
				if (b == null) {
					m.put(s, j);
				}
				else if (b != j) {
					s1 = b;
					s2 = j;
					break;
				}
			}
			pw.println("Case #" + i + ":");
			int k = 0;
			while (s1 > 0) {
				if ((s1 & 1) != 0) {
					pw.print(a[k] + " ");
				}
				s1 >>= 1;
				++k;
			}
			pw.println();
			k = 0;
			while (s2 > 0) {
				if ((s2 & 1) != 0) {
					pw.print(a[k] + " ");
				}
				s2 >>= 1;
				++k;
			}
			pw.println();
		}
		pw.close();
	}
}
