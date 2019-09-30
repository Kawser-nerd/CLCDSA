import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	boolean TIME = false;
	Scanner sc;
	
	int N, K;
	
	void solve() {
		N = sc.nextInt();
		K = sc.nextInt();
		char[][] cs = new char[N][];
		for (int i = 0; i < N; i++) cs[i] = sc.next().toCharArray();
		cs = rotate(cs);
		boolean winR = win(cs, 'R');
		boolean winB = win(cs, 'B');
		if (winR && winB) {
			System.out.println("Both");
		} else if (winR) {
			System.out.println("Red");
		} else if (winB) {
			System.out.println("Blue");
		} else {
			System.out.println("Neither");
		}
	}
	
	boolean win(char[][] cs, char c) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (cs[i][j] == c) {
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) if (di != 0 || dj != 0) {
						int M = 1;
						for (;;M++) {
							int i2 = i + M * di, j2 = j + M * dj;
							if (!(0 <= i2 && i2 < N && 0 <= j2 && j2 < N && cs[i2][j2] == c)) {
								break;
							}
						}
						if (M >= K) return true;
					}
				}
			}
		}
		return false;
	}
	
	char[][] rotate(char[][] cs) {
		char[][] ds = new char[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ds[i][j] = cs[N - j - 1][i];
			}
		}
		for (int j = 0; j < N; j++) {
			int K = N - 1;
			for (int i = N - 1; i >= 0; i--) {
				if (ds[i][j] != '.') ds[K--][j] = ds[i][j];
			}
			while (K >= 0) {
				ds[K--][j] = '.';
			}
		}
		return ds;
	}
	
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
		new A().run();
	}
}
