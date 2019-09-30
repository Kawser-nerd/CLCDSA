import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class Main {
	long MOD = 1_000_000_000 + 7;
	long[] fac = new long[200000];
	long[] ifac = new long[200000];
	long[] inv = new long[200000];
	{
		fac[0] = fac[1] = ifac[0] = ifac[1] = inv[0] = inv[1] = 1;
		for (int i = 2; i < fac.length; ++i) {
			fac[i] = i * fac[i - 1] % MOD;
		}
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = MOD - inv[(int) MOD % i] * (MOD / i) % MOD;
		}
		for (int i = 2; i < ifac.length; ++i) {
			ifac[i] = inv[i] * ifac[i - 1] % MOD;
		}
	}
	long n, m;
	int[] f;

	class BIT {
		int n;
		long[] a;

		public BIT(int n_) {
			n = n_;
			a = new long[n + 1];
		}

		void addVal(int k, long val) {
			++k;
			val = (val + MOD) % MOD;
			while (k <= n && k > 0) {
				a[k] += val;
				if (a[k] >= MOD)
					a[k] -= MOD;
				k += k & -k;
			}
		}

		long sum(int k) {
			++k;
			long ret = 0;
			while (k > 0) {
				ret += a[k];
				if (ret >= MOD)
					ret -= MOD;
				k -= k & -k;
			}
			return ret;
		}

	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextLong();
		m = sc.nextLong();
		f = new int[(int) n];
		for (int i = 0; i < n; ++i) {
			f[i] = sc.nextInt();
		}
		BIT bit = new BIT((int) n);
		HashSet<Integer> set = new HashSet<>();
		int s = 0, t = 0;
		for (s = 0; s < n; ++s) {
			while (t < n && !set.contains(f[t])) {
				set.add(f[t]);
				++t;
			}
			long add = bit.sum(s - 1);
			if (s == 0)
				add = 1;
			bit.addVal(s, add);
			bit.addVal(t, -add);
			set.remove(f[s]);
		}
		long ret = bit.sum((int) n - 1);
		ret %= MOD;
		System.out.println(ret);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
}