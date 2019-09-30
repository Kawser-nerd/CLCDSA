import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			int[][] ss = new int[n][m], ws = new int[n][m], ts = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ss[i][j] = sc.nextInt();
					ws[i][j] = sc.nextInt();
					ts[i][j] = sc.nextInt();
				}
			}
			long[][] min = new long[n * 2][m * 2];
			for (long[] a : min) fill(a, INF);
			min[n * 2 - 1][0] = 0;
			PriorityQueue<Entry> que = new PriorityQueue<Entry>();
			que.offer(new Entry(n * 2 - 1, 0, 0));
			while (!que.isEmpty()) {
				Entry e = que.poll();
				if (e.t > min[e.x][e.y]) continue;
				for (int d = 0; d < 4; d++) {
					int x2 = e.x + dx[d], y2 = e.y + dy[d];
					if (0 <= x2 && x2 < n * 2 && 0 <= y2 && y2 < m * 2) {
						long t2;
						if (e.x != x2 && e.x / 2 == x2 / 2) {
							t2 = next(ss[e.x / 2][e.y / 2], ws[e.x / 2][e.y / 2], ts[e.x / 2][e.y / 2], e.t, 0) + 1;
						} else if (e.y != y2 && e.y / 2 == y2 / 2) {
							t2 = next(ss[e.x / 2][e.y / 2], ws[e.x / 2][e.y / 2], ts[e.x / 2][e.y / 2], e.t, 1) + 1;
						} else {
							t2 = e.t + 2;
						}
						if (min[x2][y2] > t2) {
							min[x2][y2] = t2;
							que.offer(new Entry(x2, y2, t2));
						}
					}
				}
			}
			System.out.println(min[0][m * 2 - 1]);
		}
	}
	long next(long s, long w, long t, long crt, int dir) {
		t %= s + w;
		long d = (crt - t) % (s + w);
		if (d < 0) d += s + w;
		if (d < s) {
			if (dir == 0) return crt;
			return crt + s - d;
		} else {
			if (dir == 1) return crt;
			return crt + s + w - d;
		}
	}
	int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	long INF = 1L << 60;
	class Entry implements Comparable<Entry> {
		int x, y;
		long t;
		Entry(int x, int y, long t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}
		public int compareTo(Entry e) {
			return Long.signum(t - e.t);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
