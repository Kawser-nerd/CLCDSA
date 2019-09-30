import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class A implements Runnable {

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	final static int[] dx = {0, 0, 1, -1};
	final static int[] dy = {1, -1, 0, 0};
	
	int w, h;
	char[][] s;
	int n;
	boolean[] col;
	
	class Position {
		public int[] x;
		public int[] y;
		int cur, has;
		boolean dang;
		
		public Position() {
			x = new int[n];
			y = new int[n];
			cur = 0;
		}

		public void add(int i, int j) {
			x[cur] = i;
			y[cur] = j;
			cur++;
		}
		
		public void sort() {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (x[i] > x[j] || (x[i] == x[j] && y[i] > y[j])) {
						int t = x[i]; x[i] = x[j]; x[j] = t;
						t = y[i]; y[i] = y[j]; y[j] = t;
					}
				}
			}
			dangerous();
			has = 0;
			for (int i = 0; i < n; i++) {
				has = (has * 17 + x[i]) * 23 + y[i];
			}
		}
		
		@Override
		public boolean equals(Object obj) {
			Position p = (Position) obj;
			for (int i = 0; i < n; i++) {
				if (x[i] != p.x[i] || y[i] != p.y[i]) {
					return false;
				}
			}
			return true;
		}
		
		@Override
		public int hashCode() {
			return has;
		}

		public Position move(int i, int d) {
			int nx = x[i] + dx[d];
			int ny = y[i] + dy[d];
			int fx = x[i] - dx[d];
			int fy = y[i] - dy[d];
			if (empty(nx, ny) && empty(fx, fy)) {
				Position p = new Position();
				for (int j = 0; j < n; j++) {
					if (j != i) {
						p.add(x[j], y[j]);
					} else {
						p.add(nx, ny);
					}
				}
				p.sort();
				return p;
			}
			return null;
		}

		private boolean empty(int nx, int ny) {
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				return false;
			}
			if (s[nx][ny] == '#') {
				return false;
			}
			for (int i = 0; i < n; i++) {
				if (x[i] == nx && y[i] == ny) {
					return false;
				}
			}
			return true;
		}

		public boolean dangerous() {
			if (n == 1) {
				dang = false;
			} else if (n == 2) {
				dang = (Math.abs(x[0] - x[1]) + Math.abs(y[0] - y[1]) > 1);
			} else {
				Arrays.fill(col, false);
				dfs(0);
				dang = false;
				for (int i = 0; i < n; i++) {
					if (!col[i]) {
						dang = true;
					}
				}
			}
			return dang;
		}

		private void dfs(int i) {
			col[i] = true;
			for (int j = 0; j < n; j++) {
				if (!col[j]) {
					int d = Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]);
					if (d == 1) {
						dfs(j);
					}
				}
			}
		}
	}
	
	HashMap<Position, Integer> hash;
	ArrayList<Position> list;

	private void solve() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("a.in"));
		PrintWriter pw = new PrintWriter("a.out");
		
		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			h = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			s = new char[h][];
			n = 0;
			for (int i = 0; i < h; i++) {
				s[i] = br.readLine().trim().toCharArray();
				for (int j = 0; j < w; j++) {
					if (s[i][j] == 'o' || s[i][j] == 'w') {
						n++;
					}
				}
			}
			
			col = new boolean[n];
			
			Position start = new Position();
			Position finish = new Position();
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == 'o' || s[i][j] == 'w') {
						start.add(i, j);
					}
					if (s[i][j] == 'x' || s[i][j] == 'w') {
						finish.add(i, j);
					}
				}
			}
			start.sort();
			finish.sort();
			
			hash = new HashMap<Position, Integer>();
			hash.put(start, 0);
			list = new ArrayList<Position>();
			list.add(start);
			int now = 0;
			
			int result = -1;
			if (start.equals(finish)) {
				result = 0;
			}
			
			while (now < list.size()) {
				if (result != -1) {
					break;
				}

				Position p = list.get(now);
				now++;
				int dist = hash.get(p);
				
				for (int i = 0; i < n; i++) {
					if (result != -1) {
						break;
					}
					
					for (int d = 0; d < 4; d++) {
						if (result != -1) {
							break;
						}

						Position p1 = p.move(i, d);
						if (p1 == null) {
							continue;
						}
						
						if (p1.equals(finish)) {
							result = dist + 1;
							break;
						}
						if (!p1.dang || !p.dang) {
							if (!hash.containsKey(p1)) {
								hash.put(p1, dist + 1);
								list.add(p1);
							}
						}
					}
				}
				
				if (result != -1) {
					break;
				}
			}
			
			
			pw.println("Case #" + test + ": " + result);
		}
		
		br.close();
		pw.close();
	}

}
