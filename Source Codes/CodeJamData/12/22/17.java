package Round1B;

import java.util.PriorityQueue;
import java.util.Scanner;

public class Tide {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] dx = { 0, 0, 1, -1 };
		int[] dy = { 1, -1, 0, 0 };
		int T = in.nextInt();
		for (int l = 1; l <= T; l++) {
			int h = in.nextInt();
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] C = new int[n][m];
			int[][] F = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					C[i][j] = in.nextInt();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					F[i][j] = in.nextInt();
			int[][] Can = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (C[i][j] - h >= 50)
						Can[i][j] = 0;
					else
						Can[i][j] = h - (C[i][j] - 50);
				}
			boolean[][] visited = new boolean[n][m];
			PriorityQueue<cell> P = new PriorityQueue<cell>();
			P.add(new cell(0, 0, 0));
			int res = -1;
			while (!P.isEmpty()) {
				cell temp = P.poll();
				int x = temp.x;
				int y = temp.y;
				int t = temp.t;
				if (x == n - 1 && y == m - 1) {
					res = t;
					break;
				}
				if (visited[x][y])
					continue;
				visited[x][y] = true;
				for (int i = 0; i < 4; i++) {
					int X = x + dx[i];
					int Y = y + dy[i];
					if (X < 0 || Y < 0 || X == n || Y == m)
						continue;
					if ((C[X][Y] - F[x][y]) < 50 || C[X][Y] - F[X][Y] < 50
							|| C[x][y] - F[X][Y] < 50)
						continue;
					int currentTime = Math.max(t, Can[X][Y]);
					if (currentTime == 0)
						P.add(new cell(X, Y, 0));
					else {
						int currentLevel = h - currentTime;
						if (currentLevel - F[x][y] >= 20)
							currentTime += 10;
						else
							currentTime += 100;
						P.add(new cell(X, Y, currentTime));
					}
				}
			}
			System.out.println("Case #" + l + ": " + (res / 10.0));
		}
	}
}

class cell implements Comparable<cell> {
	int x;
	int y;
	int t;

	public cell(int i, int j, int k) {
		x = i;
		y = j;
		t = k;
	}

	public int compareTo(cell o) {
		return t - o.t;
	}

}