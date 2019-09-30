import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	long B;
	int N;
	long[] X;
	
	void read() {
		B = sc.nextLong();
		N = sc.nextInt();
		X = new long[37];
		for (int i = 0; i < N; i++) X[i] = sc.nextLong();
	}
	
	void solve() {
		sort(X);
		TreeSet<Long> set = new TreeSet<>();
		for (int i = 0; i < 37; i++) {
			for (int j = -2; j <= 2; j++) if (X[i] + j > 0) set.add(X[i] + j);
		}
		double res = 0;
		for (int k = 1; k <= 37; k++) {
			loop : for (long x : set) {
				long need = 0;
				long can = Long.MAX_VALUE;
				int num = 0;
				for (int i = 0; i < k; i++) {
					if (X[i] > x) continue loop;
					need += x - X[i];
					num++;
				}
				long need2 = 0;
				int num2 = 0;
				for (int i = k; i < 37; i++) {
					if (X[i] <= x) {
						need2 += x - X[i] + 1;
						num2++;
					} else can = min(can, X[i] - 1);
				}
				if (need + need2 <= B) {
					long i = 0;
					for (long add = 10000000000L; add > 0; add /= 10) {
						for ( ; x + i <= can && need + num * i + need2 + num2 * i <= B; i += add) {
							res = max(res, (need + num * i) * 36.0 / k - need - num * i - need2 - num2 * i);
						}
						i -= add;
					}
				}
			}
		}
		System.out.printf("%.10f%n", res);
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
