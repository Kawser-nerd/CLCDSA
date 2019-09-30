import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
 
class Main {
	public static void main(String[] args) {
		new Main().run();
	}
 
	void run() {
		Scanner sc = new Scanner(System.in);
		long[] p1 = { sc.nextLong(), sc.nextLong() };
		long[] p2 = { sc.nextLong(), sc.nextLong() };
		if (p1[0] > p2[0]) {
			long[] tmp = p1;
			p1 = p2;
			p2=tmp;
		}
		int coe = 1;
		if (p1[1] > p2[1]) {
			coe = -1;
			p1[1] *= coe;
			p2[1] *= coe;
		}
		int n = sc.nextInt();
		long[][] p = new long[n][2];
		for (int i = 0; i < n; ++i) {
			p[i][0] = sc.nextLong();
			p[i][1] = sc.nextLong() * coe;
		}
		Arrays.sort(p, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				return Long.compare(o1[0], o2[0]);
			}
		});
		int sz = 0;
		for (int i = 0; i < n; ++i) {
			if (p1[0] <= p[i][0] && p[i][0] <= p2[0] && p1[1] <= p[i][1] && p[i][1] <= p2[1])
				++sz;
		}
		long[] a = new long[sz];
		sz = 0;
		for (int i = 0; i < n; ++i) {
			if (p1[0] <= p[i][0] && p[i][0] <= p2[0] && p1[1] <= p[i][1] && p[i][1] <= p2[1]) {
				a[sz++] = p[i][1];
			}
		}
		long lis = LIS(a.length, a);
		double ans = (p2[0] - p1[0] + p2[1] - p1[1]) * 100 + (Math.PI * 5 - 20) * lis;
		if (lis == Math.min(p2[0] - p1[0] + 1, p2[1] - p1[1] + 1))
			ans += Math.PI * 5;
		System.out.println(String.format("%.20f", ans));
	}
 
	long LIS(int n, long[] a) {
		long[] f = new long[n];
		int sz = 0;
		for (int i = 0; i < n; ++i) {
			if (sz == 0) {
				f[sz] = a[0];
				++sz;
			} else {
				int ok = -1;
				int ng = sz;
				while (ng - ok > 1) {
					int middle = (ok + ng) / 2;
					if (f[middle] < a[i]) {
						ok = middle;
					} else {
						ng = middle;
					}
				}
 
				f[ok + 1] = a[i];
				if (ok + 1 == sz)
					++sz;
			}
		}
		return sz;
	}
 
	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}