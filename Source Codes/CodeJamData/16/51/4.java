import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	
	public static int PARALLEL = 10;
	public static int ID = 0;
	
	int id;
	PrintWriter out;
	
	char[] cs;
	char[] CJ = {'C', 'J'};
	
	void read(Scanner sc) {
		cs = sc.next().toCharArray();
	}
	
	void solve() {
		int n = cs.length;
		int[][][] dp = new int[2][2][n + 1];
		for (int j = 0; j < 2; j++) fill(dp[0][j], -1);
		dp[0][0][0] = dp[0][1][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) fill(dp[(i + 1) & 1][j], -1);
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < n; k++) if (dp[i & 1][j][k] >= 0) {
					if (k > 0) {
						dp[(i + 1) & 1][1 - j][k - 1] = max(dp[(i + 1) & 1][1 - j][k - 1], dp[i & 1][j][k] + (CJ[j] == cs[i] ? 0 : -5));
					}
					dp[(i + 1) & 1][1 - j][k + 1] = max(dp[(i + 1) & 1][1 - j][k + 1], dp[i & 1][j][k] + (CJ[1 - j] == cs[i] ? 10 : 5));
				}
			}
			for (int j = 0; j < 2; j++) {
				dp[(i + 1) & 1][j][0] = max(dp[(i + 1) & 1][j][0], dp[(i + 1) & 1][1 - j][0]);
			}
		}
		out.println(max(dp[n & 1][0][0], dp[n & 1][1][0]));
	}
	
	void debug(Object...os) {
		System.err.printf("#%d: %s%n", id, deepToString(os));
	}
	
	public static void main(String[] args) {
		System.setOut(null);
		String input;
		if (args.length == 0) {
			input = A.class.getName() + ".in";
			PARALLEL = 1;
		} else {
			input = args[0];
			if (args.length >= 2) ID = Integer.parseInt(args[1]);
		}
		System.err.printf("Input = %s%n", input);
		final A[] solvers;
		final StringWriter[] outs;
		try (Scanner sc = new Scanner(new BufferedInputStream(new FileInputStream(input)))) {
			int caseN = sc.nextInt();
			solvers = new A[caseN];
			outs = new StringWriter[caseN];
			for (int i = 0; i < caseN; i++) {
				solvers[i] = new A();
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
						synchronized (A.class) {
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
