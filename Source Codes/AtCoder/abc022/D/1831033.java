import java.awt.geom.Line2D;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ax = new int[n];
		int[] ay = new int[n];

		for (int i = 0; i < n; ++i) {
			ax[i] = sc.nextInt();
			ay[i] = sc.nextInt();
		}
		int[] o1 = convexHull(ax, ay);
		double d1 = 0;
		for (int i = 0; i < o1.length; ++i) {
			double dx = ax[o1[(i + 1) % o1.length]] - ax[o1[i]];
			double dy = ay[o1[(i + 1) % o1.length]] - ay[o1[i]];
			d1 += Math.sqrt(dx * dx + dy * dy);
		}
		for (int i = 0; i < n; ++i) {
			ax[i] = sc.nextInt();
			ay[i] = sc.nextInt();
		}
		o1 = convexHull(ax, ay);
		double d2 = 0;
		for (int i = 0; i < o1.length; ++i) {
			double dx = ax[o1[(i + 1) % o1.length]] - ax[o1[i]];
			double dy = ay[o1[(i + 1) % o1.length]] - ay[o1[i]];
			d2 += Math.sqrt(dx * dx + dy * dy);
		}

		System.out.println(d2 / d1);
	}

	static int[] convexHull(final int[] x, final int[] y) {
		int n = x.length;
		Integer[] ord = new Integer[n];
		for (int i = 0; i < n; ++i) {
			ord[i] = i;
		}
		Arrays.sort(ord, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				if (x[o1] != x[o2])
					return Double.compare(x[o1], x[o2]);
				else
					return Double.compare(y[o1], y[o2]);
			}
		});

		int[] ret = new int[n + 1];
		int p = 0;
		for (int i = 0; i < n; ++i) {
			if (p >= 1 && x[ord[i]] == x[ret[p - 1]] && y[ord[i]] == y[ret[p - 1]])
				continue;
			while (p >= 2 && Line2D.relativeCCW(x[ret[p - 2]], y[ret[p - 2]], x[ret[p - 1]], y[ret[p - 1]], x[ord[i]],
					y[ord[i]]) >= 0)
				--p;
			ret[p++] = ord[i];
		}

		int inf = p + 1;
		for (int i = n - 2; i >= 0; --i) {
			if (x[ord[i]] == x[ret[p - 1]] && y[ord[i]] == y[ret[p - 1]])
				continue;
			while (p >= inf && Line2D.relativeCCW(x[ret[p - 2]], y[ret[p - 2]], x[ret[p - 1]], y[ret[p - 1]], x[ord[i]],
					y[ord[i]]) >= 0)
				--p;
			ret[p++] = ord[i];
		}
		return Arrays.copyOf(ret, p - 1);
	}
}