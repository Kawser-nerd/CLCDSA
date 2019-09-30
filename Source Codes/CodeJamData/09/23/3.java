import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BaiC {

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };

	static final int MAX = 240;

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("C-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out3.txt"));

		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			System.out.println(test);
			int n = sc.nextInt();
			int q = sc.nextInt();
			sc.nextLine();
			char[][] a = new char[n][];
			for (int i = 0; i < n; ++i)
				a[i] = sc.nextLine().toCharArray();

			String[][][] F = new String[n][n][MAX * 2];
			int[][][] d = new int[n][n][MAX * 2];
			Queue<Integer> qx = new LinkedList<Integer>();
			Queue<Integer> qy = new LinkedList<Integer>();
			Queue<Integer> qz = new LinkedList<Integer>();

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j)
					if ('0' <= a[i][j] && a[i][j] <= '9') {
						F[i][j][a[i][j] - '0' + MAX / 2] = "" + a[i][j];
						d[i][j][a[i][j] - '0' + MAX / 2] = 1;
						qx.add(i);
						qy.add(j);
						qz.add(a[i][j] - '0' + MAX / 2);
					}
			}

			while (!qx.isEmpty()) {
				int u = qx.remove();
				int v = qy.remove();
				int t = qz.remove();
				for (int h = 0; h < 4; ++h) {
					int x = u + dx[h];
					int y = v + dy[h];
					if (0 <= x && x < n && 0 <= y && y < n) {
						for (int h2 = 0; h2 < 4; ++h2) {
							int i = x + dx[h2];
							int j = y + dy[h2];
							if (0 <= i && i < n && 0 <= j && j < n) {
								int newt = 0;
								if (a[x][y] == '+')
									newt = t + a[i][j] - '0';
								else
									newt = t - (a[i][j] - '0');
								if (0 <= newt && newt < 2 * MAX) {
									if (d[i][j][newt] == 0) {
										d[i][j][newt] = d[u][v][t] + 1;
										F[i][j][newt] = F[u][v][t] + a[x][y] + a[i][j];
										qx.add(i);
										qy.add(j);
										qz.add(newt);
									} else if (d[i][j][newt] == d[u][v][t] + 1) {
										String s = F[u][v][t] + a[x][y] + a[i][j];
										if (F[i][j][newt].compareTo(s) > 0) {
											F[i][j][newt] = s;
											qx.add(i);
											qy.add(j);
											qz.add(newt);
										}
									}
								}
							}
						}
					}
				}
			}

			pw.println("Case #" + test + ":");

			for (int t = 0; t < q; ++t) {
				int x = sc.nextInt() + MAX / 2;
				String s = null;
				int len = 0;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j)
						if (d[i][j][x] > 0) {
							if (len == 0 || len > d[i][j][x]) {
								len = d[i][j][x];
								s = F[i][j][x];
							} else if (len == d[i][j][x] && s.compareTo(F[i][j][x]) > 0) {
								s = F[i][j][x];
							}
						}
				}
				pw.println(s);
			}
		}

		pw.close();
		sc.close();
	}
}
