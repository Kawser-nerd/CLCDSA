import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static long B;
	static long[] X;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			System.out.printf("Case #%d: %.7f\n", t, solve());
		}
	}

	static double solve() {
		B = sc.nextLong();
		N = sc.nextInt();
		X = new long[37];
		for (int i = 0; i < N; ++i) {
			X[i] = sc.nextLong();
		}
		Arrays.sort(X);
		ArrayList<State> sts = new ArrayList<State>();
		for (int i = 0; i < 37;) {
			int start = i;
			while (i < 37 && X[i] == X[start]) {
				++i;
			}
			sts.add(new State(X[start], i - start));
		}
		double ans = 0;
		for (int i = 0; i < sts.size(); ++i) {
			long height = sts.get(i).h;
			long all = 0;
			int width = 0;
			for (int j = 0; j < i; ++j) {
				all += (height - sts.get(j).h) * sts.get(j).c;
				width += sts.get(j).c;
			}
			width += sts.get(i).c;
			//			System.out.println(height + " " + all + " " + width);
			for (int j = 0; j < width; ++j) {
				if (all + j > B) break;
				double exp = 0;
				for (int k = 0; k < width - j; ++k) {
					exp += 36.0 * (height - X[k]) / (width - j);
				}
				long mh = i >= sts.size() - 1 ? 0 : sts.get(i + 1).h - sts.get(i).h - 1;
				long ma = Math.min(mh, (B - all - j) / width);
				exp += ma * 36.0;
				exp -= all + ma * width + j;
				ans = Math.max(ans, exp);
			}
		}
		return ans;
	}

	static class State {
		long h;
		int c;

		public State(long h, int c) {
			this.h = h;
			this.c = c;
		}

	}

}