import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	
	int N = 10000;
	int[] dp = new int[N + 2];
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			int[][] g = new int[n][3];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					g[i][j] = sc.nextInt();
				}
			}
			int max = 0;
			for (int a = 0; a <= N; a++) {
				fill(dp, 0);
				for (int i = 0; i < n; i++) if (a >= g[i][0]) {
					int mb = N - a - g[i][2];
					if (g[i][1] <= mb) {
						dp[g[i][1]]++;
						dp[mb + 1]--;
					}
				}
				int sum = 0;
				for (int b = 0; b <= N; b++) {
					sum += dp[b];
					if (max < sum) max = sum;
				}
			}
			System.out.println(max);
		}
	}

	void small_run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			int[][] g = new int[n][3];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					g[i][j] = sc.nextInt();
				}
			}
			int max = 0;
			for (int a = 0; a <= 10000; a++) {
				for (int b = 0; a + b <= 10000; b++) {
					int c = 10000 - a - b;
					int tmp = 0;
					for (int i = 0; i < n; i++) {
						if (a >= g[i][0] && b >= g[i][1] && c >= g[i][2]) tmp++;
					}
					max = max(max, tmp);
				}
			}
			System.out.println(max);
		}
	}
	
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
