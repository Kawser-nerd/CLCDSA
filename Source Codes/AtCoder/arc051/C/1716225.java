import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	final long MOD = 1_000_000_000 + 7;

	class Val implements Comparable<Val> {
		long v;
		long a;
		int c;
		int id;

		// v*pow(a,c)
		public Val(long v_, long a_, int c_, int id_) {
			v = v_;
			a = a_;
			c = c_;
			id = id_;
		}

		public int compareTo(Val val) {
			int c0 = c - Math.min(c, val.c);
			int c1 = val.c - Math.min(c, val.c);
			// v*pow(a,c)-v'*pow(a,c')
			if (c0 == 0 && c1 == 0)
				return Long.compare(v, val.v);
			else {
				long v0 = v;
				long v1 = val.v;
				while (c0 > 0 || c1 > 0) {
					if (c0 > 0) {
						v0 *= a;
						--c0;
						if (v0 > v1)
							return 1;
					}
					if (c1 > 0) {
						v1 *= a;
						--c1;
						if (v0 < v1)
							return -1;
					}
				}
				return Long.compare(v0, v1);
			}
		};

		long out() {
			long ret = 1;
			long res = c;
			long p = a;
			for (; res > 0; res >>= 1, p = p * p % MOD) {
				if (res % 2 == 1) {
					ret = ret * p % MOD;
				}
			}
			ret = ret * v % MOD;
			return ret;
		}
	}

	void solve(int n, long A, long B, long[] a) {

		if (A == 0) {
			for (int i = 0; i < n; ++i) {
				System.out.println(a[i] % MOD);
			}
			return;
		}

		int base = (int) (Math.max(0, B - 5000) / n);
		int res = (int) (B - base * n);
		PriorityQueue<Val> pq = new PriorityQueue<>();
		for (int i = 0; i < n; ++i) {
			pq.add(new Val(a[i], A, 0, i));
		}
		while (res > 0) {
			Val val = pq.poll();
			val.c++;
			pq.add(val);
			--res;
		}
		while (!pq.isEmpty()) {
			Val val = pq.poll();
			val.c += base;
			System.out.println(val.out());
		}
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long A = sc.nextLong();
		long B = sc.nextLong();
		long[] a = new long[N];
		for (int i = 0; i < N; ++i)
			a[i] = sc.nextLong();
		solve(N, A, B, a);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}