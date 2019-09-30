import java.util.*;
import static java.lang.Math.*;

import java.awt.geom.Line2D;
import java.io.*;

public class B {
	public static void p(Object... args) { System.out.println(Arrays.deepToString(args));}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			bestScore = -1;
			bestOrder = null;
			N = in.nextInt();
			P = new Point[N];
			for (int i = 0; i < N; i++) {
				P[i] = new Point(in.nextInt(), in.nextInt());
			}
			int[] order = new int[N];
			boolean[] used = new boolean[N];
			used[0] = true;
			order[0] = 0;
			go(1, order, used);

			System.out.format("Case #%d: ", zz);
			for (int o : bestOrder)
				System.out.print(o+" ");
			System.out.println();
			//			p(bestScore);
		}
	}
	private static void go(int at, int[] order, boolean[] used) {
		if (at == N) {
			score(order);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (used[i])
				continue;
			used[i] = true;
			order[at] = i;
			go(at + 1, order, used);
			used[i] = false;
		}
	}
	static void score(int[] O) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int a = O[i];
				int b = O[(i+1)%N];
				int c = O[j];
				int d = O[(j+1)%N];
				if (intersect(P[a], P[b], P[c], P[d])) {
					return;
				}
			}
		}
		double area = 0.0;
		for (int i = 0; i < N; i++) {
			int a = O[i];
			int b = O[(i+1)%N];
			area += P[a].x*P[b].y - P[b].x*P[a].y;
		}
		area = abs(area) / 2.0;
		if (area > bestScore) {
			bestScore = area;
			bestOrder = new int[N];
			for (int i = 0; i < N; i++)
				bestOrder[i] = O[i];
		}

	}
	private static boolean intersect(Point a, Point b, Point c, Point d) {
		if (a.equals(c) || a.equals(d) || b.equals(c) || b.equals(d))
			return false;
		return Line2D.linesIntersect(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
	}
	static int N;
	static double bestScore = -1;
	static int[] bestOrder = null;
	static Point[] P;


	static class Point {
		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
		long x, y;
	}
}
