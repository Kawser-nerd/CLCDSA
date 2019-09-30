import java.util.*;
import java.io.*;

public class Pockets implements Runnable {
	private final String problemID = getClass().getName().toLowerCase();
	private final String problemType = "large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private static final int[] dx = { 1, 0, -1, 0 };
	private static final int[] dy = { 0, 1, 0, -1 };
	private boolean[][] hor;
	private boolean[][] ver;
	private boolean[][] field;
	
	private String next() throws IOException {
		if (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
			return next();
		}
		return st.nextToken();
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		System.out.println("Test number " + testNumber);
		int l = Integer.parseInt(next());
		List<Integer> pointsX = new ArrayList<Integer>();
		List<Integer> pointsY = new ArrayList<Integer>();
		int x = 0;
		int y = 0;
		pointsX.add(0);
		pointsY.add(0);
		int dir = 0;
		int minX = 0;
		int minY = 0;
		int maxX = 0;
		int maxY = 0;
		int area = 0;
		for (int i = 0; i < l; i++) {
			String s = next();
			int t = Integer.parseInt(next());
			for (int j = 0; j < t; j++) {
				for (int u = 0; u < s.length(); u++) {
					char ch = s.charAt(u);
					if (ch == 'F') {
						if (dir == 0) {
							area += y;
						} else if (dir == 2) {
							area -= y;
						}
						x = x + dx[dir];
						y = y + dy[dir];
						minX = Math.min(minX, x);
						minY = Math.min(minY, y);
						maxX = Math.max(maxX, x);
						maxY = Math.max(maxY, y);
						pointsX.add(x);
						pointsY.add(y);
					} else if (ch == 'L') {
						dir = (dir + 1) % 4;
					} else {
						dir = (dir + 3) % 4;
					}
				}
			}
		}
		int sx = maxX - minX + 1;
		int sy = maxY - minY + 1;
		for (int i = 0; i < sx; i++) {
			for (int j = 0; j < sy; j++) {
				hor[i][j] = ver[i][j] = field[i][j] = false;
			}
		}
		for (int i = 0; i + 1 < pointsX.size(); i++) {
			int x1 = pointsX.get(i) - minX;
			int y1 = pointsY.get(i) - minY;
			int x2 = pointsX.get(i + 1) - minX;
			int y2 = pointsY.get(i + 1) - minY;
			if (x1 + 1 == x2 && y1 == y2) {
				hor[x1][y1] = true;
			}
			if (x1 - 1 == x2 && y1 == y2) {
				hor[x1 - 1][y1] = true;
			}
			if (y1 + 1 == y2 && x1 == x2) {
				ver[x1][y1] = true;
			}
			if (y1 - 1 == y2 && x1 == x2) {
				ver[x1][y1 - 1] = true;
			}
		}
		
		for (int i = 0; i < sx; i++) {
			int from = sy;
			int to = -1;
			for (int j = 0; j < sy; j++) {
				if (hor[i][j]) {
					from = Math.min(from, j);
					to = Math.max(to, j);
				}
			}
			if (from > to) {
				continue;
			}
			for (int j = from; j < to; j++) {
				field[i][j] = true;
			}
		}
		for (int j = 0; j < sy; j++) {
			int from = sx;
			int to = -1;
			for (int i = 0; i < sx; i++) {
				if (ver[i][j]) {
					from = Math.min(from, i);
					to = Math.max(to, i);
				}
			}
			if (from > to) {
				continue;
			}
			for (int i = from; i < to; i++) {
				field[i][j] = true;
			}
		}
		int totalArea = 0;
		for (int i = 0; i < sx; i++) {
			for (int j = 0; j < sy; j++) {
				if (field[i][j]) {
					totalArea++;
				}
			}
		}
		area = Math.abs(area);
		totalArea -= area;
		out.println("Case #" + testNumber + ": " + totalArea);
	}
	
	public static void main(String[] args) {
		new Thread(new Pockets()).start();
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
		hor = new boolean[6100][6100];
		ver = new boolean[6100][6100];
		field = new boolean[6100][6100];
		st = null;
		for (int i = 0; i < testsNumber; i++) {
			solveSingleTest(i + 1);
		}
		
		in.close();
		out.close();
	}
}
