import java.util.Arrays;
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
		long[][] mat = new long[k][k];
		for (int j = 0; j + 1 < k; ++j) {
			mat[j][j + 1] = (1L << 32) - 1;
		}
		for (int j = 0; j < k; ++j) {
			mat[k - 1][j] = c[k - 1 - j];
		}
		long[][] v = new long[k][1];
		for (int j = 0; j < k; ++j) {
			v[j][0] = a[j];
		}
		v = pow(mat, v, m - 1);
		System.out.println(v[0][0]);
	}

	static long[][] pow(long[][] a, long[][] v, long n) {
		for (; n > 0; n >>= 1, a = mul(a, a)) {
			if (n % 2 == 1) {
				v = mul(a, v);
			}
		}
		return v;
	}

	static long[][] mul(long[][] a, long[][] b) {
		long[][] ret = new long[a.length][b[0].length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < b[i].length; ++j) {
				for (int k = 0; k < a[0].length; ++k) {
					ret[i][j] ^= a[i][k] & b[k][j];
				}
			}
		}
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}