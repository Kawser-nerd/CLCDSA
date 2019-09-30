import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		int[] b = new int[N];
		int[] c = new int[N];
		int[] d = new int[N];
		boolean[][] map1 = new boolean[2 * N][2 * N];
		boolean[][] map2 = new boolean[2 * N][2 * N];
		//1
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			map1[a[i]][b[i]] = true;
		}
		//2
		for (int i = 0; i < N; ++i) {
			c[i] = sc.nextInt();
			d[i] = sc.nextInt();
			map2[c[i]][d[i]] = true;
		}
		int ans = 0;
		for (int i = 0; i < 2 * N; ++i) {
			out: for (int j = 0; j < 2 * N; ++j) {
				if (map2[i][j]) {
					for (int k = j - 1; k >= 0; --k) {
						if (map1[i][k]) {
							map1[i][k] = false;
							++ans;
							continue out;
						}
					}
				}
			}
			if (i + 1 < 2 * N)
				for (int j = 0; j < 2 * N; ++j) {
					map1[i + 1][j] |= map1[i][j];
				}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}