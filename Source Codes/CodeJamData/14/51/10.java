import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	
	PrintWriter out;
	
	int N;
	long p, q, r, s;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		p = sc.nextInt();
		q = sc.nextInt();
		r = sc.nextInt();
		s = sc.nextInt();
	}
	
	long[] num;
	
	boolean can(long max) {
		int p = 0;
		for (int i = 0; i < 3; i++) {
			long sum = 0;
			while (p < N && sum + num[p] <= max) {
				sum += num[p++];
			}
			if (p >= N) return true;
		}
		return false;
	}
	
	void solve() {
		num = new long[N];
		long sum = 0;
		for (int i = 0; i < N; i++) {
			num[i] = (i * p + q) % r + s;
			sum += num[i];
		}
		long lb = 0, ub = 1L << 60;
		while (lb + 1 < ub) {
			long mid = (lb + ub) / 2;
			if (can(mid)) {
				ub = mid;
			} else {
				lb = mid;
			}
		}
		out.printf("%.10f%n", (double)(sum - ub) / sum);
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
