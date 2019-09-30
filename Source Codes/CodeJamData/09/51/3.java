import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	boolean TIME = true;
	Scanner sc;
	
	void solve() {
		n = sc.nextInt();
		m = sc.nextInt();
		cs = new char[n][];
		N = 0;
		for (int i = 0; i < n; i++) {
			cs[i] = sc.next().toCharArray();
			for (int j = 0; j < m; j++) if (cs[i][j] == 'o' || cs[i][j] == 'w') {
				N++;
			}
		}
		int[] is = new int[N], js = new int[N];
		N = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) if (cs[i][j] == 'o' || cs[i][j] == 'w') {
				is[N] = i;
				js[N] = j;
				N++;
			}
		}
		System.out.println(bfs(is, js));
	}
	
	int n, m, N;
	char[][] cs;
	
	int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	boolean[][] map = new boolean[20][20];
	
	class State {
		int d;
		int[] xs, ys;
		State(int[] xs, int[] ys, int d) {
			pairSort(xs, ys);
			this.xs = xs;
			this.ys = ys;
			this.d = d;
		}
		boolean ok() {
			for (int i = 0; i < N; i++) if (cs[xs[i]][ys[i]] != 'x' && cs[xs[i]][ys[i]] != 'w') {
				return false;
			}
			return true;
		}
		boolean isDang() {
			int[] color = new int[N];
			for (int i = 0; i < N; i++) color[i] = i;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 4; j++) {
					int x = xs[i] + dx[j], y = ys[i] + dy[j];
					for (int k = 0; k < N; k++) {
						if (x == xs[k] && y == ys[k]) {
							int c = color[k];
							for (int a = 0; a < N; a++) if (color[a] == c) color[a] = color[i];
						}
					}
				}
			}
			for (int i = 0; i < N; i++) if (color[i] != color[0]) return true;
			return false;
		}
		List<State> next() {
			List<State> list = new ArrayList<State>();
			boolean isDang = isDang();
			for (int i = 0; i < N; i++) map[xs[i]][ys[i]] = true;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 4; j++) {
					int x = xs[i] + dx[j], y = ys[i] + dy[j];
					int x2 = xs[i] - dx[j], y2 = ys[i] - dy[j];
					if (0 <= x && x < n && 0 <= y && y < m && cs[x][y] != '#' && !map[x][y]) {
						if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && cs[x2][y2] != '#' && !map[x2][y2]) {
							int[] xs2 = xs.clone();
							int[] ys2 = ys.clone();
							xs2[i] = x;
							ys2[i] = y;
							State s = new State(xs2, ys2, d + 1);
							if (!isDang || !s.isDang()) {
								list.add(s);
							}
						}
					}
				}
			}
			for (int i = 0; i < N; i++) map[xs[i]][ys[i]] = false;
			return list;
		}
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(xs);
			result = prime * result + Arrays.hashCode(ys);
			return result;
		}
		public boolean equals(Object obj) {
			State other = (State)obj;
			if (!Arrays.equals(xs, other.xs)) return false;
			if (!Arrays.equals(ys, other.ys)) return false;
			return true;
		}
	}
	
	void pairSort(int[] ks, int[] vs) {
		int n = ks.length;
		long[] ls = new long[n];
		for (int i = 0; i < n; i++) {
			ls[i] = ((long)ks[i] << 32) | vs[i];
		}
		sort(ls);
		for (int i = 0; i < n; i++) {
			ks[i] = (int)(ls[i] >> 32);
			vs[i] = (int)ls[i];
		}
	}
	
	int bfs(int[] xs, int[] ys) {
		Queue<State> que = new LinkedList<State>();
		HashSet<State> set = new HashSet<State>();
		que.offer(new State(xs, ys, 0));
		while (!que.isEmpty()) {
			State s = que.poll();
			if (s.ok()) return s.d;
			List<State> next = s.next();
			for (State t : next) {
				if (set.add(t)) que.offer(t);
			}
		}
		return -1;
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
