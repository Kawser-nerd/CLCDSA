import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	
	PrintWriter out;
	
	int N, D;
	long S0, As, Cs, Rs;
	long M0, Am, Cm, Rm;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		D = sc.nextInt();
		S0 = sc.nextLong();
		As = sc.nextLong();
		Cs = sc.nextLong();
		Rs = sc.nextLong();
		M0 = sc.nextLong();
		Am = sc.nextLong();
		Cm = sc.nextLong();
		Rm = sc.nextLong();
	}
	
	int[] S;
	int[] M;
	
	void gen() {
		S = new int[N];
		M = new int[N];
		S[0] = (int)S0;
		M[0] = (int)M0;
		for (int i = 1; i < N; i++) {
			S[i] = (int)((S[i - 1] * As + Cs) % Rs);
			M[i] = (int)((M[i - 1] * Am + Cm) % Rm);
		}
		M[0] = 0;
		for (int i = 1; i < N; i++) M[i] %= i;
	}
	
	void solve() {
		gen();
		int[] min = new int[N], max = new int[N];
		min[0] = max[0] = S[0];
		for (int i = 1; i < N; i++) {
			min[i] = max[i] = S[i];
			min[i] = min(min[i], min[M[i]]);
			max[i] = max(max[i], max[M[i]]);
		}
		int[] sum = new int[1000010];
		for (int i = 0; i < N; i++) if (min[i] + D >= max[i]) {
			sum[max(0, max[i] - D)]++;
			sum[min[i] + 1]--;
		}
		for (int i = 0; i < sum.length - 1; i++) {
			sum[i + 1] += sum[i];
		}
		int res = 0;
		for (int i = 0; i < sum.length; i++) res = max(res, sum[i]);
		out.println(res);
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
