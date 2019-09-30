import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Number {
	private static boolean run(final char[] s, final int[] d1, final int[] d, final int k) {
		if (k == s.length) {
			for (int i = 1; i < 10; ++i) {
				if (d1[i] != d[i]) {
					return false;
				}
			}
			return true;
		}
		while (true) {
			char c = s[k];
			if (c > '9') {
				s[k] = '0';
				return false;
			}
			int x = c - '0';
			if (d1[x] < d[x]) {
				++d1[x];
				if (run(s, d1, d, k + 1)) {
					return true;
				}
				--d1[x];
			}
			++s[k];
		}
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; ++i) {
			final char[] s = ('0' + sc.nextLine()).toCharArray();
			final int[] d = new int[10];
			for (char c : s) {
				d[c - '0']++;
			}
			++s[s.length - 1];
			final int[] d1 = new int[10];
			if (!run(s, d1, d, 0)) {
				throw new RuntimeException();
			}
			final String r = String.valueOf(s);
			pw.println("Case #" + (i + 1) + ": " + (s[0] == '0' ? r.substring(1) : r));
		}
		pw.close();
	}
}
