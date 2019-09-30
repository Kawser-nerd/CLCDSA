import java.io.*;
import java.util.*;
import java.math.*;

public class Balls_simple implements Runnable {

	public static void main(String[] args) {
		new Thread(new Balls_simple()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "balls";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int w = nextInt();
			int h = nextInt();
			int[] dx = new int[2];
			int[] dy = new int[2];
			for (int i = 0; i < dy.length; i++) {
				dx[i] = nextInt();
				dy[i] = nextInt();
			}
			int xs = nextInt();
			int ys = nextInt();
			boolean[][] a = new boolean[w][h];
			a[xs][ys] = true;
			int[] q = new int[w * h];
			int head = 0;
			int tail = 1;
			q[0] = xs * h + ys;
			while (head != tail) {
				int x = q[head] / h;
				int y = q[head] % h;
				head++;
				for (int i = 0; i < dx.length; i++) {
					if (0 <= x + dx[i] && x + dx[i] < w) {
						if (0 <= y + dy[i] && y + dy[i] < h) {
							if (!a[x + dx[i]][y + dy[i]]) {
								a[x + dx[i]][y + dy[i]] = true;
								q[tail] = (x + dx[i]) * h + y + dy[i];
								tail++;
							}
						}
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j]) {
						ans++;
					}
				}
			}
			out.println(ans);
		}
	}
}
