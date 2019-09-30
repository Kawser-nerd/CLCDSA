import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] field = new char[h][w];
		for (int i = 0; i < h; i++) {
			field[i] = sc.next().toCharArray();
		}
		char[][] next = new char[h][w];
		for (char[] line : next) {
			Arrays.fill(line, '#');
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (field[i][j] == '.') {
					for (int k = i - 1; k <= i + 1; k++) {
						for (int l = j - 1; l <= j + 1; l++) {
							if (k < 0 || k >= h || l < 0 || l >= w) {
								continue;
							}
							next[k][l] = '.';
						}
					}
				}
			}
		}
		char[][] reverse = new char[h][w];
		for (char[] line : reverse) {
			Arrays.fill(line, '.');
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (next[i][j] == '#') {
					for (int k = i - 1; k <= i + 1; k++) {
						for (int l = j - 1; l <= j + 1; l++) {
							if (k < 0 || k >= h || l < 0 || l >= w) {
								continue;
							}
							reverse[k][l] = '#';
						}
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (field[i][j] != reverse[i][j]) {
					System.out.println("impossible");
					return;
				}
			}
			sb.append(next[i]).append("\n");
		}
		System.out.println("possible");
		System.out.print(sb);
	}
}