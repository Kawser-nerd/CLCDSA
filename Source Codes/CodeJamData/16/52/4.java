import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	
	public static int PARALLEL = 10;
	public static int ID = 0;
	
	int id;
	PrintWriter out;
	
	int REP = 100000;
	
	int N, M;
	int[] ps;
	char[] cs;
	char[][] cool;
	
	int[][] childs;
	
	Random rand = new Random();
	
	void read(Scanner sc) {
		N = sc.nextInt();
		ps = new int[N + 1];
		ps[0] = -1;
		for (int i = 0; i < N; i++) ps[1 + i] = sc.nextInt();
		N++;
		cs = ("." + sc.next()).toCharArray();
		M = sc.nextInt();
		cool = new char[M][];
		for (int i = 0; i < M; i++) cool[i] = sc.next().toCharArray();
	}
	
	static double[][] comb;
	static {
		int n = 200;
		comb = new double[n + 1][n + 1];
		comb[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			comb[i][0] = 1;
			for (int j = 1; j <= n; j++) {
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
			}
		}
	}
	
	int[] size;
	
	int size(int i) {
		if (size[i] > 0) return size[i];
		size[i] = 1;
		for (int c : childs[i]) {
			size[i] += size(c);
		}
		return size[i];
	}
	
	double f(char[] cool) {
		int count = 0;
		KMP kmp = new KMP(cool);
		boolean[] used = new boolean[N];
		char[] ws = new char[N];
		for (int rep = 0; rep < REP; rep++) {
			fill(used, false);
			for (int i = 0; i < N; i++) {
				double p = (N - i) * rand.nextDouble();
				for (int j = 0; j < N; j++) if (!used[j] && (ps[j] < 0 || used[ps[j]])) {
					p -= size[j];
					if (p <= 0) {
						ws[i] = cs[j];
						used[j] = true;
						break;
					}
				}
			}
			if (kmp.searchFrom(ws) > 0) count++;
		}
		return (double)count / REP;
	}
	
	void solve() {
		childs = new int[N][N];
		int[] deg = new int[N];
		for (int i = 0; i < N; i++) if (ps[i] >= 0) {
			childs[ps[i]][deg[ps[i]]++] = i;
		}
		for (int i = 0; i < N; i++) childs[i] = copyOf(childs[i], deg[i]);
		size = new int[N];
		size(0);
		for (int i = 0; i < M; i++) {
			if (i > 0) out.print(" ");
			out.printf("%.10f", f(cool[i]));
		}
		out.println();
	}
	
	class KMP {
		int m;
		char[] p;
		int[] fail;
		KMP(char[] p) {
			m = p.length;
			this.p = p;
			fail = new int[m + 1];
			int crt = fail[0] = -1;
			for (int i = 1; i <= m; i++) {
				while (crt >= 0 && p[crt] != p[i - 1]) crt = fail[crt];
				fail[i] = ++crt;
			}
		}
		int searchFrom(char[] t) {
			int n = t.length, count = 0;
			for (int i = 0, j = 0; i < n; i++) {
				while (j >= 0 && t[i] != p[j]) j = fail[j];
				if (++j == m) {
					count++;
					j = fail[j];
				}
			}
			return count;
		}
	}
	
	void debug(Object...os) {
		System.err.printf("#%d: %s%n", id, deepToString(os));
	}
	
	public static void main(String[] args) {
		System.setOut(null);
		String input;
		if (args.length == 0) {
			input = B.class.getName() + ".in";
			PARALLEL = 1;
		} else {
			input = args[0];
			if (args.length >= 2) ID = Integer.parseInt(args[1]);
		}
		System.err.printf("Input = %s%n", input);
		final B[] solvers;
		final StringWriter[] outs;
		try (Scanner sc = new Scanner(new BufferedInputStream(new FileInputStream(input)))) {
			int caseN = sc.nextInt();
			solvers = new B[caseN];
			outs = new StringWriter[caseN];
			for (int i = 0; i < caseN; i++) {
				solvers[i] = new B();
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
						synchronized (B.class) {
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
