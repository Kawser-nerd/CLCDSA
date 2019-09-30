import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long n;
		long k;
		n = sc.nextLong();
		k = sc.nextLong();
		System.out.println(solve(n, k));
	}

	final long MOD = 1_000_000_000 + 7;

	long solve(long n, long k) {
		if (k == 1) {
			return n % MOD * (n + 1) % MOD * inv(2) % MOD;
		}
		long[][] p = new long[2][9];
		int q = 0;
		{
			long k_ = k;
			for (long i = 2; i * i <= k_; ++i) {
				int c = 0;
				while (k_ % i == 0) {
					k_ /= i;
					++c;
				}
				if (c > 0) {
					p[0][q] = i;
					p[1][q] = c;
					++q;
				}
			}
			if (k_ > 1) {
				p[0][q] = k_;
				p[1][q] = 1;
				++q;
			}
			p[0] = Arrays.copyOf(p[0], q);
			p[1] = Arrays.copyOf(p[1], q);
		}
		tmp = Arrays.copyOf(tmp, q);
		return (dfs(0, p, k, n));
	}

	int[] tmp = new int[9];

	long dfs(int idx, long[][] p, long k, long n) {
		long ret = 0;
		for (int i = 0; i <= p[1][idx]; ++i) {
			tmp[idx] = i;
			if (idx + 1 < tmp.length) {
				ret += dfs(idx + 1, p, k, n);
			} else {
				ret += f(p, k, n);
			}
			ret %= MOD;
		}
		return ret;
	}

	long f(long[][] p, long k, long n) {
		long div = 1;
		for (int i = 0; i < tmp.length; ++i) {
			div = div * pow(p[0][i], tmp[i]);
		}
		n /= div;
		long ret = 0;
		out: for (int s = 0; s < 1 << tmp.length; ++s) {
			long t = 1;
			int c = 0;
			for (int i = 0; i < tmp.length; ++i) {
				if (((s >> i) & 1) == 1) {
					if (p[1][i] - tmp[i] == 0)
						continue out;
					t = t * p[0][i];
					++c;
				}
			}
			ret += pow(-1, c) * t % MOD * (1 + (n / t)) % MOD * (n / t) % MOD * inv(2) % MOD;
			ret = (ret + MOD) % MOD;
		}
		ret = ret * k % MOD;
		return ret;
	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a) {
			if (n % 2 == 1) {
				ret = ret * a;
			}
		}
		return ret;
	}

	long mod_pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a % MOD) {
			if (n % 2 == 1) {
				ret = ret * a % MOD;
			}
		}
		return ret;
	}

	long inv(long a) {
		return mod_pow(a, MOD - 2);
	}

	long lcm(long a, long b) {
		return a / gcd(a, b) * b % MOD;
	}

	long gcd(long a, long b) {
		if (a > b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}