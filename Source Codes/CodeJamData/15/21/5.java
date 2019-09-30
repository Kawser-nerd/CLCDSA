import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			long N = sc.nextLong();
			System.out.printf("Case #%d: %d\n", i, solve(N));
		}
	}

	static long solve(long v) {
		if (v <= 10) return v;
		int len = ("" + v).length();
		long mod = 1;
		for (int i = 0; i < len / 2; ++i) {
			mod *= 10;
		}
		if (v % mod == 0) return solve(v - 1) + 1;
		long add = v % mod - 1;
		v -= add;
		long rev = 0;
		long tmp = v;
		while (tmp > 0) {
			rev *= 10;
			rev += tmp % 10;
			tmp /= 10;
		}
		if (rev != v) return solve(rev) + add + 1;
		return solve(v - 1) + add + 1;
	}

}
