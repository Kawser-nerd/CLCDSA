import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m, p, q, r;
		n = sc.nextInt();
		m = sc.nextInt();
		p = sc.nextInt();
		q = sc.nextInt();
		r = sc.nextInt();
		int[][] mat = new int[n][m];
		for (int i = 0; i < r; ++i) {
			int x, y, z;
			x = sc.nextInt();
			y = sc.nextInt();
			z = sc.nextInt();
			--x;
			--y;
			mat[x][y] = z;
		}
		int ans = 0;
		for (int s = 0; s < 1 << n; ++s) {
			if (Integer.bitCount(s) != p)
				continue;
			int[] a = new int[m];
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (((s >> j) & 1) > 0) {
						a[i] += mat[j][i];
					}
				}
			}
			Arrays.sort(a);

			int tmp = 0;
			for (int i = 0; i < q; ++i) {
				tmp += a[a.length - 1 - i];
			}
			ans=Math.max(ans, tmp);
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}