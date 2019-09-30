import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A_part_elf {
	public static long gcd(long x, long y) {
		long r;
		while (true) {
			r = x % y;
			if (r == 0) {
				return y;
			}
			x = y;
			y = r;
		}
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		String s = sc.nextLine();
		String[] a = s.split("/");
		long p = Long.parseLong(a[0]);
		long q = Long.parseLong(a[1]);
		long g = gcd(p, q);
		p /= g;
		q /= g;
		if (q != Long.highestOneBit(q)) {
			pw.println("impossible");
			return;
		}
		for (int i = 0; ; ++i) {
			if ((1l<<i) * p >= q) {
				pw.println(i);
				return;
			}
		}
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
			new A_part_elf().solve(sc, pw);
		}
		pw.close();
	}
}
