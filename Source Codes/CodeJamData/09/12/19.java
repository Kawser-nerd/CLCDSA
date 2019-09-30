import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	long INF = Long.MAX_VALUE / 2;

	int MAXC = 20;
	int MAXQ = 100000;

	long[][] s = new long[MAXC][MAXC];
	long[][] w = new long[MAXC][MAXC];
	long[][] t = new long[MAXC][MAXC];

	long[][][] d = new long[MAXC][MAXC][4];
	int qx[] = new int[MAXQ];
	int qy[] = new int[MAXQ];
	int qc[] = new int[MAXQ];

	int ws[][] = { { 2, 1, 1, 2 }, { 2, 2, 1, 1 }, { 1, 2, 2, 1 }, { 1, 1, 2, 2 } };
	int opv[] = {3, 2, 1, 0};
	int oph[] = {1, 0, 3, 2};
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	int n, m, u1, u2;

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int tc = nextInt();
		for (int tn = 1; tn <= tc; tn++) {
			n = nextInt();
			m = nextInt();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					s[i][j] = nextInt();
					w[i][j] = nextInt();
					t[i][j] = nextInt() % (s[i][j] + w[i][j]);
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					fill(d[i][j], INF);
			u1 = 0;
			u2 = 1;
			d[n - 1][0][3] = 0;
			qx[0] = n - 1;
			qy[0] = 0;
			qc[0] = 3;
			while (u1 != u2) {
				int x = qx[u1];
				int y = qy[u1];
				int c = qc[u1++];
				if (u1 == MAXQ)
					u1 = 0;
				long time = d[x][y][c];
				for (int dir = 0; dir < 4; dir++) {
					int nc = getOpC(c, dir);
					if (ws[c][dir] == 2) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						relax(nx, ny, nc, time + 2);
					}
					else {
						long mod = s[x][y] + w[x][y];
						long tm = (time - t[x][y] + mod) % mod;
						long wait = 1;
						if (isH(dir)) {
							if (tm < s[x][y])
								wait += s[x][y] - tm;
						}
						else {
							if (tm >= s[x][y])
								wait += mod - tm;
						}
						relax(x, y, nc, time + wait);
					}
				}
			}
//			for (int i = 0; i < 4; i++)
//				System.out.println(d[0][0][i]);
			out.println("Case #" + tn + ": " + d[0][m - 1][1]);
		}
		in.close();
		out.close();
	}
	
	private void relax(int nx, int ny, int nc, long time) {
//		System.out.println("relax " + nx + " " + ny + " " + nc + " " + time);
		if (good(nx, ny) && d[nx][ny][nc] > time) {
			d[nx][ny][nc] = time;
			qx[u2] = nx;
			qy[u2] = ny;
			qc[u2] = nc;
			u2++;
			if (u2 == MAXQ)
				u2 = 0;
		}
		
	}

	private boolean good(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	}

	private int getOpC(int c, int d) {
		if (isH(d))
			return oph[c];
		return opv[c];
	}

	private boolean isH(int d) {
		return d == 1 || d == 3;
	}

	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
