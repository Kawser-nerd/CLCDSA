import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int N;
	boolean[][] g;
	
	void read() {
		N = sc.nextInt();
		g = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String s = sc.next();
			for (int j = 0; j < N; j++) g[i][j] = s.charAt(j) == '1';
		}
	}
	
	int n;
	int[] A, B, C;
	
	int INF = 1 << 29;
	
	TreeMap<Array, Integer> dp;
	
	int rec(int[] C) {
		Array e = new Array(C);
		if (dp.containsKey(e)) return dp.get(e);
		int a = C[n], b = C[n + 1], i = C[n + 2];
		if (a == 0 && b == 0) {
			while (i < n && C[i] == 0) i++;
			int res;
			if (i == n) res = 0;
			else {
				int[] C2 = C.clone();
				C2[i]--;
				C2[n] = A[i];
				C2[n + 1] = B[i];
				C2[n + 2] = i;
				res = rec(C2);
			}
			dp.put(e, res);
			return res;
		} else if (a == b) {
			int[] C2 = C.clone();
			C2[n] = C2[n + 1] = C2[n + 2] = 0;
			int res = a * b + rec(C2);
			dp.put(e, res);
			return res;
		} else if (i == n) {
			return INF;
		} else {
			int res = INF;
			if (C[i] > 0) {
				int[] C2 = C.clone();
				C2[i]--;
				C2[n] += A[i];
				C2[n + 1] += B[i];
				res = rec(C2);
			}
			int[] C2 = C.clone();
			C2[n + 2]++;
			res = min(res, rec(C2));
			dp.put(e, res);
			return res;
		}
	}
	
	void solve() {
		int M = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (g[i][j]) M++;
		UnionFind uf = new UnionFind(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) if (g[i][k] && g[j][k]) uf.union(i, j);
			}
		}
		int[][] count = new int[N + 1][N + 1];
		for (int i = 0; i < N; i++) if (uf.ps[i] == i) {
			int a = 0;
			for (int j = 0; j < N; j++) if (uf.same(i, j)) {
				a++;
				for (int k = 0; k < N; k++) if (g[j][k]) {
					g[i][k] = true;
				}
			}
			int b = 0;
			for (int k = 0; k < N; k++) if (g[i][k]) b++;
			count[a][b]++;
		}
		for (int i = 0; i < N; i++) {
			boolean ok = true;
			for (int j = 0; j < N; j++) if (g[j][i]) ok = false;
			if (ok) count[0][1]++;
		}
		A = new int[N * 2];
		B = new int[N * 2];
		C = new int[N * 2];
		n = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) if (count[i][j] > 0) {
				A[n] = i;
				B[n] = j;
				C[n++] = count[i][j];
			}
		}
		dp = new TreeMap<D.Array, Integer>();
		C = copyOf(C, n + 3);
		System.out.println(rec(C) - M);
	}
	
	class Array implements Comparable<Array> {
		int[] is;
		Array(int...is) {
			this.is = is;
		}
		public int compareTo(Array o) {
			for (int i = 0; i < is.length && i < o.is.length; i++) {
				if (is[i] != o.is[i]) return is[i] - o.is[i];
			}
			return is.length - o.is.length;
		}
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
