import java.util.Arrays;
import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		int N;
		int[] L, P;

		void solve() {
			N = sc.nextInt();
			L = new int[N];
			P = new int[N];
			for (int i = 0; i < N; ++i) {
				L[i] = sc.nextInt();
			}
			for (int i = 0; i < N; ++i) {
				P[i] = sc.nextInt();
			}
			Stage[] stages = new Stage[N];
			for (int i = 0; i < N; ++i) {
				stages[i] = new Stage(L[i], P[i], i);
			}
			Arrays.sort(stages);
			for (int i = 0; i < N; ++i) {
				System.out.print(stages[i].idx);
				if (i != N - 1) {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}

	static class Stage implements Comparable<Stage> {
		int l, p, idx;

		Stage(int l, int p, int idx) {
			this.l = l;
			this.p = p;
			this.idx = idx;
		}

		public int compareTo(Stage o) {
			return o.l * o.p - this.l * this.p;
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
