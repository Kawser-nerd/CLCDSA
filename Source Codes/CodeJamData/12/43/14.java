import java.util.Random;
import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		int N;
		int[] x;

		void solve() {
			N = sc.nextInt();
			x = new int[N - 1];
			for (int i = 0; i < N - 1; ++i) {
				x[i] = sc.nextInt() - 1;
			}
			for (int i = 0; i < N - 1; ++i) {
				for (int j = 0; j < i; ++j) {
					if (x[j] > i && x[j] < x[i]) {
						System.out.println("Impossible");
						return;
					}
				}
			}
			int[] h = new int[N];
			Random rand = new Random();
			while (true) {
				for (int i = 0; i < N; ++i) {
					h[i] = rand.nextInt(100000000 + 1);
				}
				boolean success = true;
				for (int i = 0; i < N - 1; ++i) {
					double slopeMax = Integer.MIN_VALUE;
					double mi = 0;
					for (int j = i + 1; j < N; ++j) {
						double slope = 1.0 * (h[j] - h[i]) / (j - i);
						if (slope > slopeMax) {
							slopeMax = slope;
							mi = j;
						}
					}
					if (mi != x[i]) {
						success = false;
						break;
					}
				}
				if (success) {
					for (int i = 0; i < N; ++i) {
						System.out.print(h[i]);
						if (i != N - 1) {
							System.out.print(" ");
						}
					}
					System.out.println();
					return;
				}
			}
		}
	}

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			solver.solve();
		}
	}
}
