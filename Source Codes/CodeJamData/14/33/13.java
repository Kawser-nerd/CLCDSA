import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C_enclosure {
	public void solve(final Scanner sc, final PrintWriter pw) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		if (n > m) {
			int t = n;
			n = m;
			m = t;
		}
		int[] a = new int[n];
		int[] a1 = new int[n];
		final int max = (int) Math.pow(m + 1, n);
		int best = k;
		for (int i = 0; i < max; ++i) {
			int x = i;
			int co = 0;
			for (int j = 0; j < n; ++j) {
				a[j] = x % (m + 1);
				co += a[j];
				x /= (m + 1);
			}
			if (co < k) continue;
			boolean b = false;
			for (int j = 1; j < n; ++j) {
				if (a[j] > a[j - 1]) {
					b = true;
					break;
				}
			}
			if (b) continue;
			int p = (n - 1) / 2;
			int sg = 1;
			for (int j = 0; j < n; ++j) {
				a1[p] = a[j];
				p += (j + 1) * sg;
				sg = -sg;
			}
			int st = 0;
			for (int j = 0; j <= (n - 1) / 2; ++j) {
				if (a1[j] == 0) continue;
				if (st == 0) {
					st = a1[j];
				}
				else if (a1[j] == 1) {
					st++; 
				}
				else {
					st += Math.max(a1[j] - a1[j - 1], 2);
				}
			}
			for (int j = n - 1; j > (n - 1) / 2; --j) {
				if (a1[j] == 0) continue;
				if (j == n - 1 || a1[j + 1] == 0) {
					st += a1[j];
				}
				else if (a1[j] == 1) {
					st++; 
				}
				else {
					st += Math.max(a1[j] - a1[j + 1], 2);
				}
			}
			if (st < best) best = st;
		}
		pw.println(best);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new C_enclosure().solve(sc, pw);
		}
		pw.close();
	}
}
