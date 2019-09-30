import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	
	PrintWriter out;
	
	int N;
	char[] EL;
	int[] id;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		EL = new char[N];
		id = new int[N];
		for (int i = 0; i < N; i++) {
			EL[i] = sc.next().charAt(0);
			id[i] = sc.nextInt();
		}
	}
	
	int INF = 1 << 29;
	
	void solve() {
		TreeMap<Integer, Integer> map = new TreeMap<>();
		int ID = 0;
		for (int i = 0; i < N; i++) if (id[i] > 0) {
			if (!map.containsKey(id[i])) map.put(id[i], ID++);
		}
		int[] crt = new int[1 << N];
		for (int i = 0; i < 1 << N; i++) crt[i] = Integer.bitCount(i);
		for (int i = 0; i < N; i++) {
			int[] next = new int[1 << N];
			fill(next, INF);
			if (EL[i] == 'E') {
				for (int j = 0; j < 1 << N; j++) if (crt[j] < INF) {
					int s = 0, t = N - 1;
					if (id[i] > 0) s = t = map.get(id[i]);
					for (int k = s; k <= t; k++) if ((j >> k & 1) == 0) {
						next[j | 1 << k] = min(next[j | 1 << k], crt[j] + 1);
					}
				}
			} else {
				for (int j = 0; j < 1 << N; j++) if (crt[j] < INF) {
					int s = 0, t = N - 1;
					if (id[i] > 0) s = t = map.get(id[i]);
					for (int k = s; k <= t; k++) if ((j >> k & 1) != 0) {
						next[j & ~(1 << k)] = min(next[j & ~(1 << k)], crt[j] - 1);
					}
				}
			}
			crt = next;
		}
		int res = INF;
		for (int i = 0; i < crt.length; i++) res = min(res, crt[i]);
		if (res >= INF) out.println("CRIME TIME");
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
				System.setIn(new BufferedInputStream(new FileInputStream(C.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final C[] solvers = new C[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new C();
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
						synchronized (C.class) {
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
