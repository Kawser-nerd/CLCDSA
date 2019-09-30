import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	
	PrintWriter out;
	
	int P, Q, N;
	int[] H, G;
	
	void read(Scanner sc) {
		P = sc.nextInt();
		Q = sc.nextInt();
		N = sc.nextInt();
		H = new int[N];
		G = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = sc.nextInt();
			G[i] = sc.nextInt();
		}
	}
	
	int INF = 1 << 29;
	
	void solve() {
		int T = 1000;
		int[][][] dp = new int[N + 1][201][T + 1];
		for (int i = 0; i <= N; i++) for (int j = 0; j <= 200; j++) fill(dp[i][j], -INF);
		dp[0][0][1] = 0;
		for (int i = 0; i < N; i++) {
			for (int d = 0; d < H[i]; d++) {
				for (int t = T; t >= 0; t--) if (dp[i][d][t] >= 0) {
					// attack
					if (t > 0) {
						if (d + P >= H[i]) {
							dp[i + 1][0][t - 1] = max(dp[i + 1][0][t - 1], dp[i][d][t] + G[i]);
						} else {
							dp[i][d + P][t - 1] = max(dp[i][d + P][t - 1], dp[i][d][t]);
						}
					}
					// pass
					if (t + 1 <= T) {
						if (d + Q >= H[i]) {
							dp[i + 1][0][t + 1] = max(dp[i + 1][0][t + 1], dp[i][d][t]);
						} else {
							dp[i][d + Q][t + 1] = max(dp[i][d + Q][t + 1], dp[i][d][t]);
						}
					}
				}
			}
		}
		int res = 0;
		for (int t = 0; t <= T; t++) res = max(res, dp[N][0][t]);
		out.println(res);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static int __ID = 0;
	public static boolean __ERROR = false;
	
	public static void main(String[] args) {
		int pN = 1;
		if (args.length == 0) {
			try {
				System.setIn(new BufferedInputStream(new FileInputStream(B.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final B[] solvers = new B[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new B();
			outs[i] = new StringWriter();
			solvers[i].out = new PrintWriter(outs[i]);
			solvers[i].out.printf("Case #%d: ", i + 1);
			solvers[i].read(sc);
		}
		Thread[] ts = new Thread[pN];
		for (int i = 0; i < pN; i++) {
			ts[i] = new Thread() {
				@Override
				public void run() {
					for (;;) {
						int id;
						synchronized (B.class) {
							if (__ID == caseN) return;
							id = __ID++;
						}
						try {
							solvers[id].solve();
						} catch (RuntimeException e) {
							__ERROR = true;
							System.err.printf("Error in case %d:%n", id + 1);
							e.printStackTrace();
						}
						solvers[id].out.flush();
						solvers[id] = null;
					}
				}
			};
			ts[i].start();
		}
		for (int i = 0; i < pN; i++) {
			try {
				ts[i].join();
			} catch (InterruptedException e) {
				i--;
				continue;
			}
		}
		for (int i = 0; i < caseN; i++) {
			out.print(outs[i].toString());
		}
		if (__ERROR) out.printf("%nError occured!!!%n");
	}
	
}
