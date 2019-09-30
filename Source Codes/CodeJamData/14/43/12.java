package gcj.R2_2014.C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		long start = System.currentTimeMillis();

		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
//		if (true) { filename = "C-small-attempt0.in"; }
		if (true) { filename = "C-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
		long end = System.currentTimeMillis();
		tr((end - start) + "ms");
	}

	class Building {
		int id;
		int x0, y0, x1, y1;

		int getX(int pos) {
			pos = pos & 3;
			if (pos == 0) return x0;
			if (pos == 1) return x1;
			if (pos == 2) return x1;
			if (pos == 3) return x0;
			return -1;
		}
		int getY(int pos) {
			pos = pos & 3;
			if (pos == 0) return y0;
			if (pos == 1) return y0;
			if (pos == 2) return y1;
			if (pos == 3) return y1;
			return -1;
		}


	}

	long INF = 1L << 58;
	long[][] g;

	void solve(Scanner sc, PrintWriter fout) {
		int W = sc.nextInt();
		int H = sc.nextInt();
		int B = sc.nextInt();

		Building[] bs = new Building[B];
		for (int i = 0; i < B; i++) {
			Building buiding = new Building();
			buiding.x0 = sc.nextInt();
			buiding.y0 = sc.nextInt();
			buiding.x1 = sc.nextInt() + 1;
			buiding.y1 = sc.nextInt() + 1;
			bs[i] = buiding;
		}

		int start = B;
		int goal = B + 1;
		g = new long[B + 2][B + 2];
		for (int i = 0; i < g.length; i++) for (int j = 0; j < g.length; j++) g[i][j] = INF;
		for (int i = 0; i < g.length; i++) g[i][i] = 0;

		g[start][goal] = W;
		g[goal][start] = W;
		for (int i = 0; i < B; i++) {
			long dist = bs[i].x0;
			g[start][i] = g[i][start] = dist;
		}

		for (int i = 0; i < B; i++) {
			long dist = W - (bs[i].x1);
			g[goal][i] = g[i][goal] = dist;
		}

		for (int i = 0; i < B; i++) for (int j = i + 1; j < B; j++) {
			long dist = getDist(bs[i], bs[j]);
			g[i][j] = g[j][i] = dist;
		}

		for (int k = 0; k < g.length; k++) {
			for (int i = 0; i < g.length; i++) {
				for (int j = 0; j < g.length; j++) {
					g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}

		fout.println(g[start][goal]);

	}

	long getDist(Building a, Building b) {
		long res = Long.MAX_VALUE;
		for (int s = 0; s < 4; s++)
			for (int i = 0; i < 4; i++) {
				res = Math.min(res, dist(a.getX(s), a.getY(s), a.getX(s+1), a.getY(s+1), b.getX(i), b.getY(i)));
				res = Math.min(res, dist(b.getX(s), b.getY(s), b.getX(s+1), b.getY(s+1), a.getX(i), a.getY(i)));
			}

		return res;
	}

	long dist(long x1, long y1, long x2, long y2, long xp, long yp) {
		long res = Long.MAX_VALUE;
		res = Math.min(res, dist(x1, y1, xp, yp));
		res = Math.min(res, dist(x2, y2, xp, yp));

		if (x1 == x2) {
			if (y1 <= yp && yp <= y2 || y2 <= yp && yp <= y1)
				res = Math.min(res, dist(x1, yp, xp, yp));
		} else if (y1 == y2) {
			if (x1 <= xp && xp <= x2 || x2 <= xp && xp <= x1)
				res = Math.min(res, dist(xp, y1, xp, yp));
		}
		return res;
	}

	long dist(long x1, long y1, long x2, long y2) {
		return Math.max(Math.abs(x1 - x2), Math.abs(y1 - y2));
	}

}
