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
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			long[] xs = new long[n], ys = new long[n];
			for (int i = 0; i < n; i++) xs[i] = sc.nextLong();
			for (int i = 0; i < n; i++) ys[i] = sc.nextLong();
			sort(xs);
			sort(ys);
			long res = 0;
			for (int i = 0; i < n; i++) res += xs[i] * ys[n - i - 1];
			System.out.println(res);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
