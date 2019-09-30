import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.math.BigInteger.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int N, M;
	char[][] cs;
	
	void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		cs = new char[N][];
		for (int i = 0; i < N; i++) cs[i] = sc.next().toCharArray();
	}
	
	void solve(int sx, int sy) {
		boolean[][] can = new boolean[N][M];
		can[sx][sy] = true;
		int ID = 1;
		for (int x = N - 1; x >= 0; x--) {
			for (int y = 0; y < M - 1; y++) {
				if (can[x][y] && !can[x][y + 1] && cs[x][y + 1] != '#') {
					can[x][y + 1] = true;
					ID++;
				}
			}
			for (int y = M - 1; y > 0; y--) {
				if (can[x][y] && !can[x][y - 1] && cs[x][y - 1] != '#') {
					can[x][y - 1] = true;
					ID++;
				}
			}
			if (x > 0) {
				for (int y = 0; y < M; y++) {
					if (can[x][y] && !can[x - 1][y] && cs[x - 1][y] != '#') {
						can[x - 1][y] = true;
						ID++;
					}
				}
			}
		}
		System.out.print(ID + " ");
		TreeSet<Entry> visit = new TreeSet<Entry>();
		Queue<Entry> que = new LinkedList<Entry>();
		long[] bs = new long[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) if (can[i][j]) {
				bs[i] |= 1 << j;
			}
		}
		Entry e = new Entry(bs);
		visit.add(e);
		que.offer(e);
		while (!que.isEmpty()) {
			e = que.poll();
			bs = e.bs;
			boolean goal = true;
			for (int i = 0; i < N; i++) {
				if (i == sx) {
					if (bs[i] != 1 << sy) {
						goal = false;
					}
				} else if (bs[i] != 0) {
					goal = false;
				}
			}
			if (goal) {
				System.out.println("Lucky");
				return;
			}
			left : {
				long[] bs2 = new long[N];
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) if ((bs[i] >> j & 1) != 0) {
						int i2 = i, j2 = j - 1;
						if (j2 < 0 || j2 >= M || cs[i2][j2] == '#') j2 = j;
						if (!can[i2][j2]) break left;
						bs2[i2] |= 1 << j2;
					}
				}
				Entry e2 = new Entry(bs2);
				if (visit.add(e2)) que.offer(e2);
			}
			right : {
				long[] bs2 = new long[N];
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) if ((bs[i] >> j & 1) != 0) {
						int i2 = i, j2 = j + 1;
						if (j2 < 0 || j2 >= M || cs[i2][j2] == '#') j2 = j;
						if (!can[i2][j2]) break right;
						bs2[i2] |= 1 << j2;
					}
				}
				Entry e2 = new Entry(bs2);
				if (visit.add(e2)) que.offer(e2);
			}
			down : {
				long[] bs2 = new long[N];
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) if ((bs[i] >> j & 1) != 0) {
						int i2 = i + 1, j2 = j;
						if (i2 >= N || cs[i2][j2] == '#') i2 = i;
						if (!can[i2][j2]) break down;
						bs2[i2] |= 1 << j2;
					}
				}
				Entry e2 = new Entry(bs2);
				if (visit.add(e2)) que.offer(e2);
			}
		}
		System.out.println("Unlucky");
	}
	
	class Entry implements Comparable<Entry> {
		long[] bs;
		Entry(long[] bs) {
			this.bs = bs;
		}
		public int compareTo(Entry o) {
			for (int i = 0; i < bs.length; i++) if (bs[i] != o.bs[i]) {
				return Long.signum(bs[i] - o.bs[i]);
			}
			return 0;
		}
	}
	
	void solve() {
		System.out.println();
		for (int i = 0; i < 10; i++) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < M; y++) if (cs[x][y] == '0' + i) {
					System.out.print(i + ": ");
					solve(x, y);
				}
			}
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
