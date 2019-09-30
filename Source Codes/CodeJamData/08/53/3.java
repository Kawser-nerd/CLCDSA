import java.util.*;
import java.io.*;

public class Cheating implements Runnable {
	private final String problemID = getClass().getName().toLowerCase();
	private final String problemType = "large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private static final int[] dx = { -1, 0, 1, -1, 0, 1 };
	private static final int[] dy = { -1, -1, -1, 1, 1, 1 };
	
	private boolean[] leftUsed;
	private boolean[] rightUsed;
	private boolean[][] field;
	private int[] lm;
	private int[] rm;
	private int[][] num;
	private int[] prev;
	private int[] xc, yc;
	private int[] q;
	private int n, m, low, hi;

	private String next() throws IOException {
		if (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
			return next();
		}
		return st.nextToken();
	}
	
	private boolean bfs(int u) {
		low = 0;
		hi = 1;
		q[0] = u;
		boolean found = false;
		int lastLeft = -1;
		int lastRight = -1;
		while (low < hi) {
			int cur = q[low++];
			int x = xc[cur];
			int y = yc[cur];
			for (int dir = 0; dir < 6; dir++) {
				int xx = x + dx[dir];
				int yy = y + dy[dir];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || !field[xx][yy]) {
					continue;
				}
				if (rm[num[xx][yy]] == -1) {
					lastRight = num[xx][yy];
					lastLeft = cur;
					found = true;
					break;
				}
				int tar = rm[num[xx][yy]];
				if (prev[tar] == -1) {
					prev[tar] = cur;
					q[hi++] = tar;
				}
			}
			if (found) {
				break;
			}
		}
		if (!found) {
			return false;
		}
		while (true) {
			int tmp = lm[lastLeft];
			lm[lastLeft] = lastRight;
			rm[lastRight] = lastLeft;
			lastRight = tmp;
			if (lastLeft == u) {
				break;
			}
			lastLeft = prev[lastLeft];
		}
		return true;
	}

	private void solveSingleTest(int testNumber) throws IOException {
		n = Integer.parseInt(next());
		m = Integer.parseInt(next());
		field = new boolean[n][m];
		int vert = 0;
		for (int i = 0; i < n; i++) {
			String tmp = next();
			for (int j = 0; j < m; j++) {
				field[i][j] = (tmp.charAt(j) == '.');
				if (field[i][j]) {
					vert++;
				}
			}
		}
		num = new int[n][m];
		xc = new int[n * m];
		yc = new int[n * m];
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				xc[count] = i;
				yc[count] = j;
				num[i][j] = count++;
			}
		}
		lm = new int[n * m];
		rm = new int[n * m];
		Arrays.fill(lm, -1);
		Arrays.fill(rm, -1);
		int size = 0;
		q = new int[n * m];
		prev = new int[n * m];
		while (true) {
			Arrays.fill(prev, -1);
			boolean good = false;
			for (int j = 0; j < m; j += 2) {
				for (int i = 0; i < n; i++) {
					if (!field[i][j]) {
						continue;
					}
					if (lm[num[i][j]] == -1 && bfs(num[i][j])) {
						size++;
						good = true;
					}
				}
			}
			if (!good) {
				break;
			}
		}
		int answer = vert - size;
		out.println("Case #" + testNumber + ": " + answer);
	}
	
	public static void main(String[] args) {
		new Thread(new Cheating()).start();
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
