import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void solve() {
		int R = sc.nextInt(), C = sc.nextInt(), D = sc.nextInt();
		int[][] w = new int[R][C];
		for (int i = 0; i < R; i++) {
			char[] cs = sc.next().toCharArray();
			for (int j = 0; j < C; j++) w[i][j] = cs[j] - '0';
		}
		long[][] wX = new long[R][C];
		long[][] wY = new long[R][C];
		long[][] sum = new long[R + 1][C + 1];
		long[][] sumX = new long[R + 1][C + 1];
		long[][] sumY = new long[R + 1][C + 1];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				wX[i][j] = w[i][j] * i;
				wY[i][j] = w[i][j] * j;
				sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + w[i][j];
				sumX[i + 1][j + 1] = sumX[i + 1][j] + sumX[i][j + 1] - sumX[i][j] + wX[i][j];
				sumY[i + 1][j + 1] = sumY[i + 1][j] + sumY[i][j + 1] - sumY[i][j] + wY[i][j];
			}
		}
		for (int K = min(R, C); K >= 3; K--) {
			for (int i = 0; i + K <= R; i++) {
				for (int j = 0; j + K <= C; j++) {
					long S = sum[i + K][j + K] - sum[i][j + K] - sum[i + K][j] + sum[i][j] - w[i][j] - w[i + K - 1][j] - w[i][j + K - 1] - w[i + K - 1][j + K - 1];
					long SX = sumX[i + K][j + K] - sumX[i][j + K] - sumX[i + K][j] + sumX[i][j] - wX[i][j] - wX[i + K - 1][j] - wX[i][j + K - 1] - wX[i + K - 1][j + K - 1];
					long SY = sumY[i + K][j + K] - sumY[i][j + K] - sumY[i + K][j] + sumY[i][j] - wY[i][j] - wY[i + K - 1][j] - wY[i][j + K - 1] - wY[i + K - 1][j + K - 1];
					if (2 * SX - S * (2 * i + K - 1) == 0 && 2 * SY - S * (2 * j + K - 1) == 0) {
						System.out.println(K);
						return;
					}
				}
			}
		}
		System.out.println("IMPOSSIBLE");
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
