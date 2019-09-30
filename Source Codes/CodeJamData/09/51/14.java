import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
public class A {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "A";
//	void debug(Object... os) {
//		System.err.println(deepToString(os));
//	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			h = sc.nextInt();
			w = sc.nextInt();
			char[][] f = new char[h][w];
			goal = new boolean[h][w];
			m = 0;
			for (int i = 0; i < h; i++) {
				f[i] = sc.next().toCharArray();
				for (int j = 0; j < w; j++) {
					if (f[i][j] == 'x') {
						goal[i][j] = true;
						f[i][j] = '.';
						m++;
					}
					if (f[i][j] == 'w') {
						goal[i][j] = true;
						f[i][j] = 'o';
						m++;
					}
				}
			}
//			debug(f);
			g=f;
			int[] xs = new int[m];
			int[] ys = new int[m];
			for (int i = 0, k = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (f[i][j] == 'o') {
						xs[k] = i;
						ys[k++] = j;
					}
				}
			}
//			debug(goal);
			que = new PriorityQueue<Entry>();
			map = new HashMap<Entry, Integer>();
			Entry init = new Entry(xs, ys, 0);
			que.offer(init);
			map.put(init,0);
//			debug(init.isCon());
			int res = -1;
			while (!que.isEmpty()) {
				Entry e = que.poll();
//				debug("que");
//				e.tos();
//				e.tos();
//				debug();
				if (e.isGoal()) {
					res = e.step;
//					debug("!",res);
					break;
				}
				e.addNexts();
			}
			System.out.println(res);
		}
	}
	boolean[][] goal;
	PriorityQueue<Entry> que;
	HashMap<Entry, Integer> map;
	int h, w;
	int m;
	char[][] g;
	int[] dx = { 1, 0, -1, 0 };
	int[] dy = { 0, 1, 0, -1 };
	int dfs(boolean[][] f, int x, int y) {
		if (!f[x][y])
			return 0;
		f[x][y] = false;
		int res = 1;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (in(0, nx, h) && in(0, ny, w))
				res += dfs(f, nx, ny);
		}
		return res;
	}
	void add(Entry e) {
		if (e != null) {
			if (map.containsKey(e) && map.get(e)<=e.step){
//				debug("!");
				e.tos();
				return;
			}
			map.put(e, e.step);
			que.offer(e);
		}
	}
	class Entry implements Comparable<Entry> {
// char[][] g;
		final int step;
		int[] xs;
		int[] ys;
		void tos(){
			for(char[] c:f){
//				debug(c);
			}
//			debug(xs,ys);
//			debug();
		}
		boolean isCon() {
			boolean[][] f = new boolean[h][w];
			for (int i = 0; i < m; i++) {
				f[xs[i]][ys[i]] = true;
			}
			int v=dfs(f,xs[0],ys[0]);
//			debug(v);
			return v == m;
		}
// Entry(char[][] tmp, int step) {
// for (int i = 0; i < h; i++) {
// g[i] = tmp[i].clone();
// }
// this.step = step;
// }
		Entry(int[] txs, int[] tys, int step) {
			this.xs = txs.clone();
			this.ys = tys.clone();
			for (int i = 0; i < m; i++) {
				for (int j = i; j < m; j++) {
					if(xs[i]>xs[j] || xs[i]==xs[j]&&ys[i]>ys[j]){
						int t=xs[i];xs[i]=xs[j];xs[j]=t;
						t=ys[i];ys[i]=ys[j];ys[j]=t;
					}
				}
			}
			this.step = step;
			f=new char[h][w];
			for (int i = 0; i < h; i++) {
				fill(f[i],'.');
			}
			for (int i = 0; i < m; i++) {
				f[xs[i]][ys[i]]='o';
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if(g[i][j]=='#')f[i][j]='#';
				}
			}
//			for(char[] c:f)debug(c);
//			debug(isCon());
//			debug();
		}
		@Override
		public int compareTo(Entry arg0) {
			return step - arg0.step;
		}
		char[][] f;
		boolean isGoal() {
			for (int i = 0; i < m; i++) {
				if (!goal[xs[i]][ys[i]])
					return false;
			}
			return true;
		}
		void addNexts() {
			for (int i = 0; i < m; i++) {
				int x = xs[i], y = ys[i];
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d], ny = y + dy[d];
					int bx = x + dx[(d + 2) % 4], by = y + dy[(d + 2) % 4];
					if (in(0, nx, h) && in(0, ny, w) && in(0, bx, h) && in(0, by, w) && f[nx][ny]=='.' && f[bx][by]=='.') {
						xs[i] = nx;
						ys[i] = ny;
						Entry e = new Entry(xs, ys, step + 1);
						if (e.isCon()) {
							e.tos();
							add(e);
						} else
							for (int j = 0; j < m; j++) {
								int tx = xs[j], ty = ys[j];
								for (int nd = 0;nd < 4; nd++) {
									int tnx = tx + dx[nd], tny = ty + dy[nd];
									int tbx = tx + dx[(nd + 2) % 4], tby = ty + dy[(nd + 2) % 4];
									if (in(0, tnx, h) && in(0, tny, w) && in(0, tbx, h) && in(0, tby, w)&&e.f[tnx][tny]=='.' && e.f[tbx][tby]=='.') {
										xs[j] = tnx;
										ys[j] = tny;
										Entry ne = new Entry(xs, ys, step + 2);
										if (ne.isCon()) {
											ne.tos();
											add(ne);
										}
									}
								}
								xs[j] = tx;
								ys[j] = ty;
							}
						xs[i] = x;
						ys[i] = y;
					}
				}
			}
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + Arrays.hashCode(xs);
			result = prime * result + Arrays.hashCode(ys);
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Entry other = (Entry) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (!Arrays.equals(xs, other.xs))
				return false;
			if (!Arrays.equals(ys, other.ys))
				return false;
			return true;
		}
		private A getOuterType() {
			return A.this;
		}

	}

	boolean in(long from, long n, long to) {
		return from <= n && n < to;
	}

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new A().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new A().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new A().run();
			}
		} else
			new A().run();
	}
	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}
	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
