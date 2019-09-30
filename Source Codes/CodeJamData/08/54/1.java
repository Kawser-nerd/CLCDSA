import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
	}
	long M = 10007;
	static final int[] di = {1, 2}, dj = {2, 1};
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int h = sc.nextInt(), w = sc.nextInt(), r = sc.nextInt();
			boolean[][] bs = new boolean[h][w];
			for (int i = 0; i < r; i++) bs[sc.nextInt() - 1][sc.nextInt() - 1] = true;
			long[][] dp = new long[h][w];
			dp[0][0] = 1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) if (!bs[i][j]) {
					for (int k = 0; k < 2; k++) {
						int ii = i + di[k], jj = j + dj[k];
						if (ii < h && jj < w) dp[ii][jj] = (dp[ii][jj] + dp[i][j]) % M;
					}
				}
			}
			System.out.println(dp[h - 1][w - 1]);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
