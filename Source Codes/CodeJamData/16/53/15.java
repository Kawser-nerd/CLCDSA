import java.io.*;
import java.util.*;

public class C {

	static class Point {
		int x;
		int y;
		int z;
		Point(Scanner in) {
			x = in.nextInt();
			y = in.nextInt();
			z = in.nextInt();
			in.nextInt();
			in.nextInt();
			in.nextInt();
		}

		int dist2(Point second) {
			int dx = this.x - second.x;
			int dy = this.y - second.y;
			int dz = this.z - second.z;
			return dx * dx + dy * dy + dz * dz;
		}
	}

	String solveOne(Scanner in) {
		int n = in.nextInt();
		in.nextInt();
		Point p[] = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(in);
		}
		boolean connected[] = new boolean[n];
		final int INF = Integer.MAX_VALUE;
		int dist2[] = new int[n];
		Arrays.fill(dist2, INF);
		dist2[0] = 0;
		int max = 0;
		while (true) {
			int bestI = -1;
			int bestDist2 = INF;
			for (int i = 0; i < n; i++) {
				if (!connected[i] && dist2[i] < bestDist2) {
					bestDist2 = dist2[i];
					bestI = i;
				}
			}
			connected[bestI] = true;
			max = Math.max(max, bestDist2);
			for (int i = 0; i < n; i++) {
				if (!connected[i]) {
					dist2[i] = Math.min(dist2[i], p[bestI].dist2(p[i]));
				}
			}
			if (bestI == 1) {
				break;
			}
		}
		return "" + Math.sqrt(max);
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %s%n", iTest, solveOne(in));
		}
	}
	
	void run() {
		Locale.setDefault(Locale.US);
		try (
			Scanner in = new Scanner(System.in);
			PrintWriter out = new PrintWriter(System.out);
	   	) {
	   		solve(in, out);
	   	}
	}


	public static void main(String args[]) {
		new C().run();
	}
}
