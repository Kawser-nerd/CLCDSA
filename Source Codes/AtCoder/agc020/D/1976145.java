import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			long a = scanInt();
			long b = scanInt();
			long c = scanInt() - 1;
			long d = scanInt();
			long x = (max(a, b) - 1) / (min(a, b) + 1) + 1;
			long la, lb;
			if (a >= x * b) {
				la = a + b;
				lb = 0;
			} else if (b >= x * a) {
				la = 0;
				lb = a + b;
			} else {
				la = (x * a - b) / (x - 1);
				lb = (x * b - a) / (x - 1);
			}
			boolean cB = a - la + la / (x + 1) - lb / (x + 1) == 0;
			for (long i = c; i < d; i++) {
				boolean isB = i < la ? i % (x + 1) == x :
					i >= a + b - lb ? (a + b - i - 1) % (x + 1) != x :
					cB;
				out.print(isB ? 'B' : 'A');
			}
			out.println();
		}
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