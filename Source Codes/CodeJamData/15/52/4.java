import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	
	PrintWriter out;
	Random rand = new Random(42341);
	
	int N, K;
	int[] sum;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		K = sc.nextInt();
		sum = new int[N - K + 2];
		for (int i = 1; i < sum.length; i++) sum[i] = sc.nextInt();
	}
	
	long[] sum2;
	long[] min, max;
	
	void solve() {
		sum2 = new long[N + 1];
		for (int i = K; i <= N; i++) {
			sum2[i] = sum2[i - K] + sum[i - K + 1] - sum[i - K];
		}
		min = new long[K];
		max = new long[K];
		min[0] = max[0] = sum[1];
		for (int i = K; i <= N; i++) {
			min[i % K] = min(min[i % K], sum2[i]);
			max[i % K] = max(max[i % K], sum2[i]);
		}
		long res = Long.MAX_VALUE;
		for (int rep = 0; rep <= 10000000; rep++) {
			long minV = min[0], maxV = max[0];
			for (int i = 0; i < K; i++) {
				minV = min(minV, min[i]);
				maxV = max(maxV, max[i]);
			}
			res = min(res, maxV - minV);
			if (rand.nextBoolean()) {
				int num = 0;
				for (int i = 0; i < K; i++) if (minV == min[i]) num++;
				num = rand.nextInt(num);
				int up = -1;
				for (int i = 0; i < K; i++) if (minV == min[i] && num-- == 0) up = i;
				num = 0;
				for (int i = 0; i < K; i++) if (minV + 1 < min[i]) num++;
				if (num == 0) continue;
				num = rand.nextInt(num);
				int down = -1;
				for (int i = 0; i < K; i++) if (minV + 1 < min[i] && num-- == 0) down = i;
				min[up]++;
				max[up]++;
				min[down]--;
				max[down]--;
			} else {
				int num = 0;
				for (int i = 0; i < K; i++) if (maxV == max[i]) num++;
				num = rand.nextInt(num);
				int down = -1;
				for (int i = 0; i < K; i++) if (maxV == max[i] && num-- == 0) down = i;
				num = 0;
				for (int i = 0; i < K; i++) if (maxV - 1 > max[i]) num++;
				if (num == 0) continue;
				num = rand.nextInt(num);
				int up = -1;
				for (int i = 0; i < K; i++) if (maxV - 1 > max[i] && num-- == 0) up = i;
				min[up]++;
				max[up]++;
				min[down]--;
				max[down]--;
			}
		}
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
