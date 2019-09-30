import java.util.Arrays;
import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		long M, F;
		int N;
		Food[] foods;
		long[][] select;
		int si = 0;

		long solve() {
			M = sc.nextLong();
			F = sc.nextLong();
			N = sc.nextInt();
			foods = new Food[N];
			select = new long[N][2]; // day, price
			for (int i = 0; i < N; ++i) {
				long P = sc.nextLong();
				long S = sc.nextLong();
				foods[i] = new Food(S, P);
			}
			Arrays.sort(foods);
			for (int i = 0; i < N; ++i) {
				if (si == 0 || select[si - 1][0] < foods[i].s) {
					select[si][0] = foods[i].s;
					select[si][1] = foods[i].p;
					++si;
				}
			}
			long ans = 0;
			for (int i = 1;; ++i) {
				long days = count(i);
//				System.out.println(i + " " + days);
				if (days == 0) break;
				ans = Math.max(ans, days);
			}
			return ans;
		}

		long count(long deliv) {
			long money = M - F * deliv;
			if (money <= 0) return 0;
			long ret = 0;
			long prev = -1;
			for (int i = 0; i < si; ++i) {
				long all = deliv * (select[i][0] - prev) * select[i][1];
				if (money < all) {
					ret += money / select[i][1];
					break;
				}
				ret += deliv * (select[i][0] - prev);
				money -= all;
				prev = select[i][0];
			}
			return ret;
		}
	}

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			System.out.println(solver.solve());
		}
	}

	static class Food implements Comparable<Food> {
		long s, p;

		Food(long s, long p) {
			this.s = s;
			this.p = p;
		}

		public int compareTo(Food o) {
			if (this.p < o.p) return -1;
			if (this.p > o.p) return 1;
			if (this.s > o.s) return -1;
			if (this.s < o.s) return 1;
			return 0;
		}
	}
}
