import java.util.*;
import java.io.*;

public class Portal implements Runnable {
	private final String problemID = getClass().getName().toLowerCase();
	private final String problemType = "large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private boolean[][] field;
	private static final int[] dx = { 1, 0, -1, 0 };
	private static final int[] dy = { 0, 1, 0, -1 };
	private LinkedList<State> queue;
	private Map<State, Integer> dist;
	private int r, c;
	
	private String next() throws IOException {
		if (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
			return next();
		}
		return st.nextToken();
	}
	
	private class State {
		public int x, y;
		public int bx, by, bd;
		public int yx, yy, yd;
		
		public State(int sx, int sy) {
			this.x = sx;
			this.y = sy;
			bx = by = bd = -1;
			yx = yy = yd = -1;
		}

		public State(State cur, int bx, int by, int bd, int yx, int yy, int yd) {
			this.x = cur.x;
			this.y = cur.y;
			this.bx = cur.bx;
			this.by = cur.by;
			this.bd = cur.bd;
			this.yx = cur.yx;
			this.yy = cur.yy;
			this.yd = cur.yd;
			if (bx != -1) {
				this.bx = bx;
				this.by = by;
				this.bd = bd;
			}
			if (yx != -1) {
				this.yx = yx;
				this.yy = yy;
				this.yd = yd;
			}
		}

		public State(State cur, int xx, int yy) {
			this.x = xx;
			this.y = yy;
			this.bx = cur.bx;
			this.by = cur.by;
			this.bd = cur.bd;
			this.yx = cur.yx;
			this.yy = cur.yy;
			this.yd = cur.yd;
		}

		@Override
		public boolean equals(Object obj) {
			State that = (State) obj;
			
			if (this.x != that.x || this.y != that.y) {
				return false;
			}
			
			if (this.bx != that.bx || this.by != that.by || this.bd != that.bd) {
				return false;
			}
			
			if (this.yx != that.yx || this.yy != that.yy || this.yd != that.yd) {
				return false;
			}
			return true;
		}
		
		@Override
		public int hashCode() {
			int hash1 = (x << 22) ^ y;
			int hash2 = (bx << 3) ^ (by << 6) ^ bd;
			int hash3 = (yx << 4) ^ (yy << 8) ^ yd;
			return hash1 ^ (hash2 << 10) ^ (hash3 << 20);
		}
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		r = Integer.parseInt(next());
		c = Integer.parseInt(next());
		System.out.println("Test " + testNumber);
		
		field = new boolean[r][c];
		int sx = 0;
		int sy = 0;
		int tx = 0;
		int ty = 0;
		for (int i = 0; i < r; i++) {
			String tmp = next();
			for (int j = 0; j < c; j++) {
				char ch = tmp.charAt(j);
				if (ch == '.') {
					field[i][j] = true;
					continue;
				}
				if (ch == '#') {
					field[i][j] = false;
					continue;
				}
				if (ch == 'O') {
					field[i][j] = true;
					sx = i;
					sy = j;
					continue;
				}
				if (ch == 'X') {
					field[i][j] = true;
					tx = i;
					ty = j;
					continue;
				}
			}
		}
		
		int[][][] shootX = new int[r][c][4];
		int[][][] shootY = new int[r][c][4];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!field[i][j]) {
					continue;
				}
				for (int d = 0; d < 4; d++) {
					int x = i;
					int y = j;
					while (isInside(x, y) && field[x][y]) {
						x = x + dx[d];
						y = y + dy[d];
					}
					x = x - dx[d];
					y = y - dy[d];
					shootX[i][j][d] = x;
					shootY[i][j][d] = y;
				}
			}
		}
		
		queue = new LinkedList<State>();
		dist = new HashMap<State, Integer>();
		State init = new State(sx, sy);
		dist.put(init, 0);
		queue.addFirst(init);
		int answer = Integer.MAX_VALUE;
		while (!queue.isEmpty()) {
			State cur = queue.poll();
			int curDist = dist.get(cur);
			if (curDist >= answer) {
				continue;
			}
			if (cur.x == tx && cur.y == ty) {
				answer = Math.min(answer, curDist);
			}
			for (int d = 0; d < 4; d++) {
				int u = shootX[cur.x][cur.y][d];
				int v = shootY[cur.x][cur.y][d];
				State newState = new State(cur, u, v, d, -1, -1, -1);
				if (!dist.containsKey(newState)) {
					dist.put(newState, curDist);
					queue.addFirst(newState);
				}
				newState = new State(cur, -1, -1, -1, u, v, d);
				if (!dist.containsKey(newState)) {
					dist.put(newState, curDist);
					queue.addFirst(newState);
				}
			}
			for (int d = 0; d < 4; d++) {
				int xx = -1;
				int yy = -1;
				
				if (cur.x == cur.bx && cur.y == cur.by && d == cur.bd) {
					xx = cur.yx;
					yy = cur.yy;
				} else if (cur.x == cur.yx && cur.y == cur.yy && d == cur.yd) {
					xx = cur.bx;
					yy = cur.by;
				} else {
					xx = cur.x + dx[d];
					yy = cur.y + dy[d];
				}
				if (!isInside(xx, yy) || !field[xx][yy]) {
					continue;
				}
				State newState = new State(cur, xx, yy);
				if (!dist.containsKey(newState)) {
					dist.put(newState, curDist + 1);
					queue.addLast(newState);
				}
			}
		}
//		System.out.println(dist.size());
		if (answer == Integer.MAX_VALUE) {
			out.println("Case #" + testNumber + ": THE CAKE IS A LIE");
		} else {
			out.println("Case #" + testNumber + ": " + answer);
		}
	}
	
	private boolean isInside(int x, int y) {
		return (0 <= x) && (x < r) && (0 <= y) && (y < c);
	}

	public static void main(String[] args) {
		new Thread(new Portal()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + "_" + problemType + ".in")));
		out = new PrintWriter(new File(problemID + "_" + problemType + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int i = 0; i < testsNumber; i++) {
			solveSingleTest(i + 1);
		}
		
		in.close();
		out.close();
	}
}
