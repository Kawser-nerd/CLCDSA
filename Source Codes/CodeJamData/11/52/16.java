import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int M = 10010;
	
	void solve() {
		int N = sc.nextInt();
		if (N == 0) {
			System.out.println(0);
			return;
		}
		int[] is = new int[N];
		for (int i = 0; i < N; i++) is[i] = sc.nextInt();
		int[] num = new int[M];
		for (int i : is) num[i]++;
		int[] start = new int[N];
		int s = 0, t = 0;
		int res = Integer.MAX_VALUE;
		for (int i = 0; i < M; i++) {
			if (t - s < num[i]) {
				for (int j = t - s; j < num[i]; j++) {
					start[t++] = i;
				}
			} else if (t - s > num[i]) {
				while (t - s > num[i]) {
					res = min(res, i - start[s]);
					s++;
				}
			}
		}
		System.out.println(res);
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
