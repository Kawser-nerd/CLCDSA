import java.util.Scanner;

public class C {
	public static int[][] board;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int M = s.nextInt();
			int N = s.nextInt();
			int si = Math.min(M, N);
			s.nextLine();

			int ans[] = new int[si + 1];
			for (int j = 1; j < ans.length; j++) {
				ans[j] = 0;
			}
			board = new int[M][N];

			for (int j = 0; j < M; j++) {
				String str = s.nextLine();
				for (int j2 = 0; j2 < N; j2 += 4) {
					char h = str.charAt(j2 / 4);
					int x = Character.digit(h, 16);
					if (x >= 8) {
						board[j][j2] = 1;
					} else {
						board[j][j2] = 0;
					}
					if (x % 8 >= 4) {
						board[j][j2 + 1] = 1;
					} else {
						board[j][j2 + 1] = 0;
					}
					if (x % 4 >= 2) {
						board[j][j2 + 2] = 1;
					} else {
						board[j][j2 + 2] = 0;
					}
					if (x % 2 >= 1) {
						board[j][j2 + 3] = 1;
					} else {
						board[j][j2 + 3] = 0;
					}
				}
			}
			for (int size = si; size > 0; size--) {
				for (int j = 0; j <= M - size; j++) {
					for (int j2 = 0; j2 <= N - size; j2++) {
						if (check(j, j2, size)) {
							ans[size]++;
						}
					}
				}
			}

			// puts answer
			int sum = 0;
			for (int j = 1; j < ans.length; j++) {
				if (ans[j] > 0) {
					sum++;
				}
			}
			System.out.printf("Case #%d: %d\n", i + 1, sum);
			for (int j = ans.length - 1; j > 0; j--) {
				if (ans[j] > 0) {
					System.out.printf("%d %d\n", j, ans[j]);
				}
			}
		}
	}

	public static void pb() {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				System.out.print(board[i][j]);
			}
		System.out.println();
		}
	}
	public static boolean check(int x, int y, int s) {
		int c = board[x][y];

		if (c == 2) {
			return false;
		}
		for (int i = x + 1; i < x + s; i++) {
			if (board[i][y] == 2) {
				return false;
			}
			if (c == board[i][y]) {
				return false;
			}
			c = board[i][y];
		}
		for (int i = x; i < x + s; i++) {
			c = board[i][y];
			for (int j = y + 1; j < y + s; j++) {

				if (board[i][j] == 2) {
					return false;
				}
				if (c == board[i][j]) {
					return false;
				}
				c = board[i][j];
			}
		}
		for (int i = x; i < x + s; i++) {
			for (int j = y; j <  y + s; j++) {
				board[i][j] = 2;
			}
		}
		return true;
	}

}
