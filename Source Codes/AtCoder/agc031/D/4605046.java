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

	static int[] compose(int p[], int q[]) {
		int n = p.length;
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = p[q[i]];
		}
		return r;
	}

	static int[] inv(int p[]) {
		int n = p.length;
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[p[i]] = i;
		}
		return r;
	}

	static int[] pow(int p[], int m) {
		int n = p.length;
		int r[] = new int[n];
		fill(r, -1);
		int c[] = new int[n];
		for (int i = 0; i < n; i++) {
			if (r[i] >= 0) {
				continue;
			}
			int clen = 0;
			for (int j = i;;) {
				c[clen++] = j;
				j = p[j];
				if (j == i) {
					break;
				}
			}
			for (int j = 0; j < clen; j++) {
				r[c[j]] = c[(j + m) % clen];
			}
		}
		return r;
	}

	static void solve() throws Exception {
		int n = scanInt();
		int k = scanInt() - 1;
		int p[] = new int[n], pi[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = scanInt() - 1;
			pi[p[i]] = i;
		}
		int q[] = new int[n], qi[] = new int[n];
		for (int i = 0; i < n; i++) {
			q[i] = scanInt() - 1;
			qi[q[i]] = i;
		}
		int pr[] = pow(compose(compose(compose(q, pi), qi), p), k / 6);
		int su[] = pow(compose(compose(compose(pi, q), p), qi), k / 6);
		int p1[] = compose(compose(pr, p), su);
		int p2[] = compose(compose(pr, q), su);
		int res[];
		if (k % 6 == 0) {
			res = p1;
		} else {
			for (int i = 1; i != k % 6; i++) {
				int p3[] = compose(p2, inv(p1));
				p1 = p2;
				p2 = p3;
			}
			res = p2;
		}
		for (int i = 0; i < n; i++) {
			out.print((res[i] + 1) + " ");
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