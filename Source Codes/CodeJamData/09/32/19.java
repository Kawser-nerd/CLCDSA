import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		new Main().run();
		out.close();
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;
	static String fileName = "firefly";

	String nline() {
		try {
			return br.readLine();
		} catch (Exception e) {
			return null;
		}
	}

	String ns() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		} catch (Exception e) {
			return null;
		}
	}

	int ni() {
		return Integer.valueOf(ns());
	}

	long nl() {
		return Long.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}

	double rst(double x, double y, double z) {
		return sqrt(x * x + y * y + z * z);
	}

	public void run() {

		int T = ni();
		for (int tNum = 1; tNum <= T; tNum++) {
			int n = ni();
			double xx = 0, yy = 0, zz = 0;
			double vx = 0, vy = 0, vz = 0;
			for (int i = 0; i < n; i++) {
				double x = nd(), y = nd(), z = nd();
				double v1 = nd(), v2 = nd(), v3 = nd();
				vx += v1;
				vy += v2;
				vz += v3;
				xx += x;
				yy += y;
				zz += z;
			}
			vx /= n;
			vy /= n;
			vz /= n;
			xx /= n;
			yy /= n;
			zz /= n;
			double ans = 0;
			double ansT = 0;
			if (vx == 0 && vy == 0 && vz == 0) {
				ans = rst(xx, yy, zz);
				ansT = 0;
			} else {
				ans = Double.MAX_VALUE;
				double l = 0, r = 1000000;
				for (int i = 0; i < 10000; i++) {
					double med1 = (r - l) / 3.0 + l;
					double med2 = 2.0 * (r - l) / 3.0 + l;
					double r1 = rst(xx + vx * med1, yy + vy * med1, zz + vz
							* med1);
					double r2 = rst(xx + vx * med2, yy + vy * med2, zz + vz
							* med2);
					if (r1 < r2) {
						r = med2;
					} else {
						l = med1;
					}
				}
				ans = min(ans, rst(xx + vx * l, yy + vy * l, zz + vz * l));
				ansT = l;
			}
			out.printf("Case #%d: %.14f %.14f\n", tNum, ans, ansT);
		}

	}
}
