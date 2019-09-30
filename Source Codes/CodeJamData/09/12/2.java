import java.io.*;
import java.util.*;

public class B implements Runnable {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	final static int[] dx = new int[]{1, 0, -1, 0};
	final static int[] dy = new int[]{0, 1, 0, -1};
	
	private void solve() {
		int hei = in.nextInt();
		int wid = in.nextInt();
		long[][] ss = new long[hei][wid];
		long[][] ww = new long[hei][wid];
		long[][] tt = new long[hei][wid];
		for (int i = hei - 1; i >= 0; i--) {
			for (int j = 0; j < wid; j++) {
				ss[i][j] = in.nextLong();
				ww[i][j] = in.nextLong();
				tt[i][j] = in.nextLong();
			}
		}
		long inf = Long.MAX_VALUE / 2;
		int H = 3 * hei - 1;
		int W = 3 * wid - 1;
		long[][] dist = new long[H][W];
		int[][] sp = new int[H][W];
		boolean[][] mark = new boolean[H][W];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				dist[i][j] = inf;
				sp[i][j] = (i % 3 == 2 ? 1 : 0) + (j % 3 == 2 ? 1 : 0);
				if (sp[i][j] > 0) {
					mark[i][j] = true;
				}
			}
		}
		dist[0][0] = 0;
		while (true) {
			int ii = -1;
			int jj = -1;
			long bd = inf;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if (mark[i][j])
						continue;
					if (dist[i][j] < bd) {
						ii = i;
						jj = j;
						bd = dist[i][j];
					}
				}
			}
			if (ii < 0) {
				break;
			}
			mark[ii][jj] = true;
			for (int dir = 0; dir < 4; dir++) {
				int i = ii + dx[dir];
				int j = jj + dy[dir];
				int i1 = ii + 2 * dx[dir];
				int j1 = jj + 2 * dy[dir];
				if (i < 0 || j < 0 || i >= H || j >= W) {
					continue;
				}
				if (sp[i][j] == 1) {
					dist[i1][j1] = Math.min(dist[i1][j1], dist[ii][jj] + 2);
					continue;
				}
				long ok, notok, start;
				if (dx[dir] == 0) {
					// Hor
					ok = ww[i / 3][j / 3];
					notok = ss[i / 3][j / 3];
					start = tt[i / 3][j / 3] + notok;
				} else {
					// Ver
					ok = ss[i / 3][j / 3];
					notok = ww[i / 3][j / 3];
					start = tt[i / 3][j / 3];
				}
				long d = dist[ii][jj];
				long p = ok + notok;
				long r = (d - start) % p;
				if (r < 0) r += p;
				long walk = (r < ok) ? 1 : (p - r + 1);
				dist[i][j] = Math.min(dist[i][j], d + walk);
			}
		}
		out.println(dist[H - 1][W - 1]);
	}

	public void run() {
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			solve();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		Thread thread = new Thread(new B());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
