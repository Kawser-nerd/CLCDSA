import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class D {
	char[] cs;
	int n;
	public static void main(String[] args) {
		new D().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			n = sc.nextInt();
			cs = sc.next().toCharArray();
			System.out.println(permRec(new int[n], new boolean[n], 0));
		}
	}
	int permRec(int[] a, boolean[] used, int p) {
		if (p == a.length) {
			char last = 0;
			int res = 0;
			for (int i = 0; i < cs.length; i += n) {
				for (int j = 0; j < n; j++) {
					char c = cs[i + a[j]];
					if (c != last) {
						res++;
						last = c;
					}
				}
			}
			return res;
		} else {
			int res = Integer.MAX_VALUE;
			for (a[p] = 0; a[p] < used.length; a[p]++) if (!used[a[p]]) {
				used[a[p]] = true;
				res = min(res, permRec(a, used, p + 1));
				used[a[p]] = false;
			}
			return res;
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
