import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		boolean[] valid = new boolean[n];
		for(int i = 0;i < n;i++){
			int h = 0;
			for(int e : g[i]){
				if(g[e].length > 1)h++;
			}
			if(h > 2){
				out.println(-1);
				return;
			}
			if(g[i].length >= 2)valid[i] = true;
		}
		
		DJSet ds = new DJSet(n);
		for(int i = 0;i < n;i++){
			if(valid[i]){
				ds.ct[i]++;
			}
		}
		for(int i = 0;i < n;i++){
			if(!valid[i])continue;
			for(int e : g[i]){
				if(valid[e]){
					ds.union(i, e);
				}
			}
		}
		int pos = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				if(ds.ct[i] > 0)pos++;
			}
		}
		if(pos > 1){
			out.println(-1);
			return;
		}
		
		if(pos == 0){
			// star
			if(n <= 3){
				for(int i = 0;i < n;i++){
					out.print((i+1) + " ");
				}
				out.println();
			}else{
				out.print(1 + " ");
				for(int i = 3;i <= n-1;i++){
					out.print(i + " ");
				}
				out.print(2 + " " + n);
				out.println();
			}
			return;
		}
		
		int[] route = new int[n];
		int p = 0;
		route[p++] = 0;
		int min = 999999999;
		int arg = -1;
		for(int i = 0;i < n;i++){
			if(valid[i]){
				int vct = 0;
				for(int e : g[i]){
					if(valid[e]){
						vct++;
					}
				}
				if(vct < min){
					min = vct;
					arg = i;
				}
			}
		}
		assert arg != -1;
		int cur = arg;
		int pre = -1;
		
		inner:
		while(true){
			route[p++] = g[cur].length-2;
			for(int e : g[cur]){
				if(valid[e] && e != pre){
					pre = cur;
					cur = e;
					continue inner;
				}
			}
			break;
		}
		
		route[p++] = 0;
		
		route = Arrays.copyOf(route, p);
		int[] A = make(route);
		
		route = rev(route);
		int[] B = make(route);
		
		for(int i = 0;i < n;i++){
			if(A[i] < B[i]){
				break;
			}else if(A[i] > B[i]){
				A = B;
				break;
			}
		}
		
		for(int i = 0;i < n;i++){
			out.print(A[i] + " ");
		}
		out.println();
		
//		tr(route);
	}
	
	public static int[] rev(int[] a)
	{
		int[] b = new int[a.length];
		for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
		return b;
	}

	
	static int[] make(int[] route)
	{
		int n = route.length;
		int[] ret = new int[200005];
		int p = 0;
		int cur = 1;
		for(int i = 0;i < n;i++){
			int old = cur;
			cur++;
			for(int j = 0;j < route[i];j++){
				ret[p++] = cur++;
			}
			ret[p++] = old;
		}
		return Arrays.copyOf(ret, p);
	}
	
	public static class DJSet {
		public int[] upper;
		public int[] ct;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			ct = new int[n];
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
				ct[x] += ct[y];
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

	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
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