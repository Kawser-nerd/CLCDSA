import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N, M;
	int[][] ps;
	int[] U, V;
	
	void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		U = new int[M];
		V = new int[M];
		for (int i = 0; i < M; i++) {
			U[i] = sc.nextInt() - 1;
		}
		for (int i = 0; i < M; i++) {
			V[i] = sc.nextInt() - 1;
		}
	}
	
	class V extends ArrayList<V> {
		int id;
		boolean used;
		V(int id) {
			this.id = id;
		}
	}
	
	int[] toi(Integer[] Is) {
		int n = Is.length;
		int[] is = new int[n];
		for (int i = 0; i < n; i++) is[i] = Is[i];
		return is;
	}
	
	void solve() {
		ps = new int[M + 1][];
		ps[0] = new int[N];
		for (int i = 0; i < N; i++) ps[0][i] = i;
		for (int i = 0; i < M; i++) {
			if (U[i] > V[i]) {
				int t = U[i]; U[i] = V[i]; V[i] = t;
			}
			for (int j = 0; j <= i; j++) {
				int num = 0;
				for (int k = 0; k < ps[j].length; k++) if (ps[j][k] == U[i] || ps[j][k] == V[i]) num++;
				if (num == 2) {
					ArrayList<Integer> a = new ArrayList<Integer>(), b = new ArrayList<Integer>();
					for (int k = 0; k < ps[j].length; k++) {
						if (ps[j][k] <= U[i] || V[i] <= ps[j][k]) a.add(ps[j][k]);
						if (U[i] <= ps[j][k] && ps[j][k] <= V[i]) b.add(ps[j][k]);
					}
					ps[j] = toi(a.toArray(new Integer[0]));
					ps[i + 1] = toi(b.toArray(new Integer[0]));
					break;
				}
			}
		}
		V[] vs = new V[M + 1];
		for (int i = 0; i <= M; i++) vs[i] = new V(i);
		int min = N;
		for (int i = 0; i <= M; i++) {
			min = min(min, ps[i].length);
			for (int j = 0; j < i; j++) {
				int num = 0;
				for (int a = 0, b = 0; a < ps[i].length && b < ps[j].length; ) {
					if (ps[i][a] == ps[j][b]) {
						num++;
						a++;
						b++;
					} else if (ps[i][a] < ps[j][b]) {
						a++;
					} else {
						b++;
					}
				}
				if (num > 2) throw null;
				if (num == 2) {
					vs[i].add(vs[j]);
					vs[j].add(vs[i]);
				}
			}
		}
		int[] res = new int[N];
		fill(res, -1);
		Queue<V> que = new LinkedList<V>();
		que.offer(vs[0]);
		vs[0].used = true;
		while (!que.isEmpty()) {
			V v = que.poll();
			int m = ps[v.id].length;
			int s = 0;
			boolean[] used = new boolean[min];
			for (int i = 0; i < m; i++) if (res[ps[v.id][i]] >= 0) {
				s = i;
				used[res[ps[v.id][i]]] = true;
			}
			for (int i = 0; i < m; i++) if (res[ps[v.id][(s + i) % m]] < 0) {
				int prev = res[ps[v.id][(s + i + m - 1) % m]];
				int next = res[ps[v.id][(s + i + 1) % m]];
				int x = prev + 1;
				while (used[x % min]) x++;
				while (x % min == prev || x % min == next) x++;
				res[ps[v.id][(s + i) % m]] = x % min;
			}
			for (V u : v) if (!u.used) {
				u.used = true;
				que.offer(u);
			}
		}
		for (int i = 0; i <= M; i++) {
			boolean[] used = new boolean[min];
			for (int j = 0; j < ps[i].length; j++) used[res[ps[i][j]]] = true;
			for (int j = 0; j < min; j++) if (!used[j]) {
				throw null;
			}
		}
		System.out.println(min);
		for (int i = 0; i < N; i++) {
			if (i > 0) System.out.print(" ");
			System.out.print(res[i] + 1);
		}
		System.out.println();
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
