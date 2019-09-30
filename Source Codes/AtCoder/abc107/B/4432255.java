import java.util.Arrays;
import java.util.Scanner;

public class Main {
 	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();

		String board[][] = new String[H][W];

		for (int i = 0; i < board.length; i++) {
			board[i] = sc.next().split("");
		}

		boolean[] row = new boolean[H];
		Arrays.fill(row, false);
		boolean[] col = new boolean[W];
		Arrays.fill(col, false);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if(board[i][j].equals("#")) {
					row[i] = true;
					col[j] = true;
				}
			}
		}

		for (int i = 0; i < H; i++) {
			if (row[i]) {
				for (int j = 0; j < W; j++) {
					if (col[j]) {
						System.out.print(board[i][j]);
					}
				}
				System.out.println();
			}
		}
 	}
}