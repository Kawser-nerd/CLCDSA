import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
	
	PrintWriter out;
	
	int P;
	long[] E, F;
	
	void read(Scanner sc) {
		P = sc.nextInt();
		E = new long[P];
		F = new long[P];
		for (int i = 0; i < P; i++) E[i] = sc.nextLong();
		for (int i = 0; i < P; i++) F[i] = sc.nextLong();
	}
	
	void solve() {
		long sum = 0;
		for (int i = 0; i < P; i++) sum += F[i];
		int N = 0;
		while (1L << N < sum) N++;
		long[] res = new long[N];
		TreeMap<Long, Integer> ids = new TreeMap<Long, Integer>();
		for (int i = 0; i < P; i++) ids.put(E[i], i);
		loop : for (int i = 0; i < N; i++) {
			for (int j = 0; j < P; j++) if (F[j] > 0) {
				if (E[j] < 0) {
					long[] F2 = F.clone();
					long[] F3 = new long[P];
					boolean ok = true;
					for (int k = 0; k < P; k++) if (F2[k] > 0) {
						if (ids.containsKey(E[k] - E[j])) {
							int p = ids.get(E[k] - E[j]);
							F2[p] -= F2[k];
							F3[p] += F2[k];
							if (F2[p] < 0) {
								ok = false;
								break;
							}
							F2[k] = 0;
						} else {
							ok = false;
							break;
						}
					}
					if (ok) {
						F = F3;
						res[i] = E[j];
						continue loop;
					}
				} else if (E[j] > 0) {
					long[] F2 = F.clone();
					long[] F3 = new long[P];
					boolean ok = true;
					for (int k = P - 1; k >= 0; k--) if (F2[k] > 0) {
						if (ids.containsKey(E[k] - E[j])) {
							int p = ids.get(E[k] - E[j]);
							F2[p] -= F2[k];
							F3[p] += F2[k];
							if (F2[p] < 0) {
								ok = false;
								break;
							}
							F2[k] = 0;
						} else {
							ok = false;
							break;
						}
					}
					if (ok) {
						F = F3;
						res[i] = E[j];
						continue loop;
					}
				} else {
					boolean ok = true;
					for (int k = 0; k < P; k++) if (F[k] % 2 != 0) ok = false;
					if (ok) {
						for (int k = 0; k < P; k++) F[k] /= 2;
						res[i] = 0;
						continue loop;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			out.print(res[i]);
			if (i < N - 1) out.print(" ");
		}
		out.println();
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
