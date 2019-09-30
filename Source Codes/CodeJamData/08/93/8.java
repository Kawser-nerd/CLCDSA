import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	BufferedReader br;
	PrintWriter pw;

	private void solve() throws Exception {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter("c.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
		}

		br.close();
		pw.close();
	}

	int r, c, res;
	int[][] a, b;
	int[] dx = {-1, -1, -1, 0, 0,   1, 1, 1, 0};
	int[] dy = {-1, 0, 1,   1, -1, -1, 0, 1, 0};

	private void runtest() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		a = new int[r][c];
		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < c; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		res = 0;
		b = new int[r][c];
		for (int ul = 0; ul < 2; ul++) {
			b[0][0] = ul;
			for (int up = 0; up < 1 << (r - 1); up++) {
				int x = up;
				for (int i = 1; i < r; i++) {
					b[i][0] = x % 2;
					x = x / 2;
				}
				for (int ud = 0; ud < 1 << (c - 1); ud++) {
					x = ud;
					for (int i = 1; i < c; i++) {
						b[0][i] = x % 2;
						x = x / 2;
					}

					int v = go();
					if (v > res) {
						res = v;
					}
				}
			}
		}
		pw.println(res);
	}

	private int go() {
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				b[i][j] = 0;
				int d = sum(i - 1, j - 1);
				b[i][j] = a[i - 1][j - 1] - d;
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i][j] < 0 || b[i][j] > 1) {
					return -1;
				}
				if (sum(i, j) != a[i][j]) {
					return -1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < c; i++) {
			res += b[r / 2][i];
		}
		return res;
	}

	private int sum(int i, int j) {
		int res = 0;
		for (int dir = 0; dir < 9; dir++) {
			int ni = i + dx[dir];
			int nj = j + dy[dir];
			if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
				res += b[ni][nj];
			}
		}
		return res;
	}

}
