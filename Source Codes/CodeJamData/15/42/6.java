import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	
	PrintWriter out;
	
	int N;
	double V, X;
	Entry[] es;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		V = sc.nextDouble();
		X = sc.nextDouble();
		es = new Entry[N];
		for (int i = 0; i < N; i++) {
			es[i] = new Entry(sc.nextDouble(), sc.nextDouble());
		}
		sort(es);
	}
	
	class Entry implements Comparable<Entry> {
		double v, x;
		Entry(double v, double x) {
			this.v = v;
			this.x = x;
		}
		@Override
		public int compareTo(Entry o) {
			return Double.compare(x, o.x);
		}
	}
	
	boolean can(double t) {
		double v = 0;
		for (int i = 0; i < N; i++) v += es[i].v * t;
		if (v < V) return false;
		double min = 0;
		v = 0;
		for (int i = 0; i < N && v < V; i++) {
			min += min(V - v, es[i].v * t) * es[i].x;
			v += es[i].v * t;
		}
		v = 0;
		double max = 0;
		for (int i = N - 1; i >= 0 && v < V; i--) {
			max += min(V - v, es[i].v * t) * es[i].x;
			v += es[i].v * t;
		}
		return (min <= V * X * (1 + 1e-13) && V * X * (1 - 1e-13) <= max);
	}
	
	void solve() {
		double lb = 0, ub = 1e30;
		for (int i = 0; i < 1000; i++) {
			double mid = (lb + ub) / 2;
			if (can(mid)) ub = mid;
			else lb = mid;
		}
		if (ub > 1e29) out.println("IMPOSSIBLE");
		else out.printf("%.10f%n", ub);
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
