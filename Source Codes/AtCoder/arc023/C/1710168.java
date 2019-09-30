import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	final long MOD = 1_000_000_000 + 7;

	long[] fac = new long[4000];
	long[] invfac = new long[4000];
	long[] inv = new long[4000];
	{
		fac[0] = fac[1] = 1;
		invfac[0] = invfac[1] = 1;
		inv[0] = inv[1] = 1;
		for (int i = 2; i < fac.length; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[(int) (MOD % i)] * (MOD / i) % MOD;
			invfac[i] = invfac[i - 1] * inv[i] % MOD;
		}
	}

	long c(long n, long k) {
		if (n < 4000 && k < 4000 && n - k < 4000)
			return fac[(int) n] * invfac[(int) (n - k)] % MOD * invfac[(int) k] % MOD;
		else {
			long ret = 1;
			for (long i = n; i >= n - k + 1; --i) {
				ret = ret * i % MOD;
			}
			for (int i = 2; i <= k; ++i) {
				ret = ret * inv[i] % MOD;
			}
			return ret;
		}
	}

	public void run() {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
		}
		long ans = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] > 0)
				continue;
			int j = i;
			while (j + 1 < n && a[j + 1] == -1)
				++j;
			int c = j - i + 1;// -1??
			ans = ans * c(a[j + 1] - a[i - 1] + c, c) % MOD;
			i = j;
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}