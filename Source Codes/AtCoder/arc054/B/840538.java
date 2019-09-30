import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Scanner in = new Scanner(System.in);
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;

	static double f(double x, double p) {
		return x + p/Math.pow(2, x*2/3);
	}

	static void solve() {
		double p = in.nextDouble();
		double l = 0.0, r = Integer.MAX_VALUE/2;

		for (int i=0; i<100; i++) {
			double s = (l*2 + r)/3;
			double t = (l + r*2)/3;
			if (f(s, p) < f(t, p)) {
				r = t;
			} else {
				l = s;
			}
		}
		out.printf("%.10f\n",f((l+r)*0.5, p));
	}

	public static void main(String[] args) {
		debug = args.length > 0;
		long start = System.nanoTime();

		solve();
		out.flush();

		long end = System.nanoTime();
		dump((end - start) / 1000000 + " ms");
		in.close();
		out.close();
	}

	static void dump(Object... o) { if (debug) System.err.println(Arrays.deepToString(o)); }
}