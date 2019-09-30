import java.util.*;
import static java.lang.Math.*;
import java.io.*;

public class B {
	static void p(Object...o){System.err.println(Arrays.deepToString(o));}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			int N = in.nextInt();
			double[] V = new double[N];
			for (int i = 0; i < N; i++)
				V[i] = in.nextInt();
			double ans = solve(N, V);
			System.out.format("Case #%d: %.09f\n", zz, ans);
		}
	}
	static double solve(int N, double[] V) {
		double low = 0.0;
		double high = 1000000;
		for (int i = 0; i < 100; i++) {
			double mid = (low + high) / 2;
			if (can(mid, N, V)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
	}
	static boolean can(double E, int N, double[] V) {
		for (int i = 0; i < N; i++) {
			next:
			for (int j = 0; j < 2; j++) {
				double y = V[i] + (j == 0 ? -E : E);
				double minslope = Double.MIN_VALUE;
				double maxslope = Double.MAX_VALUE;
				for (int k = 0; k < N; k++) {
					if (k == i)
						continue;
					for (int m = 0; m < 2; m++) {
						double y2 = V[k] + (m == 0 ? -E : E);
						double slope = (y2 - y) / (k - i);
						if ((m == 0 && k < i) || (m == 1 && k > i)) {
							if (slope < maxslope) {
								maxslope = slope;
								if (maxslope < minslope) {
									continue next;
								}
							}
						} else {
							if (slope > minslope) {
								minslope = slope;
								if (maxslope < minslope) {
									continue next;
								}
							}
						}
					}
				}
				if (minslope <= maxslope)
					return true;
			}
		}
		return false;
	}
}
