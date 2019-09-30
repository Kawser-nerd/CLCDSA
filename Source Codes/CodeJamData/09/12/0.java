import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "B-large";

	int time_x(int time, int S, int W, int T) {
		int d = (time - T) % (S + W);
		if (d < 0)
			d += S + W;
		int h = 0;
		if (d >= S)
			h = S + W - d;
		return time + h;
	}

	int time_y(int time, int S, int W, int T) {
		int d = (time - T) % (S + W);
		if (d < 0)
			d += S + W;
		int h = 0;
		if (d < S)
			h = S - d;
		return time + h;
	}

	public void solve() throws Exception {
		int ntest = iread();
		for (int test = 1; test <= ntest; test++) {
			int N = iread(), M = iread();
			int[][] S = new int[N][M], W = new int[N][M], T = new int[N][M];
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++) {
					S[x][y] = iread();
					W[x][y] = iread();
					T[x][y] = iread();
				}
			int[][] ans = new int[2 * N][2 * M];
			boolean[][] was = new boolean[2 * N][2 * M];
			for (int i = 0; i < 2 * N; i++)
				Arrays.fill(ans[i], Integer.MAX_VALUE);
			ans[2 * N - 1][0] = 0;
			while (true) {
				int min_x = -1, min_y = -1;
				for (int x = 0; x < 2 * N; x++)
					for (int y = 0; y < 2 * M; y++) {
						if (was[x][y])
							continue;
						if (ans[x][y] == Integer.MAX_VALUE)
							continue;
						if (min_x < 0 || ans[min_x][min_y] > ans[x][y]) {
							min_x = x;
							min_y = y;
						}
					}
				if (min_x == 0 && min_y == 2 * M - 1)
					break;
				int x = min_x, y = min_y;
				was[x][y] = true;
				// relax
				int a2 = ans[x][y] + 2;
				int a3 = time_x(ans[x][y], S[x / 2][y / 2], W[x / 2][y / 2],
						T[x / 2][y / 2]) + 1;
				int a4 = time_y(ans[x][y], S[x / 2][y / 2], W[x / 2][y / 2],
						T[x / 2][y / 2]) + 1;
				if (x % 2 == 0) {
					if (x > 0)
						ans[x - 1][y] = Math.min(ans[x - 1][y], a2);
					if (x < 2 * N - 1)
						ans[x + 1][y] = Math.min(ans[x + 1][y], a3);

				} else {
					if (x > 0)
						ans[x - 1][y] = Math.min(ans[x - 1][y], a3);
					if (x < 2 * N - 1)
						ans[x + 1][y] = Math.min(ans[x + 1][y], a2);
				}

				if (y % 2 == 0) {
					if (y > 0)
						ans[x][y - 1] = Math.min(ans[x][y - 1], a2);
					if (y < 2 * M - 1)
						ans[x][y + 1] = Math.min(ans[x][y + 1], a4);

				} else {
					if (y > 0)
						ans[x][y - 1] = Math.min(ans[x][y - 1], a4);
					if (y < 2 * M - 1)
						ans[x][y + 1] = Math.min(ans[x][y + 1], a2);
				}
			}
			out.write("Case #" + test + ": " + ans[0][2 * M - 1] + "\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}