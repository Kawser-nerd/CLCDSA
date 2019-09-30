import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		loop : for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt(), a = sc.nextInt();
			for (int x1 = 0; x1 <= n; x1++) {
				for (int y1 = 0; y1 <= m; y1++) {
					for (int x2 = 0; x2 <= n; x2++) {
						for (int y2 = 0; y2 <= m; y2++) {
							if (x1 * y2 - y1 * x2 == a) {
								System.out.printf("%d %d %d %d %d %d%n", 0, 0, x1, y1, x2, y2);
								continue loop;
							}
						}
					}
				}
			}
			System.out.println("IMPOSSIBLE");
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
