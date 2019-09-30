import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int m = sc.nextInt();
		long[] a = new long[k];
		long[] c = new long[k];
		for (int i = 0; i < k; ++i) {
			a[i] = sc.nextLong();
		}
		for (int i = 0; i < k; ++i) {
			c[i] = sc.nextLong();
		}
		long ans = 0;
		for (int i = 0; i < 32; ++i) {
			int[][] mat = new int[k][k];
			for (int j = 0; j + 1 < k; ++j) {
				mat[j][j + 1] = 1;
			}
			for (int j = 0; j < k; ++j) {
				mat[k - 1][j] = (int) ((c[k - 1 - j] >> i) & 1);
			}
			int[][] v = new int[k][1];
			for (int j = 0; j < k; ++j) {
				v[j][0] = (int) ((a[j] >> i) & 1);
			}
			v = pow(mat, v, m - 1);
			ans += (long) v[0][0] << i;
		}
		System.out.println(ans);
	}

	static int[][] pow(int[][] a, int[][] v, long n) {
		for (; n > 0; n >>= 1, a = mul(a, a)) {
			if (n % 2 == 1) {
				v = mul(a, v);
			}
		}
		return v;
	}

	static int[][] mul(int[][] a, int[][] b) {
		int[][] ret = new int[a.length][b[0].length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < b[i].length; ++j) {
				for (int k = 0; k < a[0].length; ++k) {
					ret[i][j] ^= a[i][k] & b[k][j];
				}
			}
		}
		return ret;
	}

}