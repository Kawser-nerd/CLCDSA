import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N, D;
	int[] ps;
	
	void read() {
		int C = sc.nextInt();
		D = sc.nextInt();
		N = 0;
		int[] P = new int[C];
		int[] V = new int[C];
		for (int i = 0; i < C; i++) {
			P[i] = sc.nextInt();
			V[i] = sc.nextInt();
			N += V[i];
		}
		ps = new int[N];
		N = 0;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < V[i]; j++) {
				ps[N++] = P[i];
			}
		}
		sort(ps);
	}
	
	void solve() {
		double lb = 0, ub = 1e16;
		for (int rep = 0; rep < 100; rep++) {
			double mid = (lb + ub) / 2;
			double p = Double.NEGATIVE_INFINITY;
			boolean ok = true;
			for (int i = 0; i < N; i++) {
				if (p + D > ps[i] + mid) {
					ok = false;
					break;
				} else if (p + D < ps[i] - mid) {
					p = ps[i] - mid;
				} else {
					p += D;
				}
			}
			if (ok) ub = mid;
			else lb = mid;
		}
		System.out.printf("%.10f%n", ub);
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
