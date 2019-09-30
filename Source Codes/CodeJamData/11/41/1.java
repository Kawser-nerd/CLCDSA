import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void solve() {
		int X = sc.nextInt(), S = sc.nextInt(), R = sc.nextInt(), t = sc.nextInt(), N = sc.nextInt();
		int[] B = new int[N], E = new int[N], w = new int[N];
		for (int i = 0; i < N; i++) {
			B[i] = sc.nextInt();
			E[i] = sc.nextInt();
			w[i] = sc.nextInt();
		}
		int[] s = new int[X];
		for (int i = 0; i < N; i++) {
			for (int x = B[i]; x < E[i]; x++) s[x] = w[i];
		}
		sort(s);
		double res = 0, T = t;
		for (int i = 0; i < X; i++) {
			if (T > 0) {
				double time = 1.0 / (s[i] + R);
				if (time <= T) {
					T -= time;
					res += 1.0 / (s[i] + R);
				} else {
					res += T + (1.0 - (s[i] + R) * T) / (s[i] + S);
					T = 0;
				}
			} else {
				res += 1.0 / (s[i] + S);
			}
		}
		System.out.printf("%.10f%n", res);
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
