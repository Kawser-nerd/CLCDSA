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
		
		char[] s = ns().toCharArray();
		
		int[][] dpr = new int[2][n]; // return flip
		int[][] dpg = new int[2][n]; // go
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			
			int rsum = 0;
			int tog = 0;
			int ming = 0;
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				if(dpr[0][e] > 0){
					rsum += dpr[1][e] + 2;
					tog++;
					
					ming = Math.min(ming, 
							(dpg[1][e] + 1) - (dpr[1][e] + 2)
							);
				}
			}
			
			int[] res = process(rsum, s[cur], tog, ming);
			
			dpr[0][cur] = res[0];
			dpr[1][cur] = res[1];
			dpg[0][cur] = res[2];
			dpg[1][cur] = res[3];
		}
		
		int ans = Integer.MAX_VALUE;
		
		int[][] ddpr = new int[2][n];
		int[][] ddpg = new int[2][n];
		
		for(int i = 0;i < n;i++){
			int cur = ord[i];
//			tr(cur);
//			tr(ddpr[0][cur], ddpr[1][cur]);
//			tr(ddpg[0][cur], ddpg[1][cur]);
			
			int rsum = 0;
			int tog = 0;
			int ming1 = 0;
			int ming2 = 0;
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				if(dpr[0][e] > 0){
					rsum += dpr[1][e] + 2;
					tog++;
					
					int v = (dpg[1][e] + 1) - (dpr[1][e] + 2);
					if(v < ming1){
						ming2 = ming1;
						ming1 = v;
					}else if(v < ming2){
						ming2 = v;
					}
				}
			}
			if(ddpr[0][cur] > 0){
				rsum += ddpr[1][cur] + 2;
				tog++;
				
				int v = (ddpg[1][cur] + 1) - (ddpr[1][cur] + 2);
				if(v < ming1){
					ming2 = ming1;
					ming1 = v;
				}else if(v < ming2){
					ming2 = v;
				}
			}
			
			{
				int[] res = process(rsum, s[cur], tog, ming1);
//				tr(cur, res);
				ans = Math.min(ans, res[2]);
			}
			
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				
				int lrsum = rsum, ltog = tog;
				int lming = ming1;
				
				if(dpr[0][e] > 0){
					lrsum -= (dpr[1][e] + 2);
					ltog -= 1;
					int v = (dpg[1][e] + 1) - (dpr[1][e] + 2);
					lming = ming1 == v ? ming2 : ming1;
				}
				
//				tr(cur, e, lrsum, ltog, lming, s[cur]);
				int[] res = process(lrsum, s[cur], ltog, lming);
				
				ddpr[0][e] = res[0];
				ddpr[1][e] = res[1];
				ddpg[0][e] = res[2];
				ddpg[1][e] = res[3];
			}
		}
		
//		tr(dpr);
//		tr(dpg);
		
		out.println(ans);
	}
	
	static int[] process(int rsum, char c, int tog, int ming)
	{
		if(rsum == 0){
			if(c == 'B'){
				return new int[]{0, 1, 0, 1};
			}else{
				return new int[]{1, 0, 1, 0};
			}
		}else{
			int[] ret= new int[4];
			{
				char t = c;
				if(tog % 2 == 1){
					t = t == 'B' ? 'W' : 'B';
				}
				ret[0] = rsum + (t == 'W' ? 1 : 0);
				ret[1] = rsum + (t == 'W' ? 0 : 1);
			}
			{
				char t = c;
				if(tog % 2 == 0){
					t = t == 'B' ? 'W' : 'B';
				}
				ret[2] = rsum + ming + (t == 'W' ? 1 : 0);
				ret[3] = rsum + ming + (t == 'W' ? 0 : 1);
			}
			return ret;
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