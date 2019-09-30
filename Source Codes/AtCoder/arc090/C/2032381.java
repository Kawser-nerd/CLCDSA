import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;


public class Main {

	private static void solve() {
		int n = ni();
		int m = ni();
		int s = ni() - 1;
		int t = ni() - 1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for (int i = 0; i < m; i ++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		long[][] l1 = dijkl(g, s);
		long[][] l2 = dijkl(g, t);
		
		long len = l1[0][t];
		
		{

			long ret = 0;
			Set<Integer> mid = new HashSet<>();
			for (int i = 0; i < n; i ++) {
				for (int[] v : g[i]) {
					int j = v[0];
					long l = v[1];
					if (l1[0][i] + l2[0][j] + l == len) {
						if (l1[0][i] * 2 < len && l1[0][j] * 2 > len) {
							long x = l1[1][i] * l2[1][j];
							x %= mod;
							x = x * x;
							x %= mod;
							ret += x;
							ret %= mod;
						}
						if (l1[0][i] * 2 == len) {
							mid.add(i);
						}
					}
				}
			}

			for (int v : mid) {
				long x = l1[1][v] * l2[1][v];
				x %= mod;
				x = (x * x) % mod;
				ret += x;
				ret %= mod;
			}
			long all = l1[1][t] * l2[1][s];
			all %= mod;
			long ans = (all - ret + mod) % mod;
			System.out.println(ans);
		}
	}

	static int mod = 1000000000 + 7;
	public static long[][] dijkl(int[][][] g, int from)
	{
		int n = g.length;
		long[] td = new long[n];
		long[] num = new long[n];
		num[from] = 1;
		
		Arrays.fill(td, Long.MAX_VALUE / 2);
		MinHeapL q = new MinHeapL(n);
		q.add(from, 0);
		td[from] = 0;
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			
			for(int[] e : g[cur]){
				int next = e[0];
				long nd = td[cur] + e[1];
				if(nd < td[next]){
					td[next] = nd;
					q.update(next, nd);
					num[next] = num[cur];
				} else if (nd == td[next]) {
					num[next] += num[cur];
					num[next] %= mod;
				}
			}
		}
		
		return new long[][] {td, num};
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w){ return packWU(n, from, to, w, from.length); }
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	
	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			@Override
			public void run() {
				long start = System.currentTimeMillis();
				String debug = args.length > 0 ? args[0] : null;
				if (debug != null) {
					try {
						is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
					} catch (Exception e) {
						throw new RuntimeException(e);
					}
				}
				reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
				solve();
				out.flush();
				tr((System.currentTimeMillis() - start) + "ms");
			}
		}, "", 64000000).start();
	}

	private static java.io.InputStream is = System.in;
	private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
	private static java.util.StringTokenizer tokenizer = null;
	private static java.io.BufferedReader reader;

	public static String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new java.util.StringTokenizer(reader.readLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	private static double nd() {
		return Double.parseDouble(next());
	}

	private static long nl() {
		return Long.parseLong(next());
	}

	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static char[] ns() {
		return next().toCharArray();
	}

	private static long[] nal(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}

	private static int[][] ntable(int n, int m) {
		int[][] table = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[i][j] = ni();
			}
		}
		return table;
	}

	private static int[][] nlist(int n, int m) {
		int[][] table = new int[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[j][i] = ni();
			}
		}
		return table;
	}

	private static int ni() {
		return Integer.parseInt(next());
	}

	private static void tr(Object... o) {
		if (is != System.in)
			System.out.println(java.util.Arrays.deepToString(o));
	}
}

class MinHeapL {
	public long[] a;
	public int[] map;
	public int[] imap;
	public int n;
	public int pos;
	public static long INF = Long.MAX_VALUE;
	
	public MinHeapL(int m)
	{
		n = Integer.highestOneBit((m+1)<<1);
		a = new long[n];
		map = new int[n];
		imap = new int[n];
		Arrays.fill(a, INF);
		Arrays.fill(map, -1);
		Arrays.fill(imap, -1);
		pos = 1;
	}
	
	public long add(int ind, long x)
	{
		int ret = imap[ind];
		if(imap[ind] < 0){
			a[pos] = x; map[pos] = ind; imap[ind] = pos;
			pos++;
			up(pos-1);
		}
		return ret != -1 ? a[ret] : x;
	}
	
	public long update(int ind, long x)
	{
		int ret = imap[ind];
		if(imap[ind] < 0){
			a[pos] = x; map[pos] = ind; imap[ind] = pos;
			pos++;
			up(pos-1);
		}else{
			a[ret] = x;
			up(ret);
			down(ret);
		}
		return x;
	}
	
	public long remove(int ind)
	{
		if(pos == 1)return INF;
		if(imap[ind] == -1)return INF;
		
		pos--;
		int rem = imap[ind];
		long ret = a[rem];
		map[rem] = map[pos];
		imap[map[pos]] = rem;
		imap[ind] = -1;
		a[rem] = a[pos];
		a[pos] = INF;
		map[pos] = -1;
		
		up(rem);
		down(rem);
		return ret;
	}
	
	public long min() { return a[1]; }
	public int argmin() { return map[1]; }
	public int size() {	return pos-1; }
	
	private void up(int cur)
	{
		for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
			long d = a[p]; a[p] = a[c]; a[c] = d;
			int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
			e = map[p]; map[p] = map[c]; map[c] = e;
		}
	}
	
	private void down(int cur)
	{
		for(int c = cur;2*c < pos;){
			int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
			if(a[b] < a[c]){
				long d = a[c]; a[c] = a[b]; a[b] = d;
				int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
				e = map[c]; map[c] = map[b]; map[b] = e;
				c = b;
			}else{
				break;
			}
		}
	}
}