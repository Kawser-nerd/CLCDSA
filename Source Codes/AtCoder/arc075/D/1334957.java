import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long[] p10 = new long[19];

	void run() {
		p10[0] = 1;
		for (int i = 1; i < p10.length; ++i) {
			p10[i] = p10[i - 1] * 10;
		}
		Scanner sc = new Scanner(System.in);
		System.out.println(calc(sc.nextLong()));
	}

	long calc(long d) {
		long ans = 0;
		for (int i = 1; i <= 19; ++i) {
			ans += solve(d, i);
		}
		return ans;
	}

	long solve(long d, int len) {
		long comb = 1;
		boolean f = true;

		while (len > 0) {
			long x = -999999;
			boolean update = false;
			if (len != 1) {
				for (long i = -9; i <= 9; ++i) {
					if (d % 10 == i * (p10[len - 1] - 1) % 10
							&& Math.abs(d - i * (p10[len - 1] - 1)) <= p10[len - 1] - 1) {
						x = i;
						if (update)
							throw new AssertionError();
						update = true;
					}
				}
			} else {
				if (d == 0) {
					return comb * (f ? 9 : 10);
				} else {
					return 0;
				}
			}
			if (!update) {
				return 0;
			}
			d -= x * (p10[len - 1] - 1);
			long cnt = 0;
			for (int i = 0; i <= 9; ++i) {
				if (f && i == 0)
					continue;
				if (i + x >= 0 && i + x <= 9) {
					++cnt;
				}
			}
			comb *= cnt;
			f = false;
			len -= 2;
			if (d % 10 != 0) {
				throw new AssertionError();
			}
			if (len > 1) {
				d /= 10;
			}
		}
		if (d != 0) {
			return 0;
		} else {
			return comb;
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}