import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Scanner in = new Scanner(System.in);
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;

	static void solve() {
		double l = in.nextInt();
		double x = in.nextInt();
		double y = in.nextInt();
		double s = in.nextInt();
		double d = in.nextInt();

		if (s < d) {
			if (x < y) {
				out.printf("%.10f\n", Math.min((d-s)/(x+y),  (l - (d-s))/(y-x)));
			} else {
				out.printf("%.10f\n", (d-s)/(x+y));
			}
		} else if (s > d) {
			if (x < y) {
				out.printf("%.10f\n", Math.min((l-(s-d))/(x+y),  (s-d)/(y-x)));
			} else {
				out.printf("%.10f\n", (l-(s-d))/(x+y));
			}
		} else {
			out.println("0");
		}
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