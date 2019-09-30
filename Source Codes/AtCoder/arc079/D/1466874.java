import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++){
			f[i] = f[i]-1;
		}
		int[] from = new int[n];
		int[] to = new int[n];
		for(int i = 0;i < n;i++){
			from[i] = f[i];
			to[i] = i;
		}
		int[][] g = packU(n, from, to);
		int[][] sp = split(g);
		int[] par = sp[0], next = sp[1];
		int[] ord = makeOrder(g, par);
		int[] dp = new int[n];
		long[] ptns = new long[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			dp[cur] = Long.numberOfTrailingZeros(~ptns[cur]);;
			if(par[cur] != -1){
				ptns[par[cur]] |= 1L<<dp[cur];
			}
		}
		int[] cycle = cycle(g, next);
		if(f[cycle[0]] == cycle[1]){
			for(int i = 1, j = cycle.length-1;i < j;i++,j--){
				int d = cycle[i]; cycle[i] = cycle[j]; cycle[j] = d;
			}
		}
		
		for(int j = 0;j < 32;j++){
			if(ptns[cycle[0]]<<~j>=0){
				int cval = j;
				for(int i = 0;i < cycle.length;i++){
					cval = Long.numberOfTrailingZeros(~(ptns[cycle[(i+1)%cycle.length]] | 1L<<cval));
				}
				if(cval == j){
					out.println("POSSIBLE");
					return;
				}
			}
		}
		out.println("IMPOSSIBLE");
	}
	
	public static int[] cycle(int[][] g, int[] next)
	{
		int n = g.length;
		int[] which = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(next[i] != -1){
				int u = i;
				while(true){
					which[p++] = u;
					u = next[u];
					if(u == i)break;
				}
				break;
			}
		}
		return Arrays.copyOf(which, p);
	}
	
	public static int[][] split(int[][] g)
	{
		int n = g.length;
		int[] deg = new int[n];
		int[] par = new int[n];
		Arrays.fill(par, -1);
		for(int i = 0;i < n;i++){
			deg[i] = g[i].length;
		}
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			if(deg[i] == 1){
				q.add(i);
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			deg[cur] = -9999999;
			for(int e : g[cur]){
				deg[e]--;
				if(deg[e] >= 0){
					par[cur] = e;
				}
				if(deg[e] >= 0 && deg[e] <= 1){
					q.add(e);
				}
			}
		}
		boolean[] ved = new boolean[n];
		int[] next = new int[n];
		Arrays.fill(next, -1);
		for(int i = 0;i < n;i++){
			if(!ved[i] && deg[i] == 2){
				ved[i] = true;
				int cur = i;
				outer:
				while(true){
					for(int e : g[cur]){
						if(deg[e] == 2 && !ved[e]){
							next[cur] = e;
							ved[e] = true;
							cur = e;
							continue outer;
						}
					}
					next[cur] = i;
					break;
				}
			}
		}
		
		return new int[][]{par, next};
	}
	
	public static int[] makeOrder(int[][] g, int[] par)
	{
		int n = g.length;
		int[] ord = new int[n];
		int p = 0;
		boolean[] ved = new boolean[n];
		for(int i = 0;i < n;i++){
			if(par[i] == -1){
				ord[p++] = i;
				ved[i] = true;
			}
		}
		for(int r = 0;r < n;r++){
			for(int e : g[ord[r]]){
				if(!ved[e]){
					ved[e] = true;
					ord[p++] = e;
				}
			}
		}
		return ord;
	}

	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static ResultCluster cluster(int[] f)
	{
		int n = f.length;
		DJSet ds = new DJSet(n);
		int[] red = new int[n+1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ds.union(i, f[i]))red[p++] = f[i];
		}
		int[] clus = new int[n]; Arrays.fill(clus, -1);
		int cidgen = 0;
		for(int i = 0;i < n;i++)if(ds.upper[i] < 0)clus[i] = cidgen++;
		for(int i = 0;i < n;i++)clus[i] = clus[ds.root(i)];
		
		int[][] cycles = new int[p][];
		int[] temp = new int[n+1];
		for(int i = 0;i < p;i++){
			temp[0] = red[i];
			int j = 1;
			for(;;j++){
				temp[j] = f[temp[j-1]];
				if(temp[j] == temp[0])break;
			}
			cycles[clus[red[i]]] = Arrays.copyOf(temp, j);
		}
		ResultCluster rc = new ResultCluster();
		rc.clus = clus;
		rc.cycles = cycles;
		return rc;
	}
	
	public static class ResultCluster {
		int[] clus;
		int[][] cycles;
	}

	
	public static void main(String[] args) throws Exception
	{
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}