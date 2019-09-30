import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int t = 1; t <= n; t++) {
			int m = sc.nextInt();
			sc.nextLine();
			String[] ss = new String[m];
			for (int i = 0; i < m; i++) ss[i] = sc.nextLine();
			int q = sc.nextInt();
			sc.nextLine();
			String[] ts = new String[q];
			for (int i = 0; i < q; i++) ts[i] = sc.nextLine();
			int[] dp = new int[m];
			for (String s : ts) {
				int min = minAll(dp);
				for (int i = 0; i < m; i++) {
					if (ss[i].equals(s)) dp[i] = INF;
					else dp[i] = min(dp[i], min + 1);
				}
			}
			System.out.printf("Case #%d: %d%n", t, minAll(dp));
		}
	}
	int minAll(int...is) {
		int res = is[0];
		for (int i = 1; i < is.length; i++) {
			if (res > is[i]) res = is[i];
		}
		return res;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
