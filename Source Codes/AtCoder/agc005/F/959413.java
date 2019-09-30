import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		solver();
	}

	final long MODULO = 924844033;
	final long root = 5;
	int[] size;
	ArrayList<Integer>[] g;

	void solver() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		size = new int[n + 1];
		g = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; ++i) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			g[a].add(b);
			g[b].add(a);
		}

		dfs(-1, 0);

		int[] a = new int[n + 1];
		for (int i = 1; i < n; ++i) {
			++a[size[i]];
			++a[n - size[i]];
		}
		// b_i=1/(n-i)!,b_(n-i+k)=1/(i-k)!
		// n*nCk-1/(k!)*Sum{a_i*i!/(i-k)!}
		// n*nCk-1/(k!)*sum{a_i*b_(n-i+k)} iCk
		// 3*3C1 - 1/1!*{b_i*iC0}
		// 9 - 1/1* (2 * 2C1 + 2*1C1), n-1+1,b_n=1/0!
		// 9 - 1/1 * 6
		// a_i*i! = a_1*1!
		// a_2*2!=2*2=4
		// b_(n-2+2)
		// b_n, b_n=1
		long[] fac = new long[n + 1];
		long[] invfac = new long[n + 1];
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fac[i] = (fac[i - 1] * i) % MODULO;
		}
		invfac[n] = inv(fac[n]);
		for (int i = n - 1; i >= 0; --i) {
			invfac[i] = (invfac[i + 1] * (i + 1)) % MODULO;
		}
		long[] f = new long[n + 1];
		long[] h = new long[n + 1];
		for (int i = 0; i <= n; ++i) {
			f[i] = a[i] * fac[i] % MODULO;
			h[i] = invfac[n - i];
		}
		f = mul(f, h);
		for (int k = 1; k <= n; ++k) {
			long ans = n * fac[n] % MODULO * invfac[n - k] % MODULO * invfac[k] % MODULO;
			ans -= inv(fac[k]) * f[n + k] % MODULO;
			if (ans < 0)
				ans += MODULO;
			System.out.println(ans);
		}

	}

	void dfs(int pre, int cur) {
		size[cur] = 1;
		for (int dst : g[cur]) {
			if (dst != pre) {
				dfs(cur, dst);
				size[cur] += size[dst];
			}
		}
	}

	long[] mul(long[] a, long[] b) {
		int n = Integer.highestOneBit(a.length + b.length) << 1;
		a = Arrays.copyOf(a, n);
		b = Arrays.copyOf(b, n);
		a = fft(a, false);
		b = fft(b, false);
		for (int i = 0; i < n; ++i) {
			a[i] = (a[i] * b[i]) % MODULO;
		}
		a = fft(a, true);
		long inv = pow(n, MODULO - 2);
		for (int i = 0; i < n; ++i) {
			a[i] = (a[i] * inv) % MODULO;
		}
		return a;
	}

	long[] fft(long[] a, boolean inv) {
		int n = a.length;
		int c = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = n >> 1; j > (c ^= j); j >>= 1)
				;
			if (c > i) {
				long d = a[c];
				a[c] = a[i];
				a[i] = d;
			}
		}

		for (int i = 1; i < n; i *= 2) {
			long w = pow(root, (MODULO - 1) / (2 * i));
			if (inv)
				w = pow(w, MODULO - 2);
			for (int j = 0; j < n; j += 2 * i) {
				long wn = 1;
				for (int k = 0; k < i; ++k) {
					long u = a[k + j];
					long v = (a[k + j + i] * wn) % MODULO;
					a[k + j] = (u + v) % MODULO;
					a[k + j + i] = (u - v + MODULO) % MODULO;
					wn = (wn * w) % MODULO;
				}
			}
		}
		return a;
	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = (a * a) % MODULO) {
			if (n % 2 == 1) {
				ret = (ret * a) % MODULO;
			}
		}
		return ret;
	}

	long inv(long a) {
		return pow(a, MODULO - 2);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.