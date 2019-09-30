import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "B-large";

	public void solve() throws Exception {
		int ntests = iread();
		for (int ntest = 1; ntest <= ntests; ntest++) {
			int N = iread(), M = iread(), F = iread();
			boolean[][] map = new boolean[N + 1][M];
			for (int i = 0; i < N; i++) {
				String s = readword();
				for (int j = 0; j < M; j++)
					map[i][j] = s.charAt(j) == '#';
			}
			Arrays.fill(map[N], true);
			int[][][] dyn = new int[N][M][M];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					Arrays.fill(dyn[i][j], Integer.MAX_VALUE);
			dyn[0][0][0] = 0;
			for (int y = 0; y < N - 1; y++)
				for (int x = 0; x < M; x++)
					for (int x2 = 0; x2 < M; x2++) {
						if (dyn[y][x][x2] == Integer.MAX_VALUE)
							continue;
						int d = dyn[y][x][x2];
						if (!map[y + 1][x])
							continue;

						int x_left = Math.min(x, x2), x_right = Math.max(x, x2);

						int left = x;
						while (left - 1 >= 0
								&& (!map[y][left - 1] || left - 1 >= x_left)
								&& map[y + 1][left - 1])
							left--;
						int right = x;
						while (right + 1 < M
								&& (!map[y][right + 1] || right + 1 <= x_right)
								&& map[y + 1][right + 1])
							right++;

						boolean can_dig = left < right;
						// FALL
						for (int i = left - 1; i <= right + 1; i++) {
							if (i < 0)
								continue;
							if (i >= M)
								continue;
							if ((i < x_left || i > x_right) && map[y][i])
								continue;
							boolean dig = map[y + 1][i];
							if (dig && !can_dig)
								continue;
							int d2 = dig ? d + 1 : d;
							int y2 = y + 1;
							while (!map[y2 + 1][i])
								y2++;
							if (y2 - y <= F)
								dyn[y2][i][i] = Math.min(dyn[y2][i][i], d2);
						}
						// DIG more than one
						if (can_dig)
							for (int u = left; u <= right; u++) {
								for (int v = left; v <= right; v++) {
									if (u==v) continue;
									if (u < v && u == left)
										continue;
									if (u > v && u == right)
										continue;
									dyn[y + 1][u][v] = Math.min(
											dyn[y + 1][u][v], d
													+ Math.abs(v - u) + 1);
								}
							}
					}
			int ans = Integer.MAX_VALUE;
			for (int x = 0; x < M; x++)
				for (int x2 = x; x2 < M; x2++)
					ans = Math.min(ans, dyn[N - 1][x][x2]);
			out.write("Case #" + ntest + ": ");
			if (ans != Integer.MAX_VALUE)
				out.write("Yes " + ans + "\n");
			else
				out.write("No\n");
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