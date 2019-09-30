import java.util.*;

// ARC 93-D
// https://beta.atcoder.jp/contests/arc093/tasks/arc093_b

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int numWhite = in.nextInt();
		int numBlack = in.nextInt();
		
		char WHITE = '.';
		char BLACK = '#';
		
		char[][] map = new char[100][100];
		
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				// Left half is white and right half is black
				map[i][j] = j <= 49 ? WHITE : BLACK;
			}
		}
		
		int count = 1;
		// Fill black in white canvas
		for (int i = 0; i < 100; i += 2) {
			for (int j = 0; j <= 49 && count < numBlack; j += 2) {
				map[i][j] = BLACK;
				count++;
			}
		}
		
		count = 1;
		// Fill white in black canvas
		for (int i = 0; i < 100; i += 2) {
			for (int j = 51; j < 100 && count < numWhite; j += 2) {
				map[i][j] = WHITE;
				count++;
			}
		}
		
		System.out.println("100 100");
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				System.out.printf("%c", map[i][j]);
			}
			System.out.println();
		}
	}
}