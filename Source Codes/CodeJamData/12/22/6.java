import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	final static int[] dx = new int[]{1, 0, -1, 0};
	final static int[] dy = new int[]{0, 1, 0, -1};

	private void solve() {
		int h = in.nextInt();
		int hei = in.nextInt();
		int wid = in.nextInt();
		int[][] ceil = new int[hei][wid];
		int[][] floor = new int[hei][wid];
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				ceil[i][j] = in.nextInt();
			}
		}
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				floor[i][j] = in.nextInt();
			}
		}
		final long infty = Long.MAX_VALUE / 3;
		long[][] dist = new long[hei][wid];
		boolean[][] mark = new boolean[hei][wid];
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				dist[i][j] = infty;
			}
		}
		dist[0][0] = 0;
		for (;;) {
			int bi = -1;
			int bj = -1;
			for (int i = 0; i < hei; i++) {
				for (int j = 0; j < wid; j++) {
					if (mark[i][j]) {
						continue;
					}
					if (bi == -1 || dist[i][j] < dist[bi][bj]) {
						bi = i;
						bj = j;
					}
				}
			}
			mark[bi][bj] = true;
			if (bi == hei - 1 && bj == wid - 1) {
				out.println(dist[bi][bj] / 10.0);
				return;
			}
			for (int d = 0; d < 4; d++) {
				int ci = bi + dx[d];
				int cj = bj + dy[d];
				if (ci < 0 || cj < 0 || ci >= hei || cj >= wid) {
					continue;
				}
				if (floor[ci][cj] > ceil[ci][cj] - 50) {
					continue;
				}
				if (floor[bi][bj] > ceil[ci][cj] - 50) {
					continue;
				}
				if (floor[ci][cj] > ceil[bi][bj] - 50) {
					continue;
				}
				if (floor[bi][bj] > ceil[bi][bj] - 50) {
					throw new RuntimeException();
				}
				long mint = h - ceil[ci][cj] + 50;
				mint = Math.max(mint, dist[bi][bj]);
				if (mint == 0) {
					dist[ci][cj] = 0;
					continue;
				}
				long cur;
				if (h - mint >= floor[bi][bj] + 20) {
					cur = mint + 10;
				} else {
					cur = mint + 100;
				}
				dist[ci][cj] = Math.min(dist[ci][cj], cur);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
