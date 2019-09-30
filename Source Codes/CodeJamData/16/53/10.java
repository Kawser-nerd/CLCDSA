import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);
	static final double EPS = 1e-9;
	static double[][] g;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %.9f\n", i, solve());
		}
	}

	static double solve() {
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] X = new int[N];
		int[] Y = new int[N];
		int[] Z = new int[N];
		int[] VX = new int[N];
		int[] VY = new int[N];
		int[] VZ = new int[N];
		for (int i = 0; i < N; ++i) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
			Z[i] = sc.nextInt();
			VX[i] = sc.nextInt();
			VY[i] = sc.nextInt();
			VZ[i] = sc.nextInt();
		}
		g = new double[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				g[i][j] = g[j][i] = Math.sqrt(dist2(X[i] - X[j], Y[i] - Y[j], Z[i] - Z[j]));
			}
		}
		double left = 0;
		double right = 10000;
		for (int i = 0; i < 1000; ++i) {
			double mid = (left + right) / 2;
			if (ok(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return right;
	}

	static boolean ok(double d) {
		ArrayList<Integer> pos = new ArrayList<>();
		boolean[] visited = new boolean[g.length];
		visited[0] = true;
		pos.add(0);
		for (int i = 0; i < pos.size(); ++i) {
			int cur = pos.get(i);
			for (int j = 0; j < g.length; ++j) {
				if (visited[j]) continue;
				if (g[cur][j] > d) continue;
				if (j == 1) return true;
				pos.add(j);
				visited[j] = true;
			}
		}
		return false;
	}

	static double dist2(double dx, double dy, double dz) {
		return dx * dx + dy * dy + dz * dz;
	}

}
