import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	int sort;
	
	private void solve() {
		int n = in.nextInt();
		double wid = in.nextInt();
		double hei = in.nextInt();
		Circle[] c = new Circle[n];
		for (int i = 0; i < n; i++) {
			c[i] = new Circle(i, in.nextInt());
		}
		sort = 1;
		Arrays.sort(c);
		if (solve(c, wid, hei, false, 0)) return;
		if (solve(c, wid, hei, true, 1)) return;
		sort = -1;
		Arrays.sort(c);
		if (solve(c, wid, hei, false, 2)) return;
		if (solve(c, wid, hei, true, 3)) return;
		throw new RuntimeException("Not solved");
	}
	
	private boolean solve(Circle[] c, double wid, double hei, boolean b, int heur) {
		int n = c.length;
		double[] ansx = new double[n];
		double[] ansy = new double[n];
		double px = -1e10;
		double py = -c[0].r;
		double qx = 0;
		double hh = b ? wid : hei;
		for (int i = 0; i < n; i++) {
			double y = py + c[i].r;
			double x = Math.max(px + c[i].r, 0);
			if (y > hh) {
				y = 0;
				px = qx;
				x = qx + c[i].r;
				py = y + c[i].r;
			} else {
				py = y + c[i].r;
			}
			qx = x + c[i].r;
			if (!b) {
				ansx[c[i].id] = x;
				ansy[c[i].id] = y;
			} else {
				ansx[c[i].id] = y;
				ansy[c[i].id] = x;
			}
		}
		for (int i = 0; i < n; i++) {
			if (ansx[i] < 0) return false;
			if (ansy[i] < 0) return false;
			if (ansx[i] > wid) return false;
			if (ansy[i] > hei) return false;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				double d = Math.hypot(ansx[c[i].id] - ansx[c[j].id], ansy[c[i].id] - ansy[c[j].id]);
				if (d < c[i].r) {
					return false;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(" " + (long) ansx[i] + " " + (long) ansy[i]);
		}
		out.println();
		System.out.println("solved with heur " + heur);
		return true;
	}

	class Circle implements Comparable<Circle> {
		int id;
		double r;

		public Circle(int id, double r) {
			this.id = id;
			this.r = r;
		}

		@Override
		public int compareTo(Circle o) {
			return Double.compare(r * sort, o.r * sort);
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ":");
			new B().solve();
			System.out.println("Case #" + t + ": done");
		}
		in.close();
		out.close();
	}
}
