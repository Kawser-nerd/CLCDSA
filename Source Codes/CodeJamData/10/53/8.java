import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	static boolean SAMPLE;
	Scanner sc;
	
	void solve(int caseID) {
		int n = sc.nextInt();
		TreeMap<Long, Long> map = new TreeMap<Long, Long>();
		Queue<Long> que = new LinkedList<Long>();
		for (int i = 0; i < n; i++) {
			long x = sc.nextLong();
			map.put(x, sc.nextLong());
			que.offer(x);
		}
		long res = 0;
		while (!que.isEmpty()) {
			long x = que.poll(), m = map.get(x);
			if (m > 1) {
				map.put(x, m % 2);
				add(map, x - 1, m / 2);
				add(map, x + 1, m / 2);
				res += m / 2;
				que.offer(x - 1);
				que.offer(x + 1);
			}
		}
		System.out.println(res);
	}
	
	void add(TreeMap<Long, Long> map, long x, long v) {
		if (map.containsKey(x)) map.put(x, map.get(x) + v);
		else map.put(x, v);
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
				System.setIn(new FileInputStream("C.in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new C().run();
	}
}
