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

		String[] ia = in.readLine().split(" ");
		final int N = Integer.parseInt(ia[0]);
		final int L = Integer.parseInt(ia[1]);

		String[] lines = new String[L];
		for (int i = 0; i < lines.length; ++i) {
			lines[i] = in.readLine();
		}

		int i = in.readLine().indexOf('o');
		for (int n = L - 1; 0 <= n; --n) {
			final int l = i - 1;
			final int r = i + 1;
			if (0 <= l && l < lines[n].length() && lines[n].charAt(l) == '-') {
				i -= 2;
			} else if (0 <= r && r < lines[n].length() && lines[n].charAt(r) == '-') {
				i += 2;
			}
		}

		System.out.println((i + 2) / 2);
	}
}