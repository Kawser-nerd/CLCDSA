import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	boolean TIME = true;
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt();
		int[] xs = new int[n], ys = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = sc.nextInt();
			ys[i] = sc.nextInt();
		}
		pairSort(xs, ys);
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ys[i] == ys[j]) {
					g[i][j] = true;
					g[j][i] = true;
					break;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (ys[i] + 1 == ys[j]) {
					g[i][j] = true;
					g[j][i] = true;
					break;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (ys[i] - 1 == ys[j]) {
					g[i][j] = true;
					g[j][i] = true;
					break;
				}
			}
		}
		System.out.println(coloring(g));
	}
	
	boolean[][] g;
	int[] res, id;
	int s, t, min;
	int coloring(boolean[][] g) {
		this.g = g;
		int n = g.length;
		res = new int[n];
		id = new int[n + 1];//元のインデックス(n番は番兵)
		int[] b = new int[n + 1];//連結度
		for (int i = 0; i <= n; i++) id[i] = i;
		int ans = 1;
		for (s = 0, t = 1; t <= n; t++) {//MA順序でソート
			int p = t;//最大連結度の点
			for (int i = t; i < n; i++) {
				if (g[id[t - 1]][id[i]]) b[id[i]]++;
				if (b[id[p]] < b[id[i]]) p = i;
			}
			swap(id, t, p);
			if (b[id[t]] == 0) {//連結度0なので[s,t)が連結成分
				min = 4;
				dfs(new int[n], s, 0);
				s = t;
				ans = max(ans, min);
			}
		}
//		for (int i = 0; i < n; i++) ans = max(ans, res[i] + 1);
		return ans;
	}
	void dfs(int[] is, int p, int k) {//is:現在の塗り方,p:次塗る点,k:使った色の数
		if (k >= min) return;
		if (p == t) {
			for (int i = s; i < t; i++) res[id[i]] = is[i];
			min = k;
		} else {
			boolean[] used = new boolean[k + 1];
			for (int i = 0; i < p; i++) if (g[id[p]][id[i]]) used[is[i]] = true;
			for (int i = 0; i <= k; i++) if (!used[i]) {//今までに使った色+1まで調べる
				int[] js = is.clone();
				js[p] = i;
				dfs(js, p + 1, max(k, i + 1));
			}
		}
	}
	void swap(int[] is, int i, int j) {
		int t = is[i]; is[i] = is[j]; is[j] = t;
	}
	
	void pairSort(int[] ks, int[] vs) {
		int n = ks.length;
		long[] ls = new long[n];
		for (int i = 0; i < n; i++) {
			ls[i] = ((long)ks[i] << 32) | vs[i];
		}
		sort(ls);
		for (int i = 0; i < n; i++) {
			ks[i] = (int)(ls[i] >> 32);
			vs[i] = (int)ls[i];
		}
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
