import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[] xs;
	
	void read() {
		N = sc.nextInt();
		xs = new int[N - 1];
		for (int i = 0; i < N - 1; i++) xs[i] = sc.nextInt() - 1;
	}
	
	int H = 500000000;
	int[] ys;
	
	long det(long x1, long y1, long x2, long y2) {
		return x1 * y2 - y1 * x2;
	}
	
	boolean set(int s, int t) {
		if (s == t) return true;
		if (xs[s] > t) return false;
		int mid = xs[s];
		for (int i = mid + 1; i < t; i++) ys[i] = ys[mid];
		if (!set(mid, t)) return false;
		while (det(mid - s, ys[mid] - ys[s], t - mid, ys[t] - ys[mid]) > 0) ys[s]--;
		for (int i = s + 1; i < mid; i++) ys[i] = ys[s] - 1;
		if (!set(s + 1, mid)) return false;
		return true;
	}
	
	void solve() {
		ys = new int[N];
		fill(ys, H);
		if (!set(0, N - 1)) System.out.println("Impossible");
		else {
			for (int i = 0; i < N; i++) {
				if (i > 0) System.out.print(" ");
				System.out.print(ys[i]);
			}
			System.out.println();
		}
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
