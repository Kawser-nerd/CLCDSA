import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
	
	PrintWriter out;
	
	long MOD = 1000000007;
	int R, C;
	
	void read(Scanner sc) {
		R = sc.nextInt();
		C = sc.nextInt();
	}
	
	int compare(int[][] a, int[][] b) {
		for (int j = 0; j < C; j++) {
			for (int i = 0; i < R; i++) if (a[i][j] != b[i][j]) return a[i][j] - b[i][j];
		}
		return 0;
	}
	
	int[][] copy(int[][] a) {
		int[][] b = new int[a.length][];
		for (int i = 0; i < a.length; i++) b[i] = a[i].clone();
		return b;
	}
	
	long f(int[][] a, int[][] need, int[][] space, int i, int j) {
		if (j == C) return f(a, need, space, i + 1, 0);
		if (i == R) {
			for (int k = 1; k < C; k++) {
				int[][] b = new int[R][C];
				for (int i2 = 0; i2 < R; i2++) {
					for (int j2 = 0; j2 < C; j2++) {
						b[i2][(j2 + k) % C] = a[i2][j2];
					}
				}
				if (compare(a, b) > 0) return 0;
			}
			return 1;
		}
		long res = 0;
		for (int k = 1; k <= 4; k++) {
			int[][] a2 = copy(a), need2 = copy(need), space2 = copy(space);
			a2[i][j] = k;
			need2[i][j] = k;
			if (i > 0) {
				space2[i - 1][j]--;
				if (a[i - 1][j] == k) {
					need2[i - 1][j]--;
					need2[i][j]--;
				}
				if (need2[i - 1][j] > space2[i - 1][j] || need2[i - 1][j] < 0) continue;
			}
			space2[i][(j + C - 1) % C]--;
			if (a[i][(j + C - 1) % C] == k) {
				need2[i][(j + C - 1) % C]--;
				need2[i][j]--;
			}
			if (need2[i][(j + C - 1) % C] > space2[i][(j + C - 1) % C] || need2[i][(j + C - 1) % C] < 0) continue;
			space2[i][(j + 1) % C]--;
			if (a[i][(j + 1) % C] == k) {
				need2[i][(j + 1) % C]--;
				need2[i][j]--;
			}
			if (need2[i][(j + 1) % C] > space2[i][(j + 1) % C] || need2[i][(j + 1) % C] < 0) continue;
			if (i + 1 < R) {
				space2[i + 1][j]--;
			}
			if (need2[i][j] < 0 || need2[i][j] > space2[i][j]) continue;
			res += f(a2, need2, space2, i, j + 1);
		}
		return res;
	}
	
	void solve() {
		int[][] space = new int[R][C];
		for (int i = 1; i < R - 1; i++) fill(space[i], 4);
		fill(space[0], 3);
		fill(space[R - 1], 3);
		out.println(f(new int[R][C], new int[R][C], space, 0, 0) % MOD);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static int __ID = 0;
	public static boolean __ERROR = false;
	
	public static void main(String[] args) {
		int pN = 1;
		if (args.length == 0) {
			try {
				System.setIn(new BufferedInputStream(new FileInputStream(D.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final D[] solvers = new D[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new D();
			outs[i] = new StringWriter();
			solvers[i].out = new PrintWriter(outs[i]);
			solvers[i].out.printf("Case #%d: ", i + 1);
			solvers[i].read(sc);
		}
		Thread[] ts = new Thread[pN];
		for (int i = 0; i < pN; i++) {
			ts[i] = new Thread() {
				@Override
				public void run() {
					for (;;) {
						int id;
						synchronized (D.class) {
							if (__ID == caseN) return;
							id = __ID++;
						}
						try {
							solvers[id].solve();
						} catch (RuntimeException e) {
							__ERROR = true;
							System.err.printf("Error in case %d:%n", id + 1);
							e.printStackTrace();
						}
						solvers[id].out.flush();
						solvers[id] = null;
					}
				}
			};
			ts[i].start();
		}
		for (int i = 0; i < pN; i++) {
			try {
				ts[i].join();
			} catch (InterruptedException e) {
				i--;
				continue;
			}
		}
		for (int i = 0; i < caseN; i++) {
			out.print(outs[i].toString());
		}
		if (__ERROR) out.printf("%nError occured!!!%n");
	}
	
}
