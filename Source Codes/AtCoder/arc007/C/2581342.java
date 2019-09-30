import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		final String pattern = in.readLine();
		final int p = Integer.parseInt(pattern.replaceAll("o", "1").replaceAll("x", "0"), 2);

		int ans = Integer.MAX_VALUE;

		for (int v = 1; v < 1 << pattern.length(); ++v) {
			int c = 0;
			int r = 0;
			for (int i = 0; i < pattern.length(); ++i) {
				if ((v >> i & 1) == 1) {
					++c;
					r |= p << i;
				}
			}
			final int mask = (1 << pattern.length()) - 1;
			final int loop1 = r & mask;
			final int loop2 = r >> pattern.length();
			if ((loop1 | loop2) == mask) {
				ans = Math.min(ans, c);
				if (debug) {
					System.err.println(String.format("%10s %20s %10s %10s\t%d",
					                                 Integer.toString(v, 2),
					                                 Integer.toString(r, 2),
					                                 Integer.toString(loop2, 2),
					                                 Integer.toString(loop1, 2),
					                                 c));
				}
			}

		}

		System.out.println(ans);
	}
}