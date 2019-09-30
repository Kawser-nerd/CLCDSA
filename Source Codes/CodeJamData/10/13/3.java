import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String filename = "C-large";
	final double fc = 2.0 / (Math.sqrt(5) + 1);

	public int test2(int A, int B) {

		int C = (int) (fc * A);
		if (B < C)
			return B;
		return C;
	}

	public int test(int A, int B1, int B2, int p) {
		int ans = 0;
		if (B2 >= 2 * A + 1) {
			ans += B2 - 2 * A;
			B2 = 2 * A;
		}

		if (B1 < A) {
			int C1 = B1, C2 = Math.min(A - 1, B2);
			ans += test2(A, C2) - test2(A, C1 - 1);
		}

		if (B2 > A) {
			int C1 = Math.max(A + 1, B1), C2 = B2;
			ans += (C2 - C1 + 1) - test(A, C1 - A, C2 - A, p ^ 1);
		}
		return ans;
	}

	int gcd(int x, int y) {
		if (x < y) {
			int t = x;
			x = y;
			y = t;
		}
		if (x > 2 * y)
			return 1;
		if (x == y)
			return 0;
		return 1 - gcd(x - y, y);
	}

	public void check() {
		for (int A = 1; A <= 20; A++) {
			for (int B1 = 1; B1 <= 50; B1++) {
				int c = 0;
				for (int B2 = B1; B2 <= 50; B2++) {
					c += gcd(A, B2);
					int c2 = test(A, B1, B2, 0);
					if (c2 != c) {
						System.out.println("FAIL: A=" + A + " B=" + B1 + " res="
								+ c2 + " expected=" + c);
					}
				}
			}
		}
	}

	public void solve() throws Exception {
		check();
		int T = iread();
		for (int t = 1; t <= T; t++) {
			int A1 = iread(), A2 = iread(), B1 = iread(), B2 = iread();

			long ans = 0;
			for (int A = A1; A <= A2; A++)
			   ans += test(A, B1, B2, 0);
//			for (int A = A1; A <= A2; A++)
//				for (int B = B1; B <= B2; B++)
//					ans += gcd(A, B);
			out.write("Case #" + t + ": " + ans + "\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}