import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N, M;
	String[] codes;
	boolean[][] g;
	
	void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		codes = new String[N];
		for (int i = 0; i < N; i++) codes[i] = sc.next();
		g = new boolean[N][N];
		for (int i = 0; i < M; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			g[u][v] = g[v][u] = true;
		}
	}
	
	boolean ok(int[] used) {
		Queue<Integer> que = new LinkedList<>();
		for (int i = 0; i < N; i++) if (used[i] == 1) {
			que.offer(i);
			used[i] = 2;
		}
		while (!que.isEmpty()) {
			int v = que.poll();
			for (int u = 0; u < N; u++) if (g[v][u] && used[u] == 0) {
				used[u] = 2;
				que.offer(u);
			}
		}
		for (int i = 0; i < N; i++) if (used[i] != 2) return false;
		return true;
	}
	
	void solve() {
		int r = 0;
		for (int i = 0; i < N; i++) if (codes[r].compareTo(codes[i]) > 0) r = i;
		int[] used = new int[N];
		StringBuilder res = new StringBuilder();
		res.append(codes[r]);
		int[] list = new int[N];
		int n = 0;
		list[n++] = r;
		used[r] = 1;
		for (int k = 1; k < N; k++) {
			int p = 0, q = -1;
			for (int i = 0; i < n; i++) {
				for (int v = 0; v < N; v++) if (used[v] == 0 && g[list[i]][v]) {
					if (q < 0 || codes[q].compareTo(codes[v]) >= 0) {
						int[] used2 = used.clone();
						for (int j = i + 1; j < n; j++) used2[list[j]] = 2;
						used2[v] = 1;
						if (ok(used2)) {
							p = i;
							q = v;
						}
					}
				}
			}
			res.append(codes[q]);
			for (int i = p + 1; i < n; i++) used[list[i]] = 2;
			list[p + 1] = q;
			used[q] = 1;
			n = p + 2;
		}
		System.out.println(res);
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
