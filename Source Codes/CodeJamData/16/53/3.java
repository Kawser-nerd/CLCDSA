import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	
	public static int PARALLEL = 10;
	public static int ID = 0;
	
	int id;
	PrintWriter out;
	
	double INF = 1e10;
	
	int N;
	double S;
	double[] xs, ys, zs;
	double[] vxs, vys, vzs;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		S = sc.nextDouble();
		xs = new double[N];
		ys = new double[N];
		zs = new double[N];
		vxs = new double[N];
		vys = new double[N];
		vzs = new double[N];
		for (int i = 0; i < N; i++) {
			xs[i] = sc.nextDouble();
			ys[i] = sc.nextDouble();
			zs[i] = sc.nextDouble();
			vxs[i] = sc.nextDouble();
			vys[i] = sc.nextDouble();
			vzs[i] = sc.nextDouble();
		}
	}
	
	boolean ok(double s1, double t1, double s2, double t2) {
		return max(s1, s2) <= min(t1, t2);
	}
	
	void solve() {
		double[][] from = new double[N][N];
		double[][] to = new double[N][N];
		double[][] min = new double[N][N];
		double[] checked = new double[N];
		double left = 0, right = 1e10;
		for (int rr = 0; rr < 200; rr++) {
			double mid = (left + right) / 2;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < i; j++) {
					double x = xs[i] - xs[j], y = ys[i] - ys[j], z = zs[i] - zs[j];
					double vx = vxs[i] - vxs[j], vy = vys[i] - vys[j], vz = vzs[i] - vzs[j];
					double a = vx * vx + vy * vy + vz * vz;
					double b = 2 * x * vx + 2 * y * vy + 2 * z * vz;
					double c = x * x + y * y + z * z - mid;
					double L = -1, R = -1;
					double C = b * b - 4 * a * c;
					if (a == 0) {
						if (c <= 0) {
							L = 0;
							R = INF;
						}
					} else if (C >= 0) {
						L = (-b - sqrt(C)) / (2 * a);
						R = (-b + sqrt(C)) / (2 * a);
					}
					from[i][j] = from[j][i] = L;
					to[i][j] = to[j][i] = R;
				}
			}
			fill(checked, -1);
			PriorityQueue<Entry> que = new PriorityQueue<C.Entry>();
			for (int i = 0; i < N; i++) fill(min[i], INF);
			for (int i = 1; i < N; i++) {
				if (ok(0, S, from[0][i], to[0][i])) {
					min[0][i] = min[i][0] = max(0, from[0][i]);
					que.offer(new Entry(0, i, min[0][i]));
				}
			}
			boolean ok = false;
			loop : while (!que.isEmpty()) {
				Entry e = que.poll();
				int i = e.i, j = e.j;
				if (min[i][j] != e.t) continue;
				if (i == 1 || j == 1) {
					ok = true;
					break loop;
				}
				for (int rep = 0; rep < 2; rep++) {
//					if (checked[i] >= to[i][j] + S) continue;
					checked[i] = to[i][j] + S;
					for (int k = 0; k < N; k++) if (k != i && ok(min[i][j], to[i][j] + S, from[i][k], to[i][k])) {
						double t = max(min[i][j], from[i][k]);
						if (min[i][k] > t) {
							min[i][k] = min[k][i] = t;
							if (i == 1 || k == 1) {
								ok = true;
								break loop;
							}
							que.offer(new Entry(i, k, t));
						}
					}
					int tmp = i; i = j; j = tmp;
				}
			}
			if (ok) right = mid;
			else left = mid;
		}
		out.printf("%.10f%n", sqrt(right));
	}
	
	class Entry implements Comparable<Entry> {
		int i, j;
		double t;
		Entry(int i, int j, double t) {
			this.i = i;
			this.j = j;
			this.t = t;
		}
		@Override
		public int compareTo(Entry o) {
			if (t < o.t) return -1;
			if (t > o.t) return 1;
			return 0;
		}
	}
	
	void debug(Object...os) {
		System.err.printf("#%d: %s%n", id, deepToString(os));
	}
	
	public static void main(String[] args) {
		System.setOut(null);
		String input;
		if (args.length == 0) {
			input = C.class.getName() + ".in";
			PARALLEL = 1;
		} else {
			input = args[0];
			if (args.length >= 2) ID = Integer.parseInt(args[1]);
		}
		System.err.printf("Input = %s%n", input);
		final C[] solvers;
		final StringWriter[] outs;
		try (Scanner sc = new Scanner(new BufferedInputStream(new FileInputStream(input)))) {
			int caseN = sc.nextInt();
			solvers = new C[caseN];
			outs = new StringWriter[caseN];
			for (int i = 0; i < caseN; i++) {
				solvers[i] = new C();
				solvers[i].id = i + 1;
				solvers[i].out = new PrintWriter(outs[i] = new StringWriter());
				solvers[i].out.printf("Case #%d: ", i + 1);
				solvers[i].read(sc);
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		if (ID >= 1) {
			int id = ID - 1;
			solvers[id].solve();
			System.err.flush();
			System.err.print(outs[id].toString());
			return;
		}
		Thread[] ts = new Thread[PARALLEL];
		for (int i = 0; i < PARALLEL; i++) {
			ts[i] = new Thread(new Runnable() {
				@Override
				public void run() {
					for (;;) {
						int id;
						synchronized (C.class) {
							if (ID == solvers.length) return;
							id = ID++;
							System.err.printf("Solve: %d / %d%n", id + 1, solvers.length);
						}
						try {
							solvers[id].solve();
						} catch (RuntimeException e) {
							System.err.printf("Error occurred in case %d:%n", id + 1);
							e.printStackTrace();
							System.exit(1);
						}
						solvers[id].out.flush();
						solvers[id] = null;
					}
				}
			});
			ts[i].start();
		}
		for (int i = 0; i < PARALLEL; i++) {
			try {
				ts[i].join();
			} catch (InterruptedException e) {
				i--;
				continue;
			}
		}
		PrintWriter out;
		String file = null;
		if (args.length > 0) {
			file = args[0].substring(0, args[0].lastIndexOf('.')) + ".out";
			try {
				out = new PrintWriter(new File(file));
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		} else {
			System.err.println("========== output ==========");
			System.err.flush();
			out = new PrintWriter(System.err);
		}
		for (int i = 0; i < solvers.length; i++) {
			out.print(outs[i].toString());
		}
		out.flush();
		if (file != null) {
			System.err.println("Output = " + file);
		}
	}
	
}
