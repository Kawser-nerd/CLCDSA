import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N;
	long[] xs, ys;
	
	void read() {
		N = sc.nextInt();
		xs = new long[N];
		ys = new long[N];
		for (int i = 0; i < N; i++) {
			xs[i] = sc.nextInt();
			ys[i] = sc.nextInt();
		}
	}
	
	void solve() {
		int[] is = new int[N];
		for (int i = 0; i < N; i++) is[i] = i;
		long max = 0;
		int[] res = null;
		do {
			long area = 0;
			for (int i = 0; i < N; i++) {
				int u = is[i], v = is[(i + 1) % N];
				area += xs[u] * ys[v] - ys[u] * xs[v];
			}
			if (max < area) {
				boolean ok = true;
				for (int i = 0; i < N; i++) {
					for (int j = i + 2; j < N; j++) if (i != 0 || j != N - 1) {
						int u = is[i], u2 = is[(i + 1) % N], v = is[j], v2 = is[(j + 1) % N];
						if (crsSS(new P(xs[u], ys[u]), new P(xs[u2], ys[u2]), new P(xs[v], ys[v]), new P(xs[v2], ys[v2]))) {
							ok = false;
						}
					}
				}
				if (ok) {
					max = area;
					res = is.clone();
				}
			}
		} while (nextPermutation(is));
		for (int i = 0; i < N; i++) {
			if (i > 0) System.out.print(" ");
			System.out.print(res[i]);
		}
		System.out.println();
	}
	
	boolean crsSS(P p1, P p2, P q1, P q2) {
		if (max(p1.x, p2.x) < min(q1.x, q2.x) || max(q1.x, q2.x) < min(p1.x, p2.x)) return false;
		if (max(p1.y, p2.y) < min(q1.y, q2.y) || max(q1.y, q2.y) < min(p1.y, p2.y)) return false;
		return sig(p2.sub(p1).det(q1.sub(p1))) * sig(p2.sub(p1).det(q2.sub(p1))) <= 0
			&& sig(q2.sub(q1).det(p1.sub(q1))) * sig(q2.sub(q1).det(p2.sub(q1))) <= 0;
	}
	
	long sig(long a) {
		return Long.signum(a);
	}
	
	class P {
		long x, y;
		P(long x, long y) {
			this.x = x;
			this.y = y;
		}
		P add(P p) {
			return new P(x + p.x, y + p.y);
		}
		P sub(P p) {
			return new P(x - p.x, y - p.y);
		}
		long dot(P p) {
			return x * p.x + y * p.y;
		}
		long det(P p) {
			return x * p.y - y * p.x;
		}
		public String toString() {
			return String.format("(%d, %d)", x, y);
		}
	}
	
	boolean nextPermutation(int[] is) {
		int n = is.length;
		for (int i = n - 1; i > 0; i--) {
			if (is[i - 1] < is[i]) {
				int j = n;
				while (is[i - 1] >= is[--j]);
				swap(is, i - 1, j);
				rev(is, i, n);
				return true;
			}
		}
		rev(is, 0, n);
		return false;
	}
	void swap(int[] is, int i, int j) {
		int t = is[i]; is[i] = is[j]; is[j] = t;
	}
	void rev(int[] is, int s, int t) {
		while (s < --t) swap(is, s++, t);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
