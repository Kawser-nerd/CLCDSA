import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;

public class Main {
	public static void main(String[] args) {
		new Main().solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		--a;
		--b;
		long[] x = new long[n];
		long[] y = new long[n];
		ArrayList<Point> ps = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
			ps.add(new Point(x[i] + y[i], x[i] - y[i], i));
		}
		long D = Math.abs(x[a] - x[b]) + Math.abs(y[a] - y[b]);
		int[] cnt = new int[n];
		DJSet ds = new DJSet(n);
		for (int dir = 0; dir < 2; ++dir) {
			Collections.sort(ps);
			int[] cum = new int[2 * n];
			for (int i = 0; i < n; ++i) {
				pre(ps, ps.get(i), D, cnt, cum, ds, dir);

			}
			for (int i = 1; i < cum.length; ++i) {
				cum[i] += cum[i - 1];
			}
			for (int i = 0; i + 1 < n; ++i) {
				if (cum[2 * i + 1] > 0) {
					ds.setUnion(ps.get(i).id, ps.get(i + 1).id);
				}
			}
			for (int i = 0; i < n; ++i) {
				ps.get(i).rotate();
			}
		}

		long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (ds.equiv(i, a)) {
				ans += cnt[i];
			}
		}
		System.out.println(ans / 2);
	}

	void pre(ArrayList<Point> list, Point p, long D, int[] cnt, int[] cum, DJSet ds, int dir) {
		{
			int r = lower(list, new Point(p.x + D + 1 - (dir), p.y + D, -1));
			int l = lower(list, new Point(p.x - D + (dir), p.y + D, -1));
			cnt[p.id] += r - l;
			if (r > l) {
				if (r - l > 1) {
					if (2 * (l + 1) + 1 < cum.length)
						++cum[2 * (l + 1) + 1];
					if (2 * r < cum.length)
						--cum[2 * r];
				}
				ds.setUnion(p.id, list.get(r).id);
			}

		}
		{
			int r = lower(list, new Point(p.x + D + 1 - (dir), p.y - D, -1));
			int l = lower(list, new Point(p.x - D + (dir), p.y - D, -1));
			cnt[p.id] += r - l;
			if (r > l) {
				if (r - l > 1) {
					if (2 * (l + 1) + 1 < cum.length)
						++cum[2 * (l + 1) + 1];
					if (2 * r < cum.length)
						--cum[2 * r];
				}
				ds.setUnion(p.id, list.get(r).id);
			}
		}
		return;
	}

	int lower(ArrayList<Point> list, Point p) {
		// 0 0 1 1 2 3
		// p = 1 ?? 1???0?????

		int ok = -1, ng = list.size();
		while (ng - ok > 1) {
			int middle = (ok + ng) / 2;
			if (list.get(middle).compareTo(p) < 0) {
				ok = middle;
			} else {
				ng = middle;
			}
		}
		return ok;
	}

	class Point implements Comparable<Point> {
		long x, y;
		int id;

		public Point(long x_, long y_, int id_) {
			x = x_;
			y = y_;
			id = id_;
		}

		void rotate() {
			long d = x;
			x = y;
			y = d;
		}

		@Override
		public int compareTo(Point o) {
			if (y != o.y) {
				return Long.compare(y, o.y);
			} else {
				return Long.compare(x, o.x);
			}
		}
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n_) {
			n = n_;
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (upper[x] < upper[y]) {
				int d = x;
				x = y;
				y = d;
			}
			upper[y] += upper[x];
			upper[x] = y;
		}
	}

	public static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}