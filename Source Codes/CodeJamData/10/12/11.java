import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class B {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "B";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			int L = 256;
			int[][] dp = new int[2][L];
			int D = sc.nextInt(), I = sc.nextInt(), M = sc.nextInt(), N = sc.nextInt();
			int[] as = new int[N];
			for (int i = 0; i < N; i++) {
				as[i] = sc.nextInt();
			}
			if (D == 0 || (I == 0 && M > 0)) {
				System.out.println(0);
				continue;
			}
			for (int i = 0; i < N; i++) {
				int cur = i % 2, nxt = (i + 1) % 2;
				fill(dp[nxt], 1 << 28);
				for (int j = 0; j < L; j++) {//bef
					dp[nxt][j] = min(dp[nxt][j], dp[cur][j] + D);
					for (int k = 0; k < L; k++) {//cur
						int d = abs(as[i] - k);
						if (abs(j - k) <= M) {
							dp[nxt][k] = min(dp[nxt][k], dp[cur][j] + d);
						} else if (M > 0) {
							dp[nxt][k] = min(dp[nxt][k], dp[cur][j] + (abs(k - j) - 1) / M * I + d);
						}
					}
				}
//				debug(dp[nxt]);
			}
			int res = 1 << 28;
			for (int i = 0; i < L; i++) {
				res = min(res, dp[N % 2][i]);
			}
			System.out.println(res);
		}
	}

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new B().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new B().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new B().run();
			}
		} else
			new B().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
