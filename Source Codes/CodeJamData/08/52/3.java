// java -Xmx512M -Xss128M Solution
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	int[] dr = new int[] {0, 0, 1, -1};
	int[] dc = new int[] {1, -1, 0, 0};
	private HashMap<State, Integer> d;
	private LinkedList<State> q;
	
	class State {
		int row;
		int col;
		int bpr;
		int bpc;
		int bpd;
		int ypr;
		int ypc;
		int ypd;
		
		final int hash;
		
		public State(int row, int col, int bpr, int bpc, int bpd, int ypr, int ypc, int ypd) {
			this.row = row;
			this.col = col;
			this.bpr = bpr;
			this.bpc = bpc;
			this.bpd = bpd;
			this.ypr = ypr;
			this.ypc = ypc;
			this.ypd = ypd;
			hash = Arrays.hashCode(new int[] {row, col, bpr, bpc, bpd, ypr, ypc, ypd});
		}
		
		public boolean equals(Object o) {
			State s = (State) o;
			return row == s.row &&
					col == s.col &&
					bpr == s.bpr &&
					bpc == s.bpc &&
					bpd == s.bpd &&
					ypr == s.ypr &&
					ypc == s.ypc && 
					ypd == s.ypd;
		}
		
		public int hashCode() {
			return hash;
		}
		
		State move(int r, int c) {
			return new State(r, c, bpr, bpc, bpd, ypr, ypc, ypd);
		}
			
		State yellow(int ypr, int ypc, int ypd) {
			return new State(row, col, ypr, ypc, ypd, bpr, bpc, bpd);
		}

		State blue(int bpr, int bpc, int bpd) {
			return new State(row, col, ypr, ypc, ypd, bpr, bpc, bpd);
		}
	}
	
	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			out.print("Case #" + (tt + 1) + ": ");
			int r = nextInt();
			int c = nextInt();
			int[][] map = new int[r][c];
			int sr = -1;
			int sc = -1;
			int fr = -1;
			int fc = -1;
			for (int i = 0; i < r; i++) {
				String s = nextToken();
				for (int j = 0; j < c; j++) {
					if (s.charAt(j) == '#') {
						map[i][j] = 1;
					}
					if (s.charAt(j) == 'O') {
						sr = i;
						sc = j;
					}
					if (s.charAt(j) == 'X') {
						fr = i;
						fc = j;
					}
				}
			}
			int[][][][] shoot = new int[r][c][dr.length][];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (map[i][j] == 1) {
						continue;
					}
					for (int k = 0; k < dr.length; k++) {
						int ci = i;
						int cj = j;
						while (true) {
							int ni = ci + dr[k];
							int nj = cj + dc[k];
							if (0 <= ni && ni < r && 0 <= nj & nj < c) {
								if (map[ni][nj] != 1) {
									ci = ni;
									cj = nj;
								} else {
									break;
								}
							} else {
								break;
							}
						}
						shoot[i][j][k] = new int[] {ci, cj};
					}
				}
			}
			State start = new State(sr, sc, -1, -1, -1, -1, -1, -1);
			q = new LinkedList<State>();
			d = new HashMap<State, Integer>();
			d.put(start, 0);
			q.addLast(start);
			int ans = -1;
			while (!q.isEmpty()) {
				State cur = q.pollFirst();
				int row = cur.row;
				int col = cur.col;
				int dist = d.get(cur);
				if (row == fr && col == fc) {
					ans = d.get(cur);
					break;
				}
				// move
				{
					for (int k = 0; k < dr.length; k++) {
						int nr = row + dr[k];
						int nc = col + dc[k];
						if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
							continue;
						}
						if (map[nr][nc] != 1) {
							State ns = cur.move(nr, nc);
							relaxOne(ns, dist + 1);
						}
					}
					if (cur.ypd != -1 && cur.bpd != -1 && row == cur.bpr && col == cur.bpc) {
						State ns = cur.move(cur.ypr, cur.ypc);
						relaxOne(ns, dist + 1);
					}
					if (cur.ypd != -1 && cur.bpd != -1 && row == cur.ypr && col == cur.ypc) {
						State ns = cur.move(cur.bpr, cur.bpc);
						relaxOne(ns, dist + 1);
					}
				}
				// shoot yellow
				{
					for (int k = 0; k < dr.length; k++) {
						int ypr = shoot[row][col][k][0];
						int ypc = shoot[row][col][k][1];
						int ypd = k;
						if (cur.bpr == ypr && cur.bpc == ypc && cur.bpd == ypd) {
							continue;
						}
						State ns = cur.yellow(ypr, ypc, ypd);
						relaxZero(ns, dist);
					}
				}
				// shoot blue
				{
					for (int k = 0; k < dr.length; k++) {
						int bpr = shoot[row][col][k][0];
						int bpc = shoot[row][col][k][1];
						int bpd = k;
						if (cur.ypr == bpr && cur.ypc == bpc && cur.ypd == bpd) {
							continue;
						}
						State ns = cur.blue(bpr, bpc, bpd);
						relaxZero(ns, dist);
					}
				}
			}
			if (ans == -1) {
				out.println("THE CAKE IS A LIE");
			} else {
				out.println(ans);
			}
			System.out.println(tt);
		}
	}
	
	private void relaxOne(State s, int dist) {
		if (d.get(s) == null) {
			d.put(s, dist);
			q.addLast(s);
		}
	}

	private void relaxZero(State s, int dist) {
		if (d.get(s) == null) {
			d.put(s, dist);
			q.addFirst(s);
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("b")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
