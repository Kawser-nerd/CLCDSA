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
	int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			System.out.println();
			int n = sc.nextInt();
			int[] xs = new int[n], ys = new int[n], ts = new int[n];
			int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
			for (int i = 0; i < n; i++) {
				xs[i] = sc.nextInt();
				ys[i] = sc.nextInt();
				ts[i] = sc.next().charAt(0) == 'B' ? 0 : 1;
				if (ts[i] == 0) {
					minx = min(minx, xs[i]);
					maxx = max(maxx, xs[i]);
					miny = min(miny, ys[i]);
					maxy = max(maxy, ys[i]);
				} else {
					sc.next();
				}
			}
			int m = sc.nextInt();
			while (m-- > 0) {
				int x = sc.nextInt(), y = sc.nextInt();
				if (minx <= x && x <= maxx && miny <= y && y <= maxy) {
					System.out.println("BIRD");
				} else if (minx == INF) {
					boolean b = false;
					for (int i = 0; i < n; i++) if (ts[i] == 1) {
						if (xs[i] == x && ys[i] == y) b = true;
					}
					if (b) System.out.println("NOT BIRD");
					else System.out.println("UNKNOWN");
				} else {
					int lx = min(minx, x), rx = max(maxx, x), ly = min(miny, y), ry = max(maxy, y);
					boolean b = false;
					for (int i = 0; i < n; i++) if (ts[i] == 1) {
						if (lx <= xs[i] && xs[i] <= rx && ly <= ys[i] && ys[i] <= ry) b = true;
					}
					if (b) System.out.println("NOT BIRD");
					else System.out.println("UNKNOWN");
				}
			}
		}
	}
	int[] toi(Integer[] Is) {
		int n = Is.length;
		int[] is = new int[n];
		for (int i = 0; i < n; i++) is[i] = Is[i];
		return is;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
