import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	boolean TIME = true;
	Scanner sc;
	
	int M = 10009;
	
	void solve() {
		String[] ss = sc.next().split("\\+");
		int m = ss.length;
		css = new char[m][];
		for (int i = 0; i < m; i++) css[i] = ss[i].toCharArray();
		int k = sc.nextInt();
		n = sc.nextInt();
		is = new int[n][26];
		for (int i = 0; i < n; i++) {
			for (char c : sc.next().toCharArray()) is[i][c - 'a']++;
		}
		for (int i = 1; i <= k; i++) {
			if (i > 1) System.out.print(" ");
			System.out.print(rec(new int[26], i));
		}
		System.out.println();
	}
	
	char[][] css;
	int[][] is;
	int n;
	
	int rec(int[] js, int i) {
		if (i == 0) {
			int res = 0;
			for (char[] cs : css) {
				int tmp = 1;
				for (char c : cs) {
					tmp = tmp * js[c - 'a'] % M;
				}
				res = (res + tmp) % M;
			}
			return res;
		}
		int res = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 26; k++) {
				js[k] += is[j][k];
			}
			res = (res + rec(js, i - 1)) % M;
			for (int k = 0; k < 26; k++) {
				js[k] -= is[j][k];
			}
		}
		return res;
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
