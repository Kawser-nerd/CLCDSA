import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int N;
	char[] oc;
	
	void read() {
		oc = sc.next().toCharArray();
		N = oc.length;
	}
	
	void solve() {
		double[] dp = new double[1 << N];
		for (int i = (1 << N) - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) if ((i >> ((j + k) % N) & 1) == 0) {
					dp[i] += (dp[i | 1 << ((j + k) % N)] + N - k) / N;
					break;
				}
			}
		}
		int r = 0;
		for (int i = 0; i < N; i++) if (oc[i] == 'X') r |= 1 << i;
		System.out.printf("%.10f%n", dp[r]);
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
