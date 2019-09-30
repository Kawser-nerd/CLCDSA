import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.Scanner;

public class B_2_Slides {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int b = sc.nextInt();
		final long m = sc.nextLong();
		if (m > (1l << (b - 2))) {
			pw.println("IMPOSSIBLE");
			return;
		}
		pw.println("POSSIBLE");
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j <= i; ++j) {
				pw.print(0);
			}
			for (int j = 0; j < b - i - 2; ++j) {
				pw.print(1);
			}
			if (i == b - 1) {
				pw.println();
				break;
			}
			pw.println(i == 0 || ((m - 1) & (1l << (i - 1))) != 0 ? 1 : 0);
		}
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_2_Slides().solve(sc, pw);
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
