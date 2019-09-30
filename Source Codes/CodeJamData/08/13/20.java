import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	int rep = 1000;
	void run() {
		BigDecimal r5 = root(BigDecimal.valueOf(5));
		BigDecimal d = BigDecimal.valueOf(3).add(r5);
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			System.out.println(f(d.pow(n).toPlainString()));
		}
	}
	String f(String s) {
		s = s.split("\\.")[0];
		if (s.length() > 3) s = s.substring(s.length() - 3);
		while (s.length() < 3) s = "0" + s;
		return s;
	}
	BigDecimal root(BigDecimal d) {
		BigDecimal left = BigDecimal.ZERO, right = d;
		BigDecimal two = BigDecimal.valueOf(2);
		for (int i = 0; i < rep; i++) {
			BigDecimal mid = left.add(right).divide(two);
			if (mid.multiply(mid).compareTo(d) > 0) right = mid;
			else left = mid;
		}
		return left;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
