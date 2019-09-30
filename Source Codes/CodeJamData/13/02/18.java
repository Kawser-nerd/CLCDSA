import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmower {

	public static boolean check(int[][] map, int N, int M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				boolean flag = true, flag2 = true;
				for (int k = 0; k < N; k++) {
					if (map[k][j] > map[i][j]) {
						flag = false;
						break;
					}
				}
				for (int k = 0; k < M; k++) {
					if (map[i][k] > map[i][j]) {
						flag2 = false;
						break;
					}
				}
				if (!flag && !flag2)
					return false;
			}
		}
		return true;
	}

	public static void main(String args[]) throws Exception {
		Scanner in = new Scanner(new FileInputStream("B-large.in"));
		PrintWriter writer = new PrintWriter(
				new FileOutputStream("B-large.out"));
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int M = in.nextInt();
			int[][] map = new int[N][M];
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					map[j][k] = in.nextInt();
				}
			}
			boolean result = check(map, N , M );
			writer.write("Case #" + (i + 1) + ": ");
			writer.println(result ? "YES" : "NO");
		}
		in.close();
		writer.close();
	}
}
