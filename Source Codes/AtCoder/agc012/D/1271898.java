import java.util.Arrays;
    import java.util.HashMap;
    import java.util.Iterator;
    import java.util.Map;
    import java.util.Scanner;
     
    class Main {
    	public static void main(String[] args) {
    		new Main().run();
    	}
     
    	final long MODULO = (long) (1e9 + 7);
     
    	void run() {
    		Scanner sc = new Scanner(System.in);
    		int N = sc.nextInt();
    		long X = sc.nextLong();
    		long Y = sc.nextLong();
    		int[] c = new int[N];
    		long[] w = new long[N];
    		long[][] c_min = new long[N][2];
    		for (int i = 0; i < N; ++i) {
    			c_min[i][0] = Long.MAX_VALUE / 16;
    			c_min[i][1] = -1;
    		}
    		for (int i = 0; i < N; ++i) {
    			c[i] = sc.nextInt() - 1;
    			w[i] = sc.nextLong();
    			c_min[c[i]][0] = Math.min(c_min[c[i]][0], w[i]);
    			if (c_min[c[i]][0] == w[i])
    				c_min[c[i]][1] = i;
    		}
    		DJSet ds = new DJSet(N, w);
    		for (int i = 0; i < N; ++i) {
    			if (Math.abs(w[i] + c_min[c[i]][0]) <= X) {
    				ds.setUnion(i, (int) c_min[c[i]][1]);
    			}
    		}
     
    		int v1 = 0;
    		int v2 = 0;
    		int v3 = 0;
    		for (int i = 0; i < N; ++i) {
    			if (ds.w[ds.root(i)] <= ds.w[ds.root(v1)]) {
    				v1 = ds.root(i);
    			}
    		}
    		while (v2 + 1 < N && c[v1] == c[v2])
    			++v2;
    		for (int i = 0; i < N; ++i) {
    			if (ds.w[ds.root(i)] <= ds.w[ds.root(v2)] && c[ds.root(i)] != c[ds.root(v1)]) {
    				v2 = ds.root(i);
    			}
    		}
    		while (v3 + 1 < N && (c[v1] == c[ds.root(v3)] || c[v2] == c[ds.root(v3)]))
    			++v3;
    		v3 = ds.root(v3);
    		for (int i = 0; i < N; ++i) {
    			if (ds.w[ds.root(i)] <= ds.w[v3] && c[ds.root(i)] != c[v2] && c[ds.root(i)] != c[v1]) {
    				v3 = ds.root(i);
    			}
    		}
     
    		boolean[] vis = new boolean[N];
    		for (int i = 0; i < N; ++i) {
    			int rep = ds.root(i);
    			if (vis[rep])
    				continue;
    			if (c[i] != c[v1]) {
    				if (Math.abs(ds.w[rep] + ds.w[v1]) <= Y) {
    					ds.setUnion(rep, v1);
    				}
    			}
    			if (c[i] != c[v2]) {
    				if (Math.abs(ds.w[rep] + ds.w[v2]) <= Y) {
    					ds.setUnion(rep, v2);
    				}
    			}
    			if (c[i] != c[v3]) {
    				if (Math.abs(ds.w[rep] + ds.w[v3]) <= Y) {
    					ds.setUnion(rep, v3);
    				}
    			}
    			vis[rep] = true;
    		}
     
    		long[] fac = new long[N + 1];
    		long[] invfac = new long[N + 1];
    		long[] inv = new long[N + 1];
    		inv[1] = 1;
    		fac[0] = 1;
    		invfac[0] = 1;
    		for (int i = 1; i < fac.length; ++i) {
    			fac[i] = (fac[i - 1] * i) % MODULO;
    		}
    		for (int i = 2; i < inv.length; ++i) {
    			inv[i] = (MODULO - inv[(int) (MODULO % i)] * (MODULO / i) % MODULO) % MODULO;
    		}
    		for (int i = 1; i < invfac.length; ++i) {
    			invfac[i] = (invfac[i - 1] * inv[i]) % MODULO;
    		}
     
    		HashMap<Integer, Integer>[] mp = new HashMap[N];
    		for (int i = 0; i < mp.length; ++i) {
    			mp[i] = new HashMap<>();
    		}
    		for (int i = 0; i < N; ++i) {
    			int rep = ds.root(i);
    			if (!mp[rep].containsKey(c[i])) {
    				mp[rep].put(c[i], 1);
    			} else {
    				mp[rep].put(c[i], mp[rep].get(c[i]) + 1);
    			}
    		}
     
    		long ans = 1;
    		Arrays.fill(vis, false);
    		for (int i = 0; i < N; ++i) {
    			int rep = ds.root(i);
    			if (vis[rep])
    				continue;
    			ans = (ans * fac[ds.size(rep)]) % MODULO;
    			for (Map.Entry<Integer, Integer> e : mp[rep].entrySet()) {
    				ans = (ans * invfac[e.getValue()]) % MODULO;
    			}
    			vis[rep] = true;
    		}
    		System.out.println(ans);
    	}
     
    	class DJSet {
    		int n;
    		int[] upper;
    		long[] w;
     
    		public DJSet(int n, long[] w) {
    			this.n = n;
    			upper = new int[n];
    			Arrays.fill(upper, -1);
    			this.w = w;
    		}
     
    		boolean equiv(int x, int y) {
    			return root(x) == root(y);
    		}
     
    		int root(int x) {
    			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
    		}
     
    		void setUnion(int x, int y) {
    			x = root(x);
    			y = root(y);
    			long tmpW = Math.min(w[x], w[y]);
    			if (x == y)
    				return;
    			if (upper[x] < upper[y]) {
    				int tmp = x;
    				x = y;
    				y = tmp;
    			}
    			upper[y] += upper[x];
    			upper[x] = y;
    			w[y] = tmpW;
    		}
     
    		int size(int x) {
    			return -upper[root(x)];
    		}
    	}
     
    	void tr(Object... objects) {
    		System.out.println(Arrays.deepToString(objects));
    	}
    } Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.