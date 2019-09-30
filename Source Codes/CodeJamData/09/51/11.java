import java.io.*;
import java.util.*;
import java.math.*;

public class Sokoban implements Runnable {

	public static void main(String[] args) {
		new Thread(new Sokoban()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "sokoban";

	int[] dx = new int[] { 0, 1, 0, -1 };
	int[] dy = new int[] { 1, 0, -1, 0 };

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			char[][] map = new char[n][];
			for (int i = 0; i < map.length; i++) {
				map[i] = nextToken().toCharArray();
			}
			a = new char[n][m];
			b = new boolean[a.length][a[0].length];
			for (int i = 0; i < map.length; i++) {
				for (int j = 0; j < map[i].length; j++) {
					a[i][j] = map[i][j] == 'x' ? '.' : map[i][j] == 'w' ? 'o'
							: map[i][j];
				}
			}
			HashMap<Integer, Integer>[][] d = new HashMap[n][m];
			for (int i = 0; i < d.length; i++) {
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = new HashMap<Integer, Integer>();
				}
			}
			Queue<State> q = new LinkedList<State>();
			State start = encode();
			q.add(start);
			d[start.x][start.y].put(start.code, 0);
			while (!q.isEmpty()) {
				State s = q.poll();
				decode(s);
				int dist = d[s.x][s.y].get(s.code);
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						if (s.x + i < a.length && s.y + j < a[s.x + i].length
								&& a[s.x + i][s.y + j] == 'o') {
							for (int dir = 0; dir < dx.length; dir++) {
								if (free(s.x + i + dx[dir], s.y + j + dy[dir])
										&& free(s.x + i + dx[(dir + 2) % 4],
												s.y + j + dy[(dir + 2) % 4])) {
									a[s.x + i][s.y + j] = '.';
									a[s.x + i + dx[dir]][s.y + j + dy[dir]] = 'o';
									State ns = encode();
									if (!ns.danger || !s.danger) {
										if (!d[ns.x][ns.y].containsKey(ns.code)
												|| d[ns.x][ns.y].get(ns.code) > dist + 1) {
											d[ns.x][ns.y]
													.put(ns.code, dist + 1);
											q.add(ns);
										}
									}
									a[s.x + i][s.y + j] = 'o';
									a[s.x + i + dx[dir]][s.y + j + dy[dir]] = '.';
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					a[i][j] = map[i][j] == 'o' ? '.' : map[i][j] == 'w' ? 'o'
							: map[i][j] == 'x' ? 'o' : map[i][j];
				}
			}
			State finish = encode();
			if (d[finish.x][finish.y].containsKey(finish.code)) {
				out.println(d[finish.x][finish.y].get(finish.code));
			} else {
				out.println(-1);
			}
		}
	}

	private boolean free(int i, int j) {
		return 0 <= i && i < a.length && 0 <= j && j < a[i].length
				&& a[i][j] == '.';
	}

	private void decode(State s) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = a[i][j] == 'o' ? '.' : a[i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if ((s.code & (1 << (5 * i + j))) != 0) {
					a[s.x + i][s.y + j] = 'o';
					danger = s.danger;
					x = s.x;
					y = s.y;
				}
			}
		}
	}

	class State {
		public State(int x2, int y2, int code2, boolean danger2) {
			x = x2;
			y = y2;
			code = code2;
			danger = danger2;
		}

		int x, y;
		int code;
		boolean danger;
	}

	private State encode() {
		code = 0;
		x = 100;
		y = 100;
		int n = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] == 'o') {
					x = Math.min(x, i);
					y = Math.min(y, j);
					n++;
				}
			}
		}
		int k = 0;
		for (int i = 0; i < b.length; i++) {
			Arrays.fill(b[i], false);
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (x + i < a.length && y + j < a[x + i].length
						&& a[x + i][y + j] == 'o') {
					code |= 1 << (5 * i + j);
					if (!b[x + i][y + j]) {
						dfs(x + i, y + j);
						k++;
					}
				}
			}
		}
		danger = k != 1;
		return new State(x, y, code, danger);
	}

	private void dfs(int x, int y) {
		b[x][y] = true;
		for (int i = x - 1; i < x + 2; i++) {
			for (int j = y - 1; j < y + 2; j++) {
				if (Math.abs(x - i) + Math.abs(y - j) == 1) {
					if (0 <= i && i < a.length && 0 <= j && j < a[i].length
							&& a[i][j] == 'o' && !b[i][j]) {
						dfs(i, j);
					}
				}
			}
		}
	}

	char[][] a;
	boolean[][] b;
	int x, y, code;
	boolean danger;

}
