import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	static boolean SAMPLE;
	Scanner sc;
	
	int INF = 1 << 29;
	
	void solve() {
		int P = sc.nextInt();
		int[] need = new int[1 << P];
		for (int i = 0; i < 1 << P; i++) need[i] = max(0, P - sc.nextInt());
		int[][] cost = new int[P][];
		for (int i = 0; i < P; i++) {
			cost[i] = new int[1 << (P - i - 1)];
			for (int j = 0; j < cost[i].length; j++) cost[i][j] = sc.nextInt();
		}
		int[][][] dp = new int[P + 1][1 << P][P + 1];
		for (int i = 0; i < 1 << P; i++) {
			fill(dp[0][i], INF);
			for (int j = need[i]; j <= P; j++) {
				dp[0][i][j] = 0;
			}
		}
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < cost[i].length; j++) {
				for (int k = 0; k <= P; k++) {
					dp[i + 1][j][k] = dp[i][j * 2][k] + dp[i][j * 2 + 1][k];
					if (dp[i + 1][j][k] > INF) dp[i + 1][j][k] = INF;
				}
				for (int k = 0; k < P; k++) {
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i + 1][j][k + 1] + cost[i][j]);
				}
			}
		}
		System.out.println(dp[P][0][0]);
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (!SAMPLE) System.err.printf("%03d/%03d %.3f/%.3f%n", caseID, caseN, t, t / (caseID - 1) * caseN);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream(B.class.getName() + ".in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new B().run();
	}
}
