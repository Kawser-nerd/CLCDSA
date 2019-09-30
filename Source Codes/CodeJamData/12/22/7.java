import java.util.*;
import java.math.*;
import java.io.*;

public class B {
	
	class Position {
		int x, y;

		public Position(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
		@Override
		public String toString() {
			return x + " " + y;
		}
	}
	
	int h;
	int n, m;
	int[][] ceiling;
	int[][] floor;
	int[][] best;

	private boolean canGo(int x, int y, int nx, int ny) {
		int fl = Math.max(floor[x][y], floor[nx][ny]);
		int ceil = Math.min(ceiling[x][y], ceiling[nx][ny]);
		return ceil - fl >= 50;
	}

	private int getRequiredTime(int x, int y, int nx, int ny, int time) {
		int water = Math.max(0, h - time);
		return Math.max(water + 50 - ceiling[nx][ny], 0);
	}

	private void solve() throws Exception {
		h = nextInt();
		n = nextInt();
		m = nextInt();
		ceiling = new int[n][m];
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				ceiling[x][y] = nextInt();
			}
		}
		floor = new int[n][m];
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				floor[x][y] = nextInt();
			}
		}
		
		best = new int[n][m];
		for (int[] a : best) {
			Arrays.fill(a, -1);
		}
		best[0][0] = 0;
		Queue<Position> q = new ArrayDeque<B.Position>();
		Queue<Position> nq = new ArrayDeque<B.Position>();
		nq.add(new Position(0, 0));
		while (!nq.isEmpty()) {
			Position cur = nq.poll();
			q.add(cur);
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					if (dx == 0 ^ dy == 0) {
						int nx = cur.x + dx, ny = cur.y + dy;
						if (nx >= 0 && ny >= 0 && nx < n && ny < m && best[nx][ny] < 0) {
							if (!canGo(cur.x, cur.y, nx, ny)) {
								continue;
							}
							int timeToGo = getRequiredTime(cur.x, cur.y, nx, ny, 0);
							if (timeToGo == 0) {
								best[nx][ny] = 0;
								nq.add(new Position(nx, ny));
							}
						}
					}
				}
			}
		}
		
		
		while (!q.isEmpty()) {
			Position cur = q.poll();
			int time = best[cur.x][cur.y];
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					if (dx == 0 ^ dy == 0) {
						int nx = cur.x + dx, ny = cur.y + dy;
						if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
							if (!canGo(cur.x, cur.y, nx, ny)) {
								continue;
							}
							int timeToGo = getRequiredTime(cur.x, cur.y, nx, ny, time);
							int water = Math.max(0, h - (time + timeToGo));
							if (water - floor[cur.x][cur.y] >= 20) {
								timeToGo += 10;
							} else {
								timeToGo += 100;
							}
							if (best[nx][ny] < 0 || best[cur.x][cur.y] + timeToGo < best[nx][ny]) {
								best[nx][ny] = best[cur.x][cur.y] + timeToGo;
								q.add(new Position(nx, ny));
							}
						}
					}
				}
			}
		}
		
		out.printf("%.2f\n", best[n - 1][m - 1] / 10.);
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private B(String name) {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new B("b").run();
	}
}
