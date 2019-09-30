import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int t = 1; t <= n; t++) {
			int time = sc.nextInt();
			int na = sc.nextInt(), nb = sc.nextInt();
			int[] num = new int[2];
			Entry[] es = new Entry[na + nb];
			for (int i = 0; i < na; i++) es[i] = new Entry(to(sc.next()), to(sc.next()), 0);
			for (int i = 0; i < nb; i++) es[na + i] = new Entry(to(sc.next()), to(sc.next()), 1);
			sort(es);
			PriorityQueue<Integer>[] qs = new PriorityQueue[2];
			for (int i = 0; i < 2; i++) {
				qs[i] = new PriorityQueue<Integer>();
				qs[i].offer(1 << 29);
			}
			for (Entry e : es) {
				if (qs[e.pos].peek() > e.from) num[e.pos]++;
				else qs[e.pos].poll();
				qs[1 - e.pos].offer(e.to + time);
			}
			System.out.printf("Case #%d: %d %d%n", t, num[0], num[1]);
		}
	}
	int to(String s) {
		return Integer.parseInt(s.split(":")[0]) * 60 + Integer.parseInt(s.split(":")[1]);
	}
	class Entry implements Comparable<Entry> {
		int from, to, pos;
		Entry(int from, int to, int pos) {
			this.from = from;
			this.to = to;
			this.pos = pos;
		}
		public int compareTo(Entry o) {
			return from - o.from;
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
