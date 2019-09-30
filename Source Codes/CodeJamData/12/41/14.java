import java.util.Arrays;
import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		int N;
		int[] ds;
		int[] ls;
		int D;

		boolean solve() {
			N = sc.nextInt();
			ds = new int[N];
			ls = new int[N];
			for (int i = 0; i < N; ++i) {
				ds[i] = sc.nextInt();
				ls[i] = sc.nextInt();
			}
			D = sc.nextInt();
			int[] reach = new int[N];
			Arrays.fill(reach, -1);
			if (ds[0] > ls[0]) return false;
			reach[0] = ds[0];
			for (int i = 0; i < N; ++i) {
				if (reach[i] < 0) continue;
				if (reach[i] >= D - ds[i]) return true;
				for (int j = i + 1; j < N; ++j) {
					if (reach[j] >= 0) continue;
					if (ds[j] > ds[i] + reach[i]) break;
					//					if (ds[j] - ds[i] > ls[j]) continue;
					reach[j] = Math.min(ds[j] - ds[i], ls[j]);
				}
			}
			return false;
		}
	}

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			System.out.println(solver.solve() ? "YES" : "NO");
		}
	}
}
