import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	public static void main(String[] args) {
		BigInteger[][] combine = new BigInteger[512][512];
		BigInteger[][] a = new BigInteger[512][512];
		BigInteger[] s = new BigInteger[512];
		for (int i = 0; i < 512; i++) {
			combine[i][0] = BigInteger.ONE;
			combine[i][i] = BigInteger.ONE;
			for (int j = 1; j < i; j++) {
				combine[i][j] = combine[i-1][j].add(combine[i-1][j-1]);
			}
			for (int j = 0; j < 512; j++)
				a[i][j] = BigInteger.ZERO;
			s[i] = BigInteger.ZERO;
		}
		for (int n = 2; n < 512; n++) {
			a[n][1] = BigInteger.ONE;
			for (int m = 2; m < n; m++) {
				a[n][m] = BigInteger.ZERO;
				for (int k = 1; k < m; k++) {
					int N = n - m - 1;
					int M = m - k - 1;
					if (M >= 0 && M <= N) {
						a[n][m] = a[n][m].add(combine[N][M].multiply(a[m][k]));
					}
				}
			}
			for (int m = 1; m < n; m++) {
				s[n] = s[n].add(a[n][m]);
			}
		}
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int cas = 1; cas <= tests; cas++) {
			int n = sc.nextInt();
			System.out.println("Case #" + cas + ": " + (s[n].mod(BigInteger.valueOf(100003))));
		}
	}
}
