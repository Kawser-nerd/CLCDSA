import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] a = new char[H][W];
		for (int i = 0; i < H; ++i) {
			a[i] = sc.next().toCharArray();
		}
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (j != W - 1 && (j == 0 || a[i][j] == '#' || i % 2 == 0)) {
					System.out.print('#');
				} else {
					System.out.print('.');
				}
			}
			System.out.println();
		}

		System.out.println();

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (j != 0 && (j == W - 1 || a[i][j] == '#' || i % 2 == 1)) {
					System.out.print('#');
				} else {
					System.out.print('.');
				}
			}
			System.out.println();
		}
		
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}