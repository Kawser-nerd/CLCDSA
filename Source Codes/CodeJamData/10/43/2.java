import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	static boolean SAMPLE;
	Scanner sc;
	
	void solve() {
		int R = sc.nextInt();
		int[] x1 = new int[R], y1 = new int[R];
		int[] x2 = new int[R], y2 = new int[R];
		int[] maxX = new int[R], maxY = new int[R];
		for (int i = 0; i < R; i++) {
			x1[i] = sc.nextInt();
			y1[i] = sc.nextInt();
			x2[i] = sc.nextInt();
			y2[i] = sc.nextInt();
			maxX[i] = x2[i];
			maxY[i] = y2[i];
		}
		UnionFind uf = new UnionFind(R);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < i; j++) {
				if (max(x1[i], x1[j]) <= min(x2[i], x2[j])) {
					if (max(y1[i], y1[j]) <= min(y2[i], y2[j]) + 1) {
						uf.union(i, j);
					}
				} else if (max(y1[i], y1[j]) <= min(y2[i], y2[j])) {
					if (max(x1[i], x1[j]) <= min(x2[i], x2[j]) + 1) {
						uf.union(i, j);
					}
				} else if (x2[i] + 1 == x1[j] && y1[i] == y2[j] + 1) {
					uf.union(i, j);
				} else if (x2[j] + 1 == x1[i] && y1[j] == y2[i] + 1) {
					uf.union(i, j);
				}
			}
		}
		for (int i = 0; i < R; i++) {
			int j = uf.find(i);
			maxX[j] = max(maxX[j], x2[i]);
			maxY[j] = max(maxY[j], y2[i]);
		}
		int res = 0;
		for (int i = 0; i < R; i++) {
			int j = uf.find(i);
			res = max(res, maxX[j] - x1[i] + maxY[j] - y1[i] + 1);
		}
		System.out.println(res);
	}
	
	class UnionFind {
		int[] ps, num;
		UnionFind(int size) {
			ps = new int[size];
			num = new int[size];
			for (int i = 0; i < size; i++) {
				ps[i] = i;
				num[i] = 1;
			}
		}
		void union(int x, int y) {
			x = find(x); y = find(y);
			if (x == y) return;
			if (num[x] < num[y]) {
				int t = x; x = y; y = t;
			}
			ps[y] = x;
			num[x] += num[y];
		}
		int find(int x) {
			if (x != ps[x]) ps[x] = find(ps[x]);
			return ps[x];
		}
		boolean same(int x, int y) {
			return find(x) == find(y);
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
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream(C.class.getName() + ".in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new C().run();
	}
}
