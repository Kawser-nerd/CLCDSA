import java.util.*;
import java.io.*;

public class Template implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String name = "A-large";
	
	static class Vector {
		double x, y;
		
		Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		Vector diff(Vector b) {
			return new Vector(x - b.x, y - b.y);
		}
		
		double len() {
			return Math.sqrt(x * x + y * y);
		}

		public Vector mul(double scale) {
			return new Vector(x * scale, y * scale);
		}

		public Vector rot(double sin, double cos) {
			return new Vector(cos * x + sin * y, -sin * x + cos * y);
		}
		
		public String toString() {
			return x + " " + y;
		}

		public Vector add(Vector b) {
			return new Vector(x + b.x, y + b.y);
		}
	}
	
	static double sMul(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y;
	}
	
	static double vMul(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			Vector[] a = new Vector[3];
			for (int i = 0; i < 3; ++i) {
				a[i] = new Vector(nextDouble(), nextDouble());
			}
			Vector[] b = new Vector[3];
			for (int i = 0; i < 3; ++i) {
				b[i] = new Vector(nextDouble(), nextDouble());
			}
			Vector va = a[1].diff(a[0]);
			Vector vb = b[1].diff(b[0]);
			double scale = vb.len() / va.len();
			double sin = vMul(va, vb) / va.len() / vb.len();
			double cos = sMul(va, vb) / va.len() / vb.len();
			Vector x = b[0].add(b[1]).add(b[2]).mul(1.0 / 3.0);
			for (int it = 0; it < 1000000; ++it) {
				x = x.diff(a[0]).mul(scale).rot(-sin, cos).add(b[0]);
			}
//			for (int i = 0; i < 3; ++i) {
//				System.out.println(b[i].diff(a[i].diff(a[0]).mul(scale).rot(-sin, cos).add(b[0])));
//			}
			System.out.println(x.diff(x.diff(a[0]).mul(scale).rot(-sin, cos).add(b[0])));
//			System.out.println(scale);
//			System.out.println();
			if (in(a, x) && in(b, x)) {
				out.println("Case #" + test + ": " + x);
//				System.out.println(x);
			} else {
				out.println("No Solution");
//				System.out.println("No Solution");
			}
		}
	}

	private boolean in(Vector[] a, Vector x) {
		double s = 0, s0 = 0;
		for (int i = 0; i < 3; ++i) {
			double cur = vMul(a[i].diff(x), a[(i + 1) % 3].diff(x));
			s += Math.abs(cur);
			s0 += cur;
		}
		return Math.abs(s - Math.abs(s0)) < 1e-8;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(name + ".out");
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
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

	public static void main(String[] args) {
		new Thread(new Template()).start();
	}

}
