import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	long MOD = 1000002013;
	
	int N, M;
	int[] from, to, num;
	
	void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		from = new int[M];
		to = new int[M];
		num = new int[M];
		for (int i = 0; i < M; i++) {
			from[i] = sc.nextInt() - 1;
			to[i] = sc.nextInt() - 1;
			num[i] = sc.nextInt();
		}
	}
	
	void solve() {
		TreeMap<Integer, Long> in = new TreeMap<Integer, Long>();
		long cost = 0;
		for (int i = 0; i < M; i++) {
			Long v = in.get(from[i]);
			if (v == null) v = 0L;
			in.put(from[i], v + num[i]);
			v = in.get(to[i]);
			if (v == null) v = 0L;
			in.put(to[i], v - num[i]);
			long d = to[i] - from[i];
			cost += (N * d + (d - d * d) / 2) % MOD * num[i];
			cost %= MOD;
			if (cost < 0) cost += M;
		}
		Map<Integer, Long> count = new TreeMap<Integer, Long>();
		int prev = 0;
		for (Map.Entry<Integer, Long> e : in.entrySet()) {
			long d = e.getKey() - prev;
			long c = e.getValue();
			Map<Integer, Long> count2 = new TreeMap<Integer, Long>();
			if (c > 0) {
				count2.put(0, c);
			}
			for (Map.Entry<Integer, Long> e2 : count.entrySet()) {
				int j = e2.getKey();
				cost -= ((N * d - d * j) + (d - d * d) / 2) % MOD * (e2.getValue() % MOD);
				cost %= MOD;
				if (cost < 0) cost += MOD;
				if (c < 0) {
					long v = min(-c, e2.getValue());
					c += v;
					if (e2.getValue() - v > 0) {
						count2.put(e2.getKey() + (int)d, e2.getValue() - v);
					}
				} else {
					count2.put(e2.getKey() + (int)d, e2.getValue());
				}
			}
			count = count2;
			prev = e.getKey();
		}
		System.out.println(cost % MOD);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
