import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	static boolean SAMPLE;
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt();
		int N = n * 2 - 1;
		int[][] vs = new int[n * 2 - 1][n * 2 - 1];
		for (int i = 0; i < vs.length; i++) fill(vs[i], -1);
		for (int i = 0; i < n * 2 - 1; i++) {
			int d = min(i + 1, n * 2 - 1 - i);
			for (int j = 0; j < d; j++) {
				vs[i][n - d + j * 2] = sc.nextInt();
			}
		}
		int res = 1 << 29;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				boolean ok = true;
				int size = 0;
				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < N; j2++) if (vs[i2][j2] >= 0) {
						size = max(size, abs(i - i2) + abs(j - j2));
						int i3 = i * 2 - i2, j3 = j * 2 - j2;
						if (0 <= i3 && i3 < N && vs[i3][j2] >= 0 && vs[i2][j2] != vs[i3][j2]) {
							ok = false;
						}
						if (0 <= j3 && j3 < N && vs[i2][j3] >= 0 && vs[i2][j2] != vs[i2][j3]) {
							ok = false;
						}
					}
				}
				if (ok) res = min(res, (size + 1) * (size + 1) - n * n);
			}
		}
		System.out.println(res);
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (!SAMPLE) System.err.printf("%03d/%03d %.3f/%.3f%n", caseID, caseN, t, t / (caseID - 1) * caseN);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream(A.class.getName() + ".in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new A().run();
	}
}
