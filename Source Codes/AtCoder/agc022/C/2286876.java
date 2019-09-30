import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		int b[] = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = scanInt();
			if (b[i] != a[i] && 2 * b[i] >= a[i]) {
				out.print("-1");
				return;
			}
		}
		long cur = (1L << 50) - 1;
		boolean set[] = new boolean[51];
		bit: for (int bit = 49; bit >= 0; --bit) {
			long test = cur & ~(1L << bit);
			for (int i = 0; i < n; i++) {
				fill(set, false);
				set[a[i]] = true;
				for (int j = 49; j >= 0; j--) {
					if ((test & (1L << j)) != 0) {
						for (int k = j + 1; k <= 50; k++) {
							if (set[k]) {
								set[k % (j + 1)] = true;
							}
						}
					}
				}
				if (!set[b[i]]) {
//					System.err.println(test + " " + i);
					continue bit;
				}
			}
			cur = test;
		}
		out.print(cur << 1);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}