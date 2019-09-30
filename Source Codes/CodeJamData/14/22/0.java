import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int A, B, K;
	
	void read() {
		A = sc.nextInt();
		B = sc.nextInt();
		K = sc.nextInt();
	}
	
	void solveSmall() {
		long res = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) res++;
			}
		}
		System.out.println(res);
	}
	
	void solve() {
		long[][] dp = new long[31][8];
		dp[30][7] = 1;
		for (int i = 29; i >= 0; i--) {
			for (int j = 0; j < 8; j++) {
				for (int a = 0; a < 2; a++) {
					for (int b = 0; b < 2; b++) {
						int k = a & b;
						if ((j & 1) != 0 && a > (A >> i & 1)) continue;
						if ((j >> 1 & 1) != 0 && b > (B >> i & 1)) continue;
						if ((j >> 2 & 1) != 0 && k > (K >> i & 1)) continue;
						int j2 = j;
						if (a < (A >> i & 1)) j2 &= ~(1 << 0);
						if (b < (B >> i & 1)) j2 &= ~(1 << 1);
						if (k < (K >> i & 1)) j2 &= ~(1 << 2);
						dp[i][j2] += dp[i + 1][j];
					}
				}
			}
		}
		System.out.println(dp[0][0]);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
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
