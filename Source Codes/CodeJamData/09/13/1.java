import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	int N = 50;
	void run() {
		long[][] comb = new long[N][N];
		comb[0][0] = 1;
		for (int i = 1; i < N; i++) {
			comb[i][0] = 1;
			for (int j = 1; j < N; j++) {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int m = sc.nextInt(), n = sc.nextInt();
			double[][] A = new double[m][m];
			double[] b = new double[m];
			for (int i = 0; i < m; i++) {
				double div = comb[m][n] - comb[i][n];
				b[i] = comb[m][n] / div;
				A[i][i] = 1;
				for (int j = 1; j <= n && i + j < m; j++) {
					double d = ((double)comb[i][n - j]) * comb[m - i][j];
					A[i][i + j] = -d / div;
				}
			}
			double[] x = solve(A, b);
			System.out.printf("%.10f%n", x[0]);
		}
	}
	double[] solve(double[][] A, double[] b) {
		int n = A.length;
		double[][] a = new double[n][n + 1];
		for (int i = 0; i < n; i++) {
			System.arraycopy(A[i], 0, a[i], 0, n);
			a[i][n] = b[i];
		}
		for (int p = 0; p < n; p++) {
			for (int i = p + 1; i < n; i++) {
				if (abs(a[i][p]) > abs(a[p][p])) {
					double[] t = a[i]; a[i] = a[p]; a[p] = t;
				}
			}
			double inv = 1 / a[p][p];
			for (int j = 0; j <= n; j++) a[p][j] *= inv;
			for (int i = 0; i < n; i++) if (i != p) {
				double d = a[i][p];
				for (int j = 0; j <= n; j++) a[i][j] -= d * a[p][j];
			}
		}
		double[] x = new double[n];
		for (int i = 0; i < n; i++) x[i] = a[i][n];
		return x;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
