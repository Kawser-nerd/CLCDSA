import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "D-small-attempt0";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	static class Vector {
		double x, y;
		
		Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		double len2() {
			return x * x + y * y;
		}
		
		double len() {
			return Math.sqrt(len2());
		}
		
		Vector add(Vector b) {
			return new Vector(x + b.x, y + b.y);
		}
		
		Vector sub(Vector b) {
			return new Vector(x - b.x, y - b.y);
		}
		
		Vector mul(double b) {
			return new Vector(x * b, y * b);
		}
	}
	
	static double sMul(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y;
	}
	
	static double vMul(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		if (n != 2) {
			throw new AssertionError();
		}
		Vector c1 = new Vector(nextDouble(), nextDouble());
		Vector c2 = new Vector(nextDouble(), nextDouble());
		double d = c1.sub(c2).len();
		for (int i = 0; i < m; ++i) {
			Vector bucket = new Vector(nextDouble(), nextDouble());
			double r1 = c1.sub(bucket).len();
			double r2 = c2.sub(bucket).len();
			double area;
			if (r1 + d <= r2 + 1e-12) {
				area = Math.PI * r1 * r1;
			} else if (r2 + d <= r1 + 1e-12) {
				area = Math.PI * r2 * r2;
			} else {
				area = aIsect(r1, r2, d) + aIsect(r2, r1, d);
			}
			out.print(area + " ");
		}
		out.println();
	}

	private double aIsect(double r1, double r2, double d) {
		double a = (r1 * r1 - r2 * r2 + d * d) / d / 2.;
		double h = Math.sqrt(Math.max(0., r1 * r1 - a * a));
		double alpha = Math.atan2(h, a);
		return alpha * r1 * r1 - a * h;
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
