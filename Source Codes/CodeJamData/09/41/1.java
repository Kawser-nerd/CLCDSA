import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt();
		char[][] cs = new char[n][];
		for (int i = 0; i < n; i++) cs[i] = sc.next().toCharArray();
		int[] to = new int[n];
		for (int i = 0; i < n; i++) to[i] = f(cs[i]);
		int[] id = new int[n];
		fill(id, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if (to[j] <= i && id[j] < 0) {
				id[j] = i;
				break;
			}
		}
		System.out.println(need(id));
	}
	
	int f(char[] cs) {
		for (int i = cs.length - 1; i >= 0; i--) if (cs[i] == '1') return i;
		return 0;
	}
	
	int need(int[] is) {
		int n = is.length;
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j + 1 < n; j++) if (is[j] > is[j + 1]) {
				swap(is, j, j + 1);
				num++;
			}
		}
		return num;
	}
	
	void swap(int[] is, int i, int j) {
		int t = is[i]; is[i] = is[j]; is[j] = t;
	}
	
	void run() {
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
