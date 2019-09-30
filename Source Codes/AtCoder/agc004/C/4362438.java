import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] reds = new char[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (j == 0 || (j != w - 1 && i % 2 == 0)) {
					reds[i][j] = '#';
				} else {
					reds[i][j] = '.';
				}
			}
		}
		StringBuilder red = new StringBuilder();
		StringBuilder blue = new StringBuilder();
		char[][] blues = new char[h][w];
		for (int i = 0; i < h; i++) {
			char[] line = sc.next().toCharArray();
			for (int j = 0; j < w; j++) {
				if (reds[i][j] == '#') {
					blues[i][j] = '.';
				} else {
					blues[i][j] = '#';
				}
				if (line[j] == '#') {
					reds[i][j] = '#';
					blues[i][j] = '#';
				}
			}
			red.append(new String(reds[i])).append("\n");
			blue.append(new String(blues[i])).append("\n");
		}
		System.out.println(red);
		System.out.print(blue);
	}
}