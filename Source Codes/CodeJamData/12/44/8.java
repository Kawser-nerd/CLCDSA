import java.io.*;
import java.util.*;

public class Descending {

	class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
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
			Point other = (Point) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private Descending getOuterType() {
			return Descending.this;
		}

	}

	int[] dx = new int[] { 0, 0, 1 };
	int[] dy = new int[] { -1, 1, 0 };

	int r, c;
	char[][] field;
	boolean[][] can;

	boolean inside(int x, int y) {
		return (x >= 0 && x < r && y >= 0 && y < c && field[x][y] != '#');
	}

	class PtList {
		int[] a;

		public PtList() {
			a = new int[r];
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + Arrays.hashCode(a);
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
			PtList other = (PtList) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (!Arrays.equals(a, other.a))
				return false;
			return true;
		}

		private Descending getOuterType() {
			return Descending.this;
		}

	}

	void solve() throws Exception {
		r = nextInt();
		c = nextInt();
		field = new char[r][c];
		int countCaves = 0;
		for (int i = 0; i < r; i++) {
			field[i] = nextToken().toCharArray();
			for (char ch : field[i]) {
				if (Character.isDigit(ch)) {
					countCaves = Math.max(countCaves, (int) (ch - '0') + 1);
				}
			}
		}
		Point[] caves = new Point[countCaves];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (Character.isDigit(field[i][j])) {
					caves[(int) (field[i][j] - '0')] = new Point(i, j);
				}
			}
		}

		for (int cave = 0; cave < countCaves; cave++) {
			Point curCave = caves[cave];
			can = new boolean[r][c];
			can[curCave.x][curCave.y] = true;
			for (int IT = 0; IT < r * c; IT++) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (!can[i][j] && field[i][j] != '#') {
							for (int k = 0; k < 3; k++) {
								int cx = i + dx[k];
								int cy = j + dy[k];
								if (inside(cx, cy)) {
									can[i][j] |= can[cx][cy];
								}
							}
						}
					}
				}
			}
			
			List<Point> pts = new ArrayList<Point>();
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (can[i][j]) {
						pts.add(new Point(i, j));
					}
				}
			}

			out.print(cave + ": " + pts.size() + " ");
			PtList start = new PtList();
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (can[i][j]) {
						start.a[i] |= (1 << j);
					}
				}
			}
			
			Queue<PtList> q = new ArrayDeque<Descending.PtList>();
			Set<PtList> visited = new HashSet<Descending.PtList>();
			visited.add(start);
			q.add(start);
			boolean ans = false;
			while (!q.isEmpty()) {
				PtList cur = q.poll();
				boolean ok = true;
				for (int i = 0; i < r; i++) {
					if (i != curCave.x) {
						if (cur.a[i] != 0) {
							ok = false;
						}
					} else {
						if (cur.a[i] != (1 << curCave.y)) {
							ok = false;
						}
					}
					if (!ok) {
						break;
					}
				}
				if (ok) {
					ans = true;
					break;
				}
				
				for (int dir = 0; dir < 3; dir++) {
					PtList next = new PtList();
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if ((cur.a[i] & (1 << j)) != 0) {
								int cx = i + dx[dir];
								int cy = j + dy[dir];
								if (inside(cx, cy)) {
									next.a[cx] |= 1 << cy;
								} else {
									next.a[i] |= 1 << j;
								}
							}
						}
					}
					if (visited.contains(next)) {
						continue;
					}
					boolean good = true;
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if ((next.a[i] & (1 << j)) != 0 && !can[i][j]) {
								good = false;
								break;
							}
						}
						if (!good) {
							break;
						}
					}
					if (good) {
						visited.add(next);
						q.add(next);
					}
				}
			}
			if (ans) {
				out.println("Lucky");
			} else {
				out.println("Unlucky");
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();

			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.println("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Solved case #" + (i + 1) + " in "
						+ (System.currentTimeMillis() - time) + " ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("Descending").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Descending().run();
	}

}
