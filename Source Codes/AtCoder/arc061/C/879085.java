import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Queue;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), m = ni();
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1, ni()};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		RestorableDisjointSet2 rds = new RestorableDisjointSet2(n, m);
		int[] cen = new int[n];
		Arrays.fill(cen, -1);
		int id = n;
		int[] from = new int[2*m];
		int[] to = new int[2*m];
		int ep = 0;
		for(int i = 0;i < m;){
			int j = i;
			while(j < m && es[j][2] == es[i][2])j++;
			for(int k = i;k < j;k++){
				rds.union(es[k][0], es[k][1]);
			}
			for(int k = i;k < j;k++){
				for(int u = 0;u < 2;u++){
					int root = rds.root(es[k][u]);
					if(cen[root] == -1){
						cen[root] = id;
						id++;
					}
					from[ep] = es[k][u];
					to[ep] = cen[root];
					ep++;
				}
			}
			for(int k = i;k < j;k++){
				for(int u = 0;u < 2;u++){
					int root = rds.root(es[k][u]);
					cen[root] = -1;
				}
			}
			rds.revert(0);
			
			i = j;
		}
		
		int[][] g = packU(id, from, to, ep);
		Queue<Integer> q = new ArrayDeque<>();
		q.add(0);
		int[] d = new int[id];
		int I = 99999999;
		Arrays.fill(d, I);
		d[0] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] == I){
					d[e] = d[cur] + 1;
					q.add(e);
				}
			}
		}
		if(d[n-1] == I){
			out.println(-1);
		}else{
			out.println(d[n-1]/2);
		}
	}
	
	
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

	
	public static class RestorableDisjointSet2 {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		public long[] hist;
		private final int offset = 1000000000;
		public int hp = 0;
		
		public RestorableDisjointSet2(int n, int m)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
//				w = new int[n];
			hist = new long[2*m];
		}
		
		public RestorableDisjointSet2(RestorableDisjointSet2 ds)
		{
			this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
			this.hist = Arrays.copyOf(ds.hist, ds.hist.length);
			this.hp = ds.hp;
		}
		
		private void rec(int x)
		{
			hist[hp++] = (long)x<<32|upper[x]+offset;
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : root(upper[x]);
//				if(upper[x] < 0){
//					return x;
//				}else{
//					rec(x);
//					return upper[x] = root(upper[x]);
//				}
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public boolean union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
//					w[x] += w[y];
				rec(x);
				upper[x] += upper[y];
				rec(y);
				upper[y] = x;
			}
			return x == y;
		}
		
		public int time() { return hp; }
		
		public void revert(int to)
		{
			while(hp > to){
				upper[(int)(hist[hp-1]>>>32)] = ((int)hist[hp-1])-offset;
				hp--;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int u : upper){
				if(u < 0)ct++;
			}
			return ct;
		}
		
		public int[][] makeUp()
		{
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for(int i = 0;i < n;i++){
				if(upper[i] < 0)ret[i] = new int[-upper[i]];
			}
			for(int i = 0;i < n;i++){
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
		}

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