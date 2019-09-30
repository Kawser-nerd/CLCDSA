import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Oppa implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new Oppa()).start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {

		}
	}

	private void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("bonus.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("bonus.out"));
		int T = sc.nextInt();
		for (int tn = 1; tn <= T; tn++) {
			pw.printf("Case #%d:\n", tn);
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] h = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					h[i][j] = sc.nextInt();
				}
			}
			int[][][] next = new int[n][m][2];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int[] cur = new int[] { i, j };
					for (int di = -1; di < 2; di++)
						for (int dj = -1; dj < 2; dj++)
							if (di * di + dj * dj == 1 && i + di >= 0
									&& j + dj >= 0 && i + di < n && j + dj < m) {
								if (h[cur[0]][cur[1]] > h[i + di][j + dj]) {
									cur[0] = i + di;
									cur[1] = j + dj;
								}
							}
					next[i][j] = cur;
					//System.out.println(i + " " + j + "  " + next[i][j][0] + " " + next[i][j][1]);
				}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					next[i][j] = get(next[i][j], next);
				}
			}
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			int cur = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					int u = next[i][j][0] * (m + n) + next[i][j][1];
					if(map.get(u) == null) {
						map.put(u, cur++);
					}
					pw.print((char)(map.get(u)+'a'));
					if(j < m - 1) pw.print(" ");
				}
				pw.println();
			}
		}
		pw.close();
	}
	
	private int[] get(int[] cur, int[][][] next) {
		if(next[cur[0]][cur[1]][0] == cur[0] && next[cur[0]][cur[1]][1] == cur[1]) {
			return cur;
		}
		return next[cur[0]][cur[1]] = get(next[cur[0]][cur[1]], next);
	}
}
