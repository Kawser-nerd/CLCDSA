import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Segment implements Comparable<Segment> {
		final int length, speed;

		Segment(int length, int speed) {
			this.length = length;
			this.speed = speed;
		}
		
		public int compareTo(Segment o) {
			return speed - o.speed;
		}
	}
	
	static void solveTest() throws Exception {
		int x = nextInt();
		int s = nextInt();
		int r = nextInt();
		double t = nextInt();
		int n = nextInt();
		List<Segment> segs = new ArrayList<Segment>();
		int pos = 0;
		for (int i = 0; i < n; i++) {
			int b = nextInt();
			int e = nextInt();
			int w = nextInt();
			if (pos < b) {
				segs.add(new Segment(b - pos, 0));
			}
			segs.add(new Segment(e - b, w));
			pos = e;
		}
		if (pos < x) {
			segs.add(new Segment(x - pos, 0));
		}
		Collections.sort(segs);
		double ans = 0;
		for (Segment seg: segs) {
			if (t > 0) {
				double nt = (double) seg.length / (seg.speed + r);
				if (t < nt) {
					ans += t + (seg.length - (seg.speed + r) * t) / (seg.speed + s);
					t = 0;
				} else {
					ans += nt;
					t -= nt;
				}
			} else {
				ans += (double) seg.length / (seg.speed + s);
			}
		}
		out.printf(Locale.US, "%.12f\n", ans);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}