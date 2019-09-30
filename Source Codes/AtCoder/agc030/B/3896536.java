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
		long l = scanInt();
		int n = scanInt();
		long x[] = new long[n], xsum[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			xsum[i + 1] = xsum[i] + x[i];
		}
		long ans = 0;
		for (int it = 0;; it++) {
			for (int i = 0; i < n; i++) {
				long cans = x[n - i - 1];
//				for (int j = n - i; j < min(n, 2 * n - 2 * i); j++) {
//					cans += (l - x[j]) * 2;
//				}
//				for (int j = max(0, n - 2 * i - 1); j < n - i - 1; j++) {
//					cans += x[j] * 2;
//				}
				if (min(n, 2 * n - 2 * i) > n - i) {
					cans += 2 * (l * (min(n, 2 * n - 2 * i) - (n - i)) - (xsum[min(n, 2 * n - 2 * i)] - xsum[n - i]));
				}
				if (n - i - 1 > max(0, n - 2 * i - 1)) {
					cans += 2 * (xsum[n - i - 1] - xsum[max(0, n - 2 * i - 1)]);
				}
				ans = max(ans, cans);
			}
			if (it == 0) {
				for (int i = 0, j = n - 1; i <= j; i++, j--) {
					long t = x[i];
					x[i] = l - x[j];
					x[j] = l - t;
				}
				for (int i = 0; i < n; i++) {
					xsum[i + 1] = xsum[i] + x[i];
				}
			} else {
				break;
			}
		}
		out.print(ans);
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