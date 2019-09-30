import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	boolean TIME = false;
	Scanner sc;
	
	void solve() {
		int A1 = sc.nextInt(), A2 = sc.nextInt();
		int B1 = sc.nextInt(), B2 = sc.nextInt();
		long res = 0;
		for (int b = B1; b <= B2; b++) {
			int min = (int)(ceil(1.0 / R * b));
			int max = (int)(floor(R * b));
			min = max(min, A1);
			max = min(max, A2);
			res += A2 - A1 + 1;
			if (min <= max) {
				res -= max - min + 1;
			}
		}
		System.out.println(res);
	}
	
	double R = (sqrt(5) + 1) / 2;
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
