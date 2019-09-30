import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class Vector {
		double x, y;
		
		Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		Vector mul(double b) {
			return new Vector(x * b, y * b);
		}
		
		Vector add(Vector b) {
			return new Vector(x + b.x, y + b.y);
		}
		
		Vector sub(Vector b) {
			return new Vector(x - b.x, y - b.y);
		}
		
		double len2() {
			return x * x + y * y;
		}
		
		double len() {
			return Math.sqrt(len2());
		}
		
		Vector norm() {
			return mul(1. / len());
		}

		public Vector rot() {
			return new Vector(-y, x);
		}
		
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}
	
	static final String filename = "D-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		int n = nextInt();
		Vector[] cs = new Vector[n];
		double[] rs = new double[n];
		double max = 0.;
		for (int i = 0; i < n; ++i) {
			cs[i] = new Vector(nextDouble(), nextDouble());
			rs[i] = nextDouble();
			max = Math.max(max, rs[i]);
		}
		double l = max, r = 1000000;
		for (int it = 0; it < 100; ++it) {
			double mid = (l + r) / 2.;
			if (can(cs, rs, mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		out.println(r);
	}
	
	final double EPS = 1e-8;
	
	private ArrayList<Vector> getPS(Vector[] cs, double[] rs, double mid) {
		int n = cs.length;
		ArrayList<Vector> ps = new ArrayList<Vector>();
		for (int i = 0; i < n; ++i) {
			ps.add(cs[i]);
			for (int j = i + 1; j < n; ++j) {
				Vector a = cs[i];
				Vector b = cs[j];
				double ra = mid - rs[i];
				double rb = mid - rs[j];
				Vector v = b.sub(a);
				double d = v.len();
				if (d < EPS) {
					continue;
				}
				v = v.norm();
				Vector v2 = v.rot();
				double x = (ra * ra - rb * rb + d * d) / (2. * d);
				if (x * x > ra * ra + EPS) {
					continue;
				}
				double y = Math.sqrt(Math.max(0., ra * ra - x * x));
				ps.add(a.add(v.mul(x)).add(v2.mul(y)));
				ps.add(a.add(v.mul(x)).sub(v2.mul(y)));
			}
		}
		return ps;
	}
	
	private boolean can(Vector[] cs, double[] rs, double r) {
		int n = cs.length;
		for (Vector v : getPS(cs, rs, r)) {
			ArrayList<Vector> list = new ArrayList<Vector>();
			ArrayList<Double> listrs = new ArrayList<Double>();
			for (int i = 0; i < n; ++i) {
				if (cs[i].sub(v).len() + rs[i] > r + EPS) {
					list.add(cs[i]);
					listrs.add(rs[i]);
				}
			}
			if (can2(list.toArray(new Vector[0]), toArr(listrs), r)) {
				return true;
			}
		}
		return false;
	}
	
	private boolean can2(Vector[] cs, double[] rs, double r) {
		int n = cs.length;
		if (n == 0) {
			return true;
		}
		loop: for (Vector v : getPS(cs, rs, r)) {
			for (int i = 0; i < n; ++i) {
				if (cs[i].sub(v).len() + rs[i] > r + EPS) {
					continue loop;
				}
			}
			return true;
		}
		return false;
	}

	private double[] toArr(ArrayList<Double> list) {
		double[] r = new double[list.size()];
		for (int i = 0; i < r.length; ++i) {
			r[i] = list.get(i);
		}
		return r;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out2");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				System.out.println(test);
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
