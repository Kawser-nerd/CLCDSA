import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	int n;
	int[] x;
	int[] y;
	
	private void solve() {
		n = in.nextInt();
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		p = new int[n + 1];
		mark = new boolean[n];
		mark[0] = true;
		bestArea = -1;
		search(1);
		for (int i = 0; i < n; i++) {
			out.print(" " + bestp[i]);
		}
		out.println();
	}
	
	int[] p;
	boolean[] mark;
	int[] bestp;
	int bestArea;

	int o(int i, int j, int k) {
		return Integer.signum(x[i] * y[j] - x[j] * y[i] +
				x[j] * y[k] - x[k] * y[j] +
				x[k] * y[i] - x[i] * y[k]);
	}
	
	boolean between(int i, int j, int k) {
		return  (x[i] <= x[j] && x[j] <= x[k] || x[i] >= x[j] && x[j] >= x[k])
				&&
				(y[i] <= y[j] && y[j] <= y[k] || y[i] >= y[j] && y[j] >= y[k]);
	}
	
	void search(int i) {
		if (i == n) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (j == k) {
						continue;
					}
					int o1 = o(p[k], p[k + 1], p[j]);
					int o2 = o(p[k], p[k + 1], p[j + 1]);
					if (o1 * o2 == -1) {
						int o3 = o(p[j], p[j + 1], p[k]);
						int o4 = o(p[j], p[j + 1], p[k + 1]);
						if (o3 * o4 == -1) {
							return;
						}
					}
					if (j == (k + 1) % n) {
						continue;
					}
					if (o(p[k], p[k + 1], p[j]) == 0 && between(p[k], p[j], p[k + 1])) {
						return;
					}
				}
			}
			int area = 0;
			for (int j = 0; j < n; j++) {
				area += x[p[j]] * y[p[j + 1]] - x[p[j + 1]] * y[p[j]];
			}
			if (area > bestArea) {
				bestArea = area;
				bestp = p.clone();
			}
		}
		for (int j = 0; j < n; j++) {
			if (mark[j]) {
				continue;
			}
			mark[j] = true;
			p[i] = j;
			search(i + 1);
			mark[j] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new File(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ":");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
