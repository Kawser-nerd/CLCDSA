import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] S = new char[H][W];
		String[][] T = new String[H][W];

		for (int i = 0; i < H; i++) {
			String l = sc.next();
			S[i] = l.toCharArray();
		}

		for (int h = 0; h < H; h++) {
			char[] line = S[h];
			for (int w = 0; w < W; w++) {
				if (line[w] == '#') {
					T[h][w] = Character.toString(line[w]);
				} else {
					T[h][w] = Integer.toString(calc(S, h, w, H, W));
				}
				System.out.print(T[h][w]);
			}
			System.out.println();
		}
	}

	int calc(char[][] S, int h, int w, int H, int W) {
		int cnt = 0;

		if (h >= 1 && w >= 1 && S[h - 1][w - 1] == '#') {
			cnt++;
		}
		if (h >= 1 && S[h - 1][w] == '#') {
			cnt++;
		}
		if (h >= 1 && w < W - 1 && S[h - 1][w + 1] == '#') {
			cnt++;
		}
		if (w >= 1 && S[h][w - 1] == '#') {
			cnt++;
		}
		if (w < W - 1 && S[h][w + 1] == '#') {
			cnt++;
		}
		if (h < H-1 && w >= 1 && S[h + 1][w - 1] == '#') {
			cnt++;
		}
		if (h < H-1 && S[h + 1][w] == '#') {
			cnt++;
		}
		if (h < H-1 && w < W - 1 && S[h + 1][w + 1] == '#') {
			cnt++;
		}
		return cnt;
	}
}