import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	int N = 1000000;
	int M = 9;
	void run() {
		ok = new int[11][N];
		for (int[] a : ok) {
			fill(a, -1);
			a[1] = 1;
		}
		int[] res = new int[1 << M];
		for (int a = 0; a < 1 << M; a++) {
			int i = max(2, res[a - (a & -a)]);
			loop : for (;;i++) {
				for (int j = 0; j < M; j++) if ((a >> j & 1) != 0 && ok(i, j + 2) == 0) continue loop;
				break;
			}
			res[a] = i;
		}
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		sc.nextLine();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			String[] ss = sc.nextLine().split(" ");
			int i = 0;
			for (String s : ss) i |= 1 << (Integer.parseInt(s) - 2);
			System.out.println(res[i]);
		}
	}
	int[][] ok;
	int ok(int a, int d) {
		if (a < N) {
			if (ok[d][a] >= 0) return ok[d][a];
			if (ok[d][a] == -2) return ok[d][a] = 0;
			ok[d][a] = -2;
			return ok[d][a] = ok(f(a, d), d);
		} else return ok(f(a, d), d);
	}
	int f(int a, int d) {
		int r = 0;
		for (char c : Integer.toString(a, d).toCharArray()) {
			r += (c - '0') * (c - '0');
		}
		return r;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
