import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] s = new char[h][w];
		for (int i = 0; i < h; i++) {
			String str = sc.next();
			s[i] = str.toCharArray();
		}
		sc.close();

		boolean flg = true;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (s[i][j] == '#') {
					if (i > 0 && s[i - 1][j] == '#') {
						continue;
					}
					if (i < h - 1 && s[i + 1][j] == '#') {
						continue;
					}
					if (j > 0 && s[i][j - 1] == '#') {
						continue;
					}
					if (j < w - 1 && s[i][j + 1] == '#') {
						continue;
					}
					flg = false;
					break;
				}
			}
		}

		if (flg) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}