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
	static final int[] dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			//debug(o);
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			char[][] cs = new char[n + 2][m + 2];
			for (int i = 1; i <= n; i++) cs[i] = ("#" + sc.next() + "#").toCharArray();
			fill(cs[0], '#');
			fill(cs[n + 1], '#');
			n += 2;
			m += 2;
			HashMap<Entry, Integer> map = new HashMap<Entry, Integer>();
			int sx = 0, sy = 0;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (cs[i][j] == 'O') {
				sx = i;
				sy = j;
			}
			Entry e = new Entry(sx, sy, -1, -1, -1, -1), f;
			map.put(e, 0);
			PriorityQueue<Pair> que = new PriorityQueue<Pair>();
			que.offer(new Pair(e, 0));
			int ans = -1;
			while (!que.isEmpty()) {
				Pair p = que.poll();
				e = p.e;
				int x = e.x, y = e.y;
				if (cs[x][y] == 'X') {
					ans = p.cost;
					break;
				}
				for (int k = 0; k < 4; k++) {
					int i = 0;
					for (; cs[x + dx[k] * i][y + dy[k] * i] != '#'; i++);
					i--;
					f = new Entry(x, y, x + dx[k] * i, y + dy[k] * i, e.x2, e.y2);
					if (!map.containsKey(f) || map.get(f) > p.cost) {
						map.put(f, p.cost);
						que.offer(new Pair(f, p.cost));
					}
					f = new Entry(x, y, e.x1, e.y1, x + dx[k] * i, y + dy[k] * i);
					if (!map.containsKey(f) || map.get(f) > p.cost) {
						map.put(f, p.cost);
						que.offer(new Pair(f, p.cost));
					}
				}
				if (x == e.x1 && y == e.y1 && e.x2 >= 0) {
					f = new Entry(e.x2, e.y2, e.x1, e.y1, e.x2, e.y2);
					if (!map.containsKey(f) || map.get(f) > p.cost + 1) {
						map.put(f, p.cost + 1);
						que.offer(new Pair(f, p.cost + 1));
					}
				}
				if (x == e.x2 && y == e.y2 && e.x1 >= 0) {
					f = new Entry(e.x1, e.y1, e.x1, e.y1, e.x2, e.y2);
					if (!map.containsKey(f) || map.get(f) > p.cost + 1) {
						map.put(f, p.cost + 1);
						que.offer(new Pair(f, p.cost + 1));
					}
				}
				for (int k = 0; k < 4; k++) {
					if (cs[x + dx[k]][y + dy[k]] != '#') {
						f = new Entry(x + dx[k], y + dy[k], e.x1, e.y1, e.x2, e.y2);
						if (!map.containsKey(f) || map.get(f) > p.cost + 1) {
							map.put(f, p.cost + 1);
							que.offer(new Pair(f, p.cost + 1));
						}
					}
				}
			}
			if (ans < 0) System.out.println("THE CAKE IS A LIE");
			else System.out.println(ans);
		}
	}
	class Entry {
		int x, y, x1, y1, x2, y2;
		Entry(int x, int y, int x1, int y1, int x2, int y2) {
			this.x = x;
			this.y = y;
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + x1;
			result = prime * result + x2;
			result = prime * result + y;
			result = prime * result + y1;
			result = prime * result + y2;
			return result;
		}
		public boolean equals(Object obj) {
			if (this == obj) return true;
			if (obj == null) return false;
			if (!(obj instanceof Entry)) return false;
			final Entry other = (Entry)obj;
			if (x != other.x) return false;
			if (x1 != other.x1) return false;
			if (x2 != other.x2) return false;
			if (y != other.y) return false;
			if (y1 != other.y1) return false;
			if (y2 != other.y2) return false;
			return true;
		}
	}
	class Pair implements Comparable<Pair> {
		Entry e;
		int cost;
		Pair(Entry e, int cost) {
			this.e = e;
			this.cost = cost;
		}
		public int compareTo(Pair o) {
			return cost - o.cost;
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
