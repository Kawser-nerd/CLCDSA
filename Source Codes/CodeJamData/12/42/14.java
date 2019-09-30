import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		int N, W, L;
		int[] r;

		void solve() {
			N = sc.nextInt();
			W = sc.nextInt();
			L = sc.nextInt();
			r = new int[N];
			int maxr = 0;
			int maxi = 0;
			for (int i = 0; i < N; ++i) {
				r[i] = sc.nextInt();
				if (r[i] > maxr) {
					maxr = r[i];
					maxi = i;
				}
			}
			double[] x = new double[N];
			double[] y = new double[N];
			Random rand = new Random();
			Arrays.fill(x, -1);
			Arrays.fill(y, -1);
			x[maxi] = 0;
			y[maxi] = 0;
			OUT: while (true) {
				for (int i = 0; i < N; ++i) {
					if (i == maxi) continue;
					boolean success = false;
					for (int t = 0; t < 100; ++t) {
						x[i] = rand.nextDouble() * W;
						y[i] = rand.nextDouble() * L;
						if (sq(x[i] - x[maxi], y[i] - y[maxi]) <= sq(r[i] + r[maxi])) continue;
						boolean ok = true;
						for (int j = 0; j < i; ++j) {
							if (sq(x[i] - x[j], y[i] - y[j]) <= sq(r[i] + r[j])) {
								ok = false;
								break;
							}
						}
						if (ok) {
							success = true;
							break;
						}
					}
					if (!success) {
//						System.out.println(i);
						continue OUT;
					}
				}
				for (int i = 0; i < N; ++i) {
					System.out.printf("%f %f", x[i], y[i]);
					if (i != N - 1) System.out.print(" ");
				}
				System.out.println();
				return;
			}
		}

		double sq(double x, double y) {
			return x * x + y * y;
		}

		double sq(double r) {
			return r * r;
		}
	}

	public static void main(String[] args) {
//		Random rand = new Random();
//		int[] r = new int[1000];
//		for (int c = 0; c < 10; ++c) {
//			double S = 0;
//			for (int i = 0; i < 1000; ++i) {
//				r[i] = rand.nextInt(200) + 1;
//				S += Math.PI * r[i] * r[i];
//			}
//			int L = (int) Math.ceil(Math.sqrt(S * 5));
//			System.out.println("1000 " + L + " " + L);
//			for (int i = 0; i < 1000; ++i) {
//				System.out.print(r[i] + " ");
//			}
//			System.out.println();
//		}
//		System.exit(0);
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			solver.solve();
		}
	}
}
