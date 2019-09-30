import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		int[][] a = new int[n][m];
		int[][] edgeV = new int[n][m];
		int[][] edgeH = new int[n][m];

		for (int i = 0; i < n; ++i) {
			String s = sc.next();
			for (int j = 0; j < m; ++j) {
				a[i][j] = (int) (s.charAt(j) - '0');
				if (i > 0 && a[i][j] == 1 && a[i - 1][j] == 1) {
					edgeV[i][j] = 1;
				}
				if (j > 0 && a[i][j] == 1 && a[i][j - 1] == 1) {
					edgeH[i][j] = 1;
				}
			}
		}

		System.gc();
		// ???
		// ???

		RectangleSum s1 = new RectangleSum(a, n, m);
		a = null;
		RectangleSum s2 = new RectangleSum(edgeH, n, m);
		edgeH = null;
		RectangleSum s3 = new RectangleSum(edgeV, n, m);
		edgeV = null;
		for (int i = 0; i < q; ++i) {
			int y1 = sc.nextInt() - 1;
			int x1 = sc.nextInt() - 1;
			int y2 = sc.nextInt();
			int x2 = sc.nextInt();
			int ans = 0;
			ans += s1.get(y1, y2, x1, x2);
			ans -= s2.get(y1, y2, x1 + 1, x2);
			ans -= s3.get(y1 + 1, y2, x1, x2);
			System.out.println(ans);
		}

	}

	class RectangleSum {
		int[][] sum;

		public RectangleSum(int[][] a, int h, int w) {
			sum = new int[h + 1][w + 1];
			for (int i = 1; i <= h; ++i) {
				for (int j = 1; j <= w; ++j) {
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i - 1][j - 1];
				}
			}
		}

		// [l,r)
		// [t,b)
		int get(int t, int b, int l, int r) {
			return sum[b][r] - sum[b][l] - sum[t][r] + sum[t][l];
		}

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}