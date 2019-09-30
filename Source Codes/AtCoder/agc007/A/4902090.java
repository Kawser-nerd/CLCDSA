import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] field = new char[h][];
		for (int i = 0; i < h; i++) {
			field[i] = sc.next().toCharArray();
		}
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (field[i][j] == '#') {
					count++;
					if (i == 0 && j == 0) {
						
					} else if ((i != 0 && field[i - 1][j] == '#') ^ (j != 0 && field[i][j - 1] == '#')) {
						
					} else {
						System.out.println("Impossible");
						return;
					}
					if (i == h - 1 && j == w - 1) {
						
					} else if ((i != h - 1 && field[i + 1][j] == '#') ^ (j != w - 1 && field[i][j + 1] == '#')) {
						
					} else {
						System.out.println("Impossible");
						return;
					}
				}
			}
		}
		if (count == h + w - 1) {
			System.out.println("Possible");
		} else {
			System.out.println("Impossible");
		}
	}
}