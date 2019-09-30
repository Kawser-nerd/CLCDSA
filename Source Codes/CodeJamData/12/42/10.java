import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N, W, L;
	int[] rs;
	
	void read() {
		N = sc.nextInt();
		W = sc.nextInt();
		L = sc.nextInt();
		rs = new int[N];
		for (int i = 0; i < N; i++) rs[i] = sc.nextInt();
//		Random rand = new Random();
//		N = 1000;
//		rs = new int[N];
//		for (int i = 0; i < N; i++) rs[i] = rand.nextInt(100000) + 1;
//		long sq = 0;
//		for (int i = 0; i < N; i++) sq += (long)rs[i] * rs[i];
//		sq = (long)ceil(sq * 5 * PI);
//		W = rand.nextInt((int)ceil(sqrt(sq)) + 1);
//		L = (int)((sq + W - 1) / W);
	}
	
	void solve() {
		Entry[] es = new Entry[N];
		for (int i = 0; i < N; i++) es[i] = new Entry(i, rs[i]);
		sort(es);
		int[] inv = new int[N];
		for (int i = 0; i < N; i++) rs[i] = es[i].r;
		for (int i = 0; i < N; i++) inv[es[i].id] = i;
		int[] xs = new int[N], ys = new int[N];
		int dir = 1;
		int x = 0;
		for (int i = 0; i < N; i++) {
			int y = 0;
			for (int j = 0; j < i; j++) if (max(xs[j] - rs[j], x - rs[i]) < min(xs[j] + rs[j], x + rs[i])) {
				y = max(y, ys[j] + rs[j] + rs[i]);
			}
			if (y > L) {
				debug("orz", i, x);
				throw null;
			}
			xs[i] = x;
			ys[i] = y;
			if (i + 1 < N) {
				int x2 = x + dir * (rs[i] + rs[i + 1]);
				if (0 <= x2 && x2 <= W) {
					x = x2;
				} else {
					if (x2 < 0) {
						x = 0;
						dir = 1;
					} else {
						x = W;
						dir = -1;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (i > 0) System.out.print(" ");
			System.out.print(xs[inv[i]] + " " + ys[inv[i]]);
		}
		System.out.println();
	}
	
	class Entry implements Comparable<Entry> {
		int id, r;
		Entry(int id, int r) {
			this.id = id;
			this.r = r;
		}
		@Override
		public int compareTo(Entry e) {
			return r - e.r;
		}
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
