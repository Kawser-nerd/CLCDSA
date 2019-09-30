import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class C_1_Fashion_Police {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int j = sc.nextInt();
		final int p = sc.nextInt();
		final int s = sc.nextInt();
		final int k = sc.nextInt();
		final int[] c = new int[1000];
		final List<int[]> l = new ArrayList<>();
		int goodp = 0;
		int goods = 0;
		int nextp = 0;
		int nexts = 0;
		for (int ij = 0; ij < j; ++ij) {
			for (int ip = 0; ip < p; ++ip) {
				for (int is = 0; is < s; ++is) {
					final int xj = ij + 1;
					final int xp = (goodp + ip) % p + 1;
					final int xs = (goods + is) % s + 1;
					
					final int c1 = xj * 100 + xp * 10;
					final int c2 = xj * 100 + xs;
					final int c3 = xp * 10 + xs;
					if (c[c1] < k && c[c2] < k && c[c3] < k) {
						l.add(new int[]{xj, xp, xs});
						c[c1]++;
						c[c2]++;
						c[c3]++;
						nextp = xp - 1;
						nexts = xs - 1;
					}
				}
				goods = nexts;
			}
			goodp = nextp;
		}
		pw.println(l.size());
		for (int[] a : l) {
			for (int i = 0; i < 3; ++i) {
				if (i > 0) pw.print(' ');
				pw.print(a[i]);
			}
			pw.println();
		}
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-attempt1";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new C_1_Fashion_Police().solve(sc, pw);
		}
		pw.close();
		
		final File f = new File(fname + ".out.good");
		if (!f.exists()) {
			return;
		}
		System.out.println("Comparing");
		final BufferedReader r1 = new BufferedReader(new FileReader(fname + ".out"));
		final BufferedReader r2 = new BufferedReader(new FileReader(f));
		int n = 0;
		while (true) {
			n++;
			final String s1 = r1.readLine();
			final String s2 = r2.readLine();
			if (!Objects.equals(s1, s2)) {
				System.out.println("Line " + n);
				System.out.println("Expected: " + s2);
				System.out.println("Got:      " + s1);
				break;
			}
			if (s1 == null) {
				System.out.println("OK");
				break;
			}
		}
		r1.close();
		r2.close();
	}
}
