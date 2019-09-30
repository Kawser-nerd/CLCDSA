package gcj2009.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class B_Watersheds {

	private static boolean SMALL = false;
	private static String PROBLEM = "B";

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large"))));
			PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))));

			int N = scan.nextInt();
			scan.nextLine();
			System.out.println(String.format("%d test cases:", N));
			long start = System.currentTimeMillis(), t1, left;
			for (int CASE = 1; CASE <= N; ++CASE) {
				t1 = System.currentTimeMillis();
				System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

				int H = scan.nextInt(), W = scan.nextInt();
				int[][] alt_map = new int[H][W];
				int[][] map = new int[H][W];
				for (int i = 0; i < H; ++i) {
					for (int j = 0; j < W; ++j) {
						alt_map[i][j] = scan.nextInt();
						map[i][j] = -1;
					}
				}
				int sinkN = 0;
				for (int i = 0; i < H; ++i)
					for (int j = 0; j < W; ++j)
						if ((i == 0 || alt_map[i - 1][j] >= alt_map[i][j]) && (j == 0 || alt_map[i][j - 1] >= alt_map[i][j]) && (j == W - 1 || alt_map[i][j + 1] >= alt_map[i][j]) && (i == H - 1 || alt_map[i + 1][j] >= alt_map[i][j]))
							map[i][j] = sinkN++;
				for (int i = 0; i < H; ++i) {
					for (int j = 0; j < W; ++j) {
						if (map[i][j] == -1) {
							int ii = i, jj = j;
							while (map[ii][jj] == -1) {
								int iii = i, jjj = j, min = 1234567890;
								if (ii > 0 && alt_map[ii - 1][jj] < min) {
									min = alt_map[ii - 1][jj];
									iii = ii - 1;
									jjj = jj;
								}
								if (jj > 0 && alt_map[ii][jj - 1] < min) {
									min = alt_map[ii][jj - 1];
									iii = ii;
									jjj = jj - 1;
								}
								if (jj < W - 1 && alt_map[ii][jj + 1] < min) {
									min = alt_map[ii][jj + 1];
									iii = ii;
									jjj = jj + 1;
								}
								if (ii < H - 1 && alt_map[ii + 1][jj] < min) {
									min = alt_map[ii + 1][jj];
									iii = ii + 1;
									jjj = jj;
								}
								ii = iii;
								jj = jjj;
							}
							map[i][j] = map[ii][jj];
						}
					}
				}
				int[] arr = new int[W * H];
				for (int i = 0; i < H; ++i)
					for (int j = 0; j < W; ++j)
						arr[i * W + j] = map[i][j];
				char now = 'a';
				char[] ret = new char[arr.length];
				for (int i = 0; i < ret.length; ++i)
					ret[i] = '-';
				for (int i = 0; i < ret.length; ++i) {
					if (ret[i] == '-') {
						ret[i] = now;
						for (int j = 0; j < arr.length; ++j)
							if (arr[j] == arr[i])
								ret[j] = now;
						now++;
					}
				}
				pw.println(String.format("Case #%d:", CASE));
				for (int i = 0; i < H; ++i) {
					for (int j = 0; j < W; ++j) {
						pw.print(ret[i * W + j] + " ");
						System.out.print(ret[i * W + j] + " ");
					}
					pw.println();
					System.out.println();
				}
				String res = "";
				left = (System.currentTimeMillis() - start) * (N - CASE) / CASE;
				System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
			}
			pw.close();
			scan.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
