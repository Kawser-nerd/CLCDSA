import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int h = sc.nextInt(), w = sc.nextInt();
		char[][] board = new char[h][w];
		for (int i = 0; i < h; i++) {
			String s = sc.next();
			for (int j = 0; j < w; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '#') {
					continue;
				}
				char count = '0';
				for (int k = -1; k <= 1; k++) {
					if (i == 0 && k == -1 || i == h - 1 && k == 1) {
						continue;
					}
					for (int l = -1; l <= 1; l++) {
						if (j == 0 && l == -1 || j == w - 1 && l == 1 || k == 0 && l == 0) {
							continue;
						}
						if (board[i + k][j + l] == '#') {
							count++;
						}
					}
				}
				board[i][j] = count;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				sb.append(board[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}