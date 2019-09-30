import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.round;
import static java.lang.System.exit;
import static java.math.BigInteger.ZERO;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Vec implements Comparable<Vec> {
		
		final BigInteger x, y;
		
		Vec() throws IOException {
			x = nextReal();
			y = x.multiply(nextReal());
		}
		
		public int compareTo(Vec o) {
			return y.multiply(o.x).compareTo(o.y.multiply(x));
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		BigInteger xRes = nextReal();
		BigInteger yRes = xRes.multiply(nextReal());
		Vec vecs[] = new Vec[n];
		for (int i = 0; i < n; i++) {
			vecs[i] = new Vec();
		}
		sort(vecs);
		BigInteger cx = ZERO;
		BigInteger cy = ZERO;
		for (int i = 0; i < n; i++) {
			BigInteger nx = cx.add(vecs[i].x);
			BigInteger ny = cy.add(vecs[i].y);
//			System.err.println(cx + " " + cy + " -> " + nx + " " + ny);
			if (ny.multiply(xRes).compareTo(yRes.multiply(nx)) > 0) {
				if (i == 0) {
					printCase();
					out.println("IMPOSSIBLE");
					return;
				}
				// t * xRes - u * (nx - cx) = cx
				// t * yRes - u * (ny - cy) = cy
				// t = (cy * nx - cx * ny) / (xRes * (cy - ny) - yRes * (cx - nx))
				printCase();
				out.printf(Locale.US, "%.9f\n",
					xRes.multiply(cy.subtract(ny)).subtract(yRes.multiply(cx.subtract(nx))).doubleValue() /
					cy.multiply(nx).subtract(ny.multiply(cx)).doubleValue());
				return;
			}
			cx = nx;
			cy = ny;
		}
		if (cy.multiply(xRes).compareTo(yRes.multiply(cx)) == 0) {
			printCase();
			out.printf(Locale.US, "%.9f\n",
				xRes.doubleValue() /
				cx.doubleValue());
			return;
		}
		cx = ZERO;
		cy = ZERO;
		for (int i = n - 1; i >= 0; i--) {
			BigInteger nx = cx.add(vecs[i].x);
			BigInteger ny = cy.add(vecs[i].y);
//			System.err.println(cx + " " + cy + " -> " + nx + " " + ny);
			if (ny.multiply(xRes).compareTo(yRes.multiply(nx)) < 0) {
				if (i == n - 1) {
					printCase();
					out.println("IMPOSSIBLE");
					return;
				}
				printCase();
				out.printf(Locale.US, "%.9f\n",
					xRes.multiply(cy.subtract(ny)).subtract(yRes.multiply(cx.subtract(nx))).doubleValue() /
					cy.multiply(nx).subtract(ny.multiply(cx)).doubleValue());
				return;
			}
			cx = nx;
			cy = ny;
		}
		printCase();
		out.println("IMPOSSIBLE");
	}
	
	static BigInteger nextReal() throws IOException {
		return BigInteger.valueOf(round(nextDouble() * 10000));
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}