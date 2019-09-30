import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	class V {
		long aLen;
		long k;
		long mod;
		long v;

		public V(long aLen_, long mod_) {
			aLen = aLen_;
			k = 1;
			mod = mod_;
			v = 1;
		}

		public V() {
		}

		V merge(V o) {
			V ret = new V();
			ret.mod = mod;
			ret.aLen = aLen;
			ret.k = k + o.k;
			ret.v = (v + o.v * pow(10, aLen * k, mod)) % mod;
			return ret;
		}
	}

	long pow(long a, long n, long mod) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a % mod) {
			if (n % 2 == 1) {
				ret = ret * a % mod;
			}
		}
		return ret;
	}

	long aLen(long a) {
		long aLen = 0;
		while (a > 0) {
			a /= 10;
			++aLen;
		}
		return aLen;
	}

	long f(long a, long l, long b) {
		long aLen = aLen(a);
		V res = new V();
		res.aLen = aLen;
		res.k = 0;
		res.mod = b;
		res.v = 0;
		V p = new V(aLen, b);
		for (; l > 0; l >>= 1, p = p.merge(p)) {
			if (l % 2 == 1) {
				res = res.merge(p);
			}
		}
		return res.v;
	}

	void solve(int n, long[] a, long[] l, long b) {
		long ret = 0;
		for (int i = 0; i < n; ++i) {
			ret = ret * pow(10, aLen(a[i]) * l[i], b) % b;
			ret = (ret + f(a[i], l[i], b) * a[i] % b) % b;
		}
		System.out.println(ret);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		long[] l = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
			l[i] = sc.nextLong();
		}
		long b = sc.nextLong();
		solve(n, a, l, b);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}