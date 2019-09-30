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
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[][] ig = packD(n, to, from);
		int[] color = color3(g, ig);
		
		boolean[] dead = new boolean[n];
		boolean[] tri = new boolean[n];
		for(int i = 0;i < n;i++){
			int nex = color[i] + 1;
			if(nex >= 3)nex -= 3;
			for(int e : g[i]){
				if(color[e] != nex){
					dead[i] = true;
				}
			}
			nex = color[i] - 1;
			if(nex < 0)nex += 3;
			for(int e : ig[i]){
				if(color[e] != nex){
					dead[i] = true;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				if(g[e].length > 0)tri[i] = true;
			}
		}
		
		DJSet ds = new DJSet(n);
		ds.dead = dead;
		ds.tri = tri;
		for(int i = 0;i < m;i++){
			ds.union(from[i], to[i]);
		}
		long ret = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				if(ds.dead[i]){
					long sz = -ds.upper[i];
					ret += sz*sz;
				}
			}
		}
		for(int i = 0;i < m;i++){
			if(ds.dead[ds.root(from[i])])continue;
			if(!ds.tri[ds.root(from[i])])ret++;
		}
		
		int[][] cts = new int[3][n];
		for(int i = 0;i < n;i++){
			if(!ds.dead[ds.root(i)] && ds.tri[ds.root(i)]){
				cts[color[i]][ds.root(i)]++;
			}
		}
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0 && ds.tri[i]){
				ret += (long)cts[0][i]*cts[1][i];
				ret += (long)cts[1][i]*cts[2][i];
				ret += (long)cts[2][i]*cts[0][i];
			}
		}
		out.println(ret);
	}
	
	
	static int[] color3(int[][] g, int[][] ig)
	{
		int n = g.length;
		int[] color = new int[n];
		Arrays.fill(color, -1);
		for(int i = 0;i < n;i++){
			if(color[i] != -1)continue;
			Queue<Integer> q = new ArrayDeque<>();
			q.add(i);
			color[i] = 0;
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int e : g[cur]){
					if(color[e] == -1){
						color[e] = (color[cur] + 1) % 3;
						q.add(e);
					}
				}
				for(int e : ig[cur]){
					if(color[e] == -1){
						color[e] = (color[cur] + 2) % 3;
						q.add(e);
					}
				}
			}
		}
		return color;
	}
	
	public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	
	public static class DJSet {
		public int[] upper;
		public boolean[] dead;
		public boolean[] tri;

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
				dead[x] |= dead[y];
				tri[x] |= tri[y];
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

	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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