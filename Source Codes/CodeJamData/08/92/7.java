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
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int w = sc.nextInt(), h = sc.nextInt();
			int x1 = sc.nextInt(), y1 = sc.nextInt();
			int x2 = sc.nextInt(), y2 = sc.nextInt();
			int x = sc.nextInt(), y = sc.nextInt();
			boolean[][] map = new boolean[w][h];
			Queue<Integer> qx = new LinkedList<Integer>();
			Queue<Integer> qy = new LinkedList<Integer>();
			map[x][y] = true;
			qx.offer(x);
			qy.offer(y);
			int res = 0;
			while (!qx.isEmpty()) {
				res++;
				x = qx.poll();
				y = qy.poll();
				int xx = x + x1, yy = y + y1;
				if (0 <= xx && xx < w && 0 <= yy && yy < h && !map[xx][yy]) {
					map[xx][yy] = true;
					qx.offer(xx);
					qy.offer(yy);
				}
				xx = x + x2;
				yy = y + y2;
				if (0 <= xx && xx < w && 0 <= yy && yy < h && !map[xx][yy]) {
					map[xx][yy] = true;
					qx.offer(xx);
					qy.offer(yy);
				}
			}
			System.out.println(res);
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
