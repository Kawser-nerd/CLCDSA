import java.io.*;
import java.util.*;
import java.math.*;

public class Bridge implements Runnable {

	public static void main(String[] args) {
		new Thread(new Bridge()).start();
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

	String FNAME = "bridge";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			int m = nextInt();
			char[][] a = new char[n][];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextToken().toCharArray();
			}
			int[][] d = new int[n][m];
			for (int i = 0; i < d.length; i++) {
				Arrays.fill(d[i], Integer.MAX_VALUE / 2);
			}
			d[0][0] = 0;
			boolean[][] c = new boolean[n][m];
			c[0][0] = true;
			PriorityQueue<Item> pq = new PriorityQueue<Item>();
			pq.add(new Item(0, 0, 0));
			while (pq.size() > 0) {
				Item p = pq.poll();
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (Math.abs(i) + Math.abs(j) == 1) {
							if (0 <= p.x + i && p.x + i < d.length) {
								if (0 <= p.y + j && p.y + j < d[p.x].length) {
									if (!c[p.x + i][p.y + j]
											&& (a[p.x + i][p.y + j] == 'T' || a[p.x
													+ i][p.y + j] == '#')) {
										c[p.x + i][p.y + j] = true;
										d[p.x + i][p.y + j] = d[p.x][p.y] + 1;
										pq.add(new Item(p.x + i, p.y + j, p.d
												+ d[p.x][p.y] + 1));
									}
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < c.length; i++) {
				Arrays.fill(c[i], false);
			}
			int cost = 0;
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] == 'T') {
						pq.add(new Item(i, j, 0));
						if (i != 0 || j != 0) {
							cost += (d[i][j] + 1) * (d[i][j]) / 2;
							int x = i;
							int y = j;
							while (d[x][y] > 0) {
								c[x][y] = true;
								search: for (int dx = -1; dx < 2; dx++) {
									for (int dy = -1; dy < 2; dy++) {
										if (Math.abs(dx) + Math.abs(dy) == 1) {
											if (0 <= x + dx && x + dx < n
													&& 0 <= y + dy
													&& y + dy < m) {
												if (d[x + dx][y + dy] + 1 == d[x][y]) {
													x = x + dx;
													y = y + dy;
													break search;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < d.length; i++) {
				Arrays.fill(d[i], Integer.MAX_VALUE / 2);
			}
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] == 'T') {
						d[i][j] = 0;
					}
				}
			}
			while (pq.size() > 0) {
				Item p = pq.poll();
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (Math.abs(i) + Math.abs(j) == 1) {
							if (0 <= p.x + i && p.x + i < d.length) {
								if (0 <= p.y + j && p.y + j < d[p.x].length) {
									if ((a[p.x + i][p.y + j] == 'T' || a[p.x
											+ i][p.y + j] == '#')
											&& d[p.x + i][p.y + j] > d[p.x][p.y] + 1) {
										d[p.x + i][p.y + j] = d[p.x][p.y] + 1;
										pq.add(new Item(p.x + i, p.y + j,
												d[p.x][p.y] + 1));
									}
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < c.length; i++) {
				for (int j = 0; j < c[i].length; j++) {
					if (!c[i][j] && a[i][j] == '#') {
						cost += d[i][j];
					}
				}
			}
			out.println(cost);
		}
	}

	class Item implements Comparable<Item> {
		int x, y, d;

		public Item(int i, int j, int k) {
			x = i;
			y = j;
			d = k;
		}

		@Override
		public int compareTo(Item i) {
			return d - i.d;
		}
	}

}
