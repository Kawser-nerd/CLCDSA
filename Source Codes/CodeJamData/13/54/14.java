import java.util.Arrays;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static double[] memo;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			System.out.printf("Case #%d: %.11f\n", t, solve());
		}
	}

	static double solve() {
		String line = sc.next();
		N = line.length();
		memo = new double[1 << N];
		Arrays.fill(memo, -1);
		int st = 0;
		for (int i = 0; i < N; ++i) {
			if (line.charAt(i) == 'X') st |= 1 << i;
		}
		return rec(st);
	}

	static double rec(int st) {
		if (st == (1 << N) - 1) return 0;
		if (memo[st] >= 0) return memo[st];
		double ret = 0;
		for (int i = 0; i < N; ++i) {
			int pos = i;
			int pay = N;
			while (true) {
				if ((st & (1 << pos)) == 0) {
					break;
				}
				++pos;
				--pay;
				if (pos == N) pos = 0;
			}
			ret += rec(st | (1 << pos)) + pay;
		}
		memo[st] = ret / N;
		return memo[st];
	}
}
