import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int h = sc.nextInt(), w = sc.nextInt();
		char[][] map = new char[h][w];
		for (int i = 0; i < h; i++) {
			map[i] = sc.next().toCharArray();
		}
		char[][] red = new char[h][w];
		char[][] blue = new char[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if(map[i][j] == '#') {
					red[i][j] = blue[i][j] = '#';
					continue;
				}
				if((i % 2 == 0 && j != w-1) || (i % 2 == 1 && j == 0)) {
					red[i][j] = '#';
					blue[i][j] = '.';
				} else {
					red[i][j] = '.';
					blue[i][j] = '#';
				}
			}
		}
		printArr(red);
		System.out.println();
		printArr(blue);
	}

	static void printArr(char[][] arr) {
		for (char[] chars : arr) {
			for (char c : chars) {
				System.out.print(c);
			}
			System.out.println();
		}
	}
}