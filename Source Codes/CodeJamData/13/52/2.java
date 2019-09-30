import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class B {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static void solveOneTest() throws IOException {
		int n = nextInt();
		Point[] p = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		bestArea = Long.MIN_VALUE;
		bestOrder = null;
		boolean[] was = new boolean[n];
		Point[] order = new Point[n];
		int[] intOrder = new int[n];
		order[0] = p[0];
		was[0] = true;
		goAll(p, order, intOrder, was, 1);
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(bestOrder[i]);
		}
		out.println();
	}

	static int[] bestOrder;

	static long bestArea;

	private static void goAll(Point[] p, Point[] order, int[] intOrder,
			boolean[] was, int start) {
		if (start == p.length) {
			if (!isGood(order)) {
				return;
			}
			long area = area(order);
			if (area > bestArea) {
				bestArea = area;
				bestOrder = intOrder.clone();
			}
		}

		for (int i = 0; i < p.length; i++) {
			if (was[i]) {
				continue;
			}
			order[start] = p[i];
			intOrder[start] = i;
			was[i] = true;
			goAll(p, order, intOrder, was, start + 1);
			was[i] = false;
		}
	}

	private static boolean isGood(Point[] order) {
		for (int i = 0; i < order.length; i++) {
			for (int j = i + 2; j < order.length; j++) {
				if (i == 0 && j == order.length - 1) {
					continue;
				}
				Point p1 = order[i];
				Point p2 = order[i + 1];
				Point q1 = order[j];
				Point q2 = order[(j + 1) % order.length];

				if (theyIntersect(p1, p2, q1, q2)) {
					return false;
				}
			}
		}
		return true;
	}

	static boolean intersect1(int a, int b, int c, int d) {
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		if (c > d) {
			int t = c;
			c = d;
			d = t;
		}
		return max(a, c) <= min(b, d);
	}

	private static boolean theyIntersect(Point p1, Point p2, Point q1, Point q2) {
		if (!intersect1(p1.x, p2.x, q1.x, q2.x)) {
			return false;
		}
		if (!intersect1(p1.y, p2.y, q1.y, q2.y)) {
			return false;
		}
		Point p1p2 = p2.sub(p1);
		int q1Side = Integer.signum(q1.sub(p1).vmul(p1p2));
		int q2Side = Integer.signum(q2.sub(p1).vmul(p1p2));

		Point q1q2 = q2.sub(q1);
		int p1Side = Integer.signum(p1.sub(q1).vmul(q1q2));
		int p2Side = Integer.signum(p2.sub(q1).vmul(q1q2));
		
		return q1Side * q2Side <= 0 && p1Side * p2Side <= 0;
	}

	private static long area(Point[] p) {
		long ret = 0;
		for (int i = 0; i < p.length; i++) {
			Point u = p[i];
			Point v = p[(i + 1) % p.length];
			ret += u.vmul(v);
		}
		return Math.abs(ret);
	}

	static class Point {
		int x, y;

		Point sub(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		int vmul(Point p) {
			return x * p.y - y * p.x;
		}

		int sqAbs() {
			return x * x + y * y;
		}

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("b.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
