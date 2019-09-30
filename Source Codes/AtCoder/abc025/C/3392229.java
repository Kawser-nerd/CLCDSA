import java.util.Scanner;

public class Main {
	static char[][] a = new char[3][3];
	static int s1[];
	static int s2[];
	static int cnt = 0;
	static int[][] b = new int[2][3];
	static int[][] c = new int[3][2];
	static int g[][] = new int[3][3];
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int sum = 0;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				b[i][j] = scan.nextInt();
				sum += b[i][j];
			}
		}
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				c[i][j] = scan.nextInt();
				sum += c[i][j];
			}
		}
		scan.close();
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				a[i][j] = '*';
			}
		}
		int score = minimax(0);
		System.out.println(score);
		System.out.println(sum - score);
	}
	static int minimax(int depth) {
		if(depth == 9) {
			return score();
		}
		if(depth % 2 == 0) {
			int max = -1;
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					if(a[i][j] != '*') continue;
					a[i][j] = 'o';
					max = Math.max(max, minimax(depth + 1));
					a[i][j] = '*';
				}
			}
			return max;
		}else {
			int min = Integer.MAX_VALUE;
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					if(a[i][j] != '*') continue;
					a[i][j] = 'x';
					min = Math.min(min, minimax(depth + 1));
					a[i][j] = '*';
				}
			}
			return min;
		}
	}
	static int score() {
		int score = 0;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				if(a[i][j] == a[i + 1][j]) {
					score += b[i][j];
				}
			}
		}
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				if(a[i][j] == a[i][j + 1]) {
					score += c[i][j];
				}
			}
		}
		return score;
	}
}