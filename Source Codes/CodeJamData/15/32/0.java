import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	
	PrintWriter out;
	
	int K, L, S;
	char[] keys;
	char[] target;
	
	void read(Scanner sc) {
		K = sc.nextInt();
		L = sc.nextInt();
		S = sc.nextInt();
		keys = sc.next().toCharArray();
		target = sc.next().toCharArray();
	}
	
	void solve() {
		int[][] to = new int[L + 1][K];
		for (int i = 0; i <= L; i++) {
			for (int j = 0; j < K; j++) {
				String s = new String(target, 0, i) + keys[j];
				while (s.length() > 0) {
					if (new String(target).startsWith(s)) break;
					s = s.substring(1);
				}
				to[i][j] = s.length();
			}
		}
		double[] crt = new double[L + 1];
		for (int i = 0; i < S; i++) {
			double[] next = new double[L + 1];
			for (int j = 0; j <= L; j++) {
				for (int k = 0; k < K; k++) {
					next[j] += (crt[to[j][k]] + (to[j][k] == L ? 1 : 0)) / K;
				}
			}
			crt = next;
		}
		double exp = crt[0];
		int max = 0;
		boolean ok = true;
		for (int i = 0; i < L; i++) if (new String(keys).indexOf(target[i]) < 0) ok = false;
		if (ok) {
			int rep = 0;
			for (int i = 0; i < K; i++) rep = max(rep, to[L][i]);
			max = 1 + (S - L) / (L - rep + 1);
		}
		out.printf("%.8f%n", max(0, max - exp));
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
				System.setIn(new BufferedInputStream(new FileInputStream(B.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final B[] solvers = new B[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new B();
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
						synchronized (B.class) {
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
