import java.util.Arrays;
import java.util.Scanner;

class Main {

	public void run() {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int[][] d = new int[A][B];
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				d[i][j] = sc.nextInt();
			}
		}

		//d[x][y]=min(c[i][j]+i*x+j*y);
		int[][] c = new int[101][101];
		for (int x = 0; x < A; ++x) {
			for (int y = 0; y < B; ++y) {
				for (int i = 0; i <= 100; ++i) {
					for (int j = 0; j <= 100; ++j) {
						c[i][j] = Math.max(c[i][j], d[x][y] - (x + 1) * i - (y + 1) * j);
					}
				}
			}
		}
		int[][] d_now = new int[A][B];
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				d_now[i][j] = Integer.MAX_VALUE / 3;
			}
		}

		for (int i = 0; i <= 100; ++i) {
			for (int j = 0; j <= 100; ++j) {
				for (int x = 0; x < A; ++x) {
					for (int y = 0; y < B; ++y) {
						d_now[x][y] = Math.min(d_now[x][y], c[i][j] + (x + 1) * i + (y + 1) * j);
					}
				}
			}
		}
		for (int x = 0; x < A; ++x) {
			for (int y = 0; y < B; ++y) {
				if (d[x][y] != d_now[x][y]) {
					System.out.println("Impossible");
					return;
				}
			}
		}
		System.out.println("Possible");
		System.out.println(300 + " " + (100 + 100 + 101 * 101 + 2));
		for (int i = 1; i <= 100; ++i) {
			System.out.println(i + " " + (i + 1) + " X");
		}
		for (int i = 102; i <= 201; ++i) {
			System.out.println(i + " " + (i + 1) + " Y");
		}
		for (int i = 0; i <= 100; ++i) {
			for (int j = 0; j <= 100; ++j) {
				System.out.println((i + 1) + " " + (202 - j) + " " + c[i][j]);
			}
		}
		int s = 299;
		int t = 300;
		System.out.println(s + " " + 1 + " " + 0);
		System.out.println(202 + " " + t + " " + 0);
		System.out.println(s + " " + t);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}