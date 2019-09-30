import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	
	PrintWriter out;
	
	int R, C;
	char[][] cs;
	
	void read(Scanner sc) {
		R = sc.nextInt();
		C = sc.nextInt();
		cs = new char[R][];
		for (int i = 0; i < R; i++) cs[i] = sc.next().toCharArray();
	}
	
	boolean in(int i, int l, int r) {
		return l <= i && i <= r;
	}
	
	char[] D = {'^', '<', 'v', '>'};
	int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	
	void solve() {
		boolean[][][] dame = new boolean[R][C][4];
		for (int d = 0; d < 4; d++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if ((i == 0 || i == R - 1 || j == 0 || j == C - 1) && (!in(i - dx[d], 0, R - 1) || !in(j - dy[d], 0, C - 1))) {
						int x = i, y = j;
						while (in(x, 0, R - 1) && in(y, 0, C - 1)) {
							if (cs[x][y] != '.') {
								dame[x][y][d] = true;
								break;
							}
							x += dx[d];
							y += dy[d];
						}
					}
				}
			}
		}
		int res = 0;
		boolean impossible = false;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) if (cs[i][j] != '.') {
				boolean ok = true, can = false;
				for (int k = 0; k < 4; k++) {
					if (cs[i][j] == D[k] && dame[i][j][k]) ok = false;
					if (!dame[i][j][k]) can = true;
				}
				if (!ok) res++;
				if (!can) impossible = true;
			}
		}
		if (impossible) out.println("IMPOSSIBLE");
		else out.println(res);
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
				System.setIn(new BufferedInputStream(new FileInputStream(A.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final A[] solvers = new A[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new A();
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
						synchronized (A.class) {
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
