import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.Scanner;

public class A_2_Evacuation {
	private static int count(final int[] a, final int x) {
		int n = 0;
		for (int y : a) {
			if (y == x) {
				n++;
			}
		}
		return n;
	}
	
	private static int max(final int[] a) {
		int t = -1;
		for (int y : a) {
			t = Math.max(t, y);
		}
		return t;
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		final int[] p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = sc.nextInt();
		}
		int[] a = new int[2];
		while (count(p, 0) < n) {
			final int m = max(p);
			final int c = count(p, m);
			final int e = c == 1 || c == 3 ? 1 : 2;
			int k = 0;
			for (int i = 0; i < n; ++i) {
				if (p[i] == m) {
					a[k++] = i;
					p[i]--;
					if (k == e) {
						break;
					}
				}
			}
			for (int i = 0; i < e; ++i) {
				pw.print((char) (a[i] + 'A'));
			}
			pw.print(' ');
		}
		pw.println();
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new A_2_Evacuation().solve(sc, pw);
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
