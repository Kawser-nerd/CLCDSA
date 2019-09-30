import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class B {
	public static long dist(int[] a, int[] b) {
		return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter("C.out");
		int tc = in.nextInt();
		for (int cc = 1; cc <= tc; cc++) {
			int n = in.nextInt();
			int s = in.nextInt();

			int[][] points = new int[n][3];
			int[][] vel = new int[n][3];
			for (int i = 0; i < n; i++) {
				points[i][0] = in.nextInt();
				points[i][1] = in.nextInt();
				points[i][2] = in.nextInt();

				vel[i][0] = in.nextInt();
				vel[i][1] = in.nextInt();
				vel[i][2] = in.nextInt();

			}

			long lo = 0;
			long hi = 100000000;
			while (hi > lo) {
				long mid = (lo + hi) / 2;

				boolean[] v = new boolean[n];
				Queue<Integer> q = new ArrayDeque<>();
				q.add(0);
				v[0] = true;
				while (!q.isEmpty()) {
					int node = q.poll();
					for (int j = 0; j < n; j++) {
						if (!v[j] && dist(points[node], points[j]) <= mid) {
							q.add(j);
							v[j] = true;
						}
					}
				}
				if (v[1]) {
					hi = mid;
				} else
					lo = mid + 1;
			}
			System.out.printf("Case #%d: %.9f\n", cc, Math.sqrt(hi));
			out.printf("Case #%d: %.9f\n", cc, Math.sqrt(hi));
		}
		out.close();
	}
}
