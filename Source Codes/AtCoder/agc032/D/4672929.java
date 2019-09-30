import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt();
		long a = scanInt(), b = scanInt();
		long dyn[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			int p = scanInt();
			long c = Long.MAX_VALUE;
			for (int j = 0; j < p; j++) {
				c = min(c, dyn[j]);
				dyn[j] += a;
			}
			dyn[p] = c;
			for (int j = p + 1; j <= n; j++) {
				dyn[j] += b;
			}
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i <= n; i++) {
			ans = min(ans, dyn[i]);
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