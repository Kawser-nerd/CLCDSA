import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	static boolean SAMPLE;
	Scanner sc;
	
	int M = 200010;
	long INF = 1L << 60;
	
	void solve(int caseID) {
		long L = sc.nextLong();
		int N = sc.nextInt();
		int[] is = new int[N];
		for (int i = 0; i < N; i++) is[i] = sc.nextInt();
		sort(is);
		long[] min = new long[M];
		PriorityQueue<Entry> que = new PriorityQueue<Entry>();
		fill(min, INF);
		for (int j = 0; j < M; j++) if ((L - j) % is[N - 1] == 0) {
			min[j] = (L - j) / is[N - 1];
			que.offer(new Entry(j, (L - j) / is[N - 1]));
		}
		while (!que.isEmpty()) {
			Entry e = que.poll();
			if (min[e.i] < e.t) continue;
			for (int i = 0; i < N - 1; i++) {
				int d = is[i], f = is[N - 1] - is[i];
				if (e.i - d >= 0 && min[e.i - d] > min[e.i] + 1) {
					min[e.i - d] = min[e.i] + 1;
					que.offer(new Entry(e.i - d, min[e.i - d]));
				}
				if (e.i + f < M && min[e.i + f] > min[e.i]) {
					min[e.i + f] = min[e.i];
					que.offer(new Entry(e.i + f, min[e.i]));
				}
			}
		}
		if (min[0] == INF) System.out.println("IMPOSSIBLE");
		else System.out.println(min[0]);
	}
	
	class Entry implements Comparable<Entry> {
		int i;
		long t;
		Entry(int i, long t) {
			this.i = i;
			this.t = t;
		}
		public int compareTo(Entry o) {
			return Long.signum(t - o.t);
		}
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (!SAMPLE) System.err.printf("%03d/%03d %.3f/%.3f%n", caseID, caseN, t, t / (caseID - 1) * caseN);
			System.out.printf("Case #%d: ", caseID);
			solve(caseID);
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream("B.in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new B().run();
	}
}
